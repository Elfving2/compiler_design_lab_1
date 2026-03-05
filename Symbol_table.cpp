#include "Symbol_table.h"

Symbol_table::Symbol_table() {
    global_scope = new Scope();
    global_scope->parent = nullptr;
    global_scope->scope_name = new Symbol();
    global_scope->scope_name->identifier = "Global";
    current_scope = global_scope;
}

Scope * Symbol_table::get_global_scope() {
    return this->global_scope;
}

void Symbol_table::traverse(Node* root) {
    if (!root) return;

    if (root->type == "Class") {

        Class_symbol* class_symbol = new Class_symbol();
        class_symbol->identifier = root->value;
        class_symbol->type = root->type;

        current_scope->symbols[root->value] = class_symbol;
        current_scope->ordered_symbols.push_back(class_symbol);
        

        enter_scope(class_symbol);

        for (Node* child : root->children)
            traverse(child);

        leave_scope();
        return;
    }

    if (root->type == "function_def") {

        Method_symbol* method_symbol = new Method_symbol();
        string method_name;

        for (Node* child : root->children) {
            if (child->type == "Identifier") {
                method_name = child->value;
                method_symbol->identifier = child->value;
            }
            else if (child->type == "Return_type") {
                for (const auto& p : child->children)
                    method_symbol->type = p->value;
            }
            else if (child->type == "Parameters") {
                for (const auto& parameter : child->children)
                    for (const auto& p : parameter->children)
                        if (p->type == "Type")
                            method_symbol->parameters.push_back(p->value);
            }
        }

        current_scope->symbols[method_name] = method_symbol;
        current_scope->ordered_symbols.push_back(method_symbol);

        enter_scope(method_symbol);

        for (Node* child : root->children)
            traverse(child);

        leave_scope();
        return;
    }

    execute(root);
    for (Node* child : root->children)
        traverse(child);
}

void Symbol_table::execute(Node* root) {
    if (root->type == "varDecl") {
        Variable_symbol * variable_symbol = new Variable_symbol(); 
        for (Node* child : root->children) {
            if (child->type == "Identifier")
                variable_symbol->identifier = child->value;
            else if (child->type == "Type")
                variable_symbol->type = child->value;
            else if (child->type == "Modifier") {
                variable_symbol->isVolatile = true;
            }
            else if (child->type == "Value") {
                variable_symbol->value = child->value;
            }
        }
        if (current_scope->symbols.find(variable_symbol->identifier) != current_scope->symbols.end()  ) {
            errors.push_back(variable_symbol->identifier + " duplication in scope");
        }
        current_scope->symbols[variable_symbol->identifier] = variable_symbol;
        current_scope->ordered_symbols.push_back(variable_symbol);
    }
    else if (root->type == "Assign") {

        Assign_symbol * assign_symbol = new Assign_symbol();

        //string identifier;
        for (Node* child : root->children) {
            if (child->type == "Identifier") cout << "";
                //assign_symbol->identifier = child->value;
            else if (child->type == "Value") {
                //assign_symbol->value = child->value;
            }
        }

        Symbol* found = lookup(assign_symbol->identifier);

        if (found == nullptr) {
          //  errors.push_back("Variable '" + assign_symbol->identifier + "' not declared in this scope.");
        }
        current_scope->symbols[to_string(rand())] = assign_symbol;
        current_scope->ordered_symbols.push_back(assign_symbol);
    }
}

void Symbol_table::indentation(int indent) {
    for (int i = 0; i < indent; i++) {
        cout << " ";
    }
}

void Symbol_table::print_scope(Scope* scope, int indent)
{

    for (Symbol* symbol : scope->ordered_symbols) {
        indentation(indent);
        if (auto classPtr = dynamic_cast<Class_symbol*>(symbol))
            classPtr->print();
        else if (auto methodPtr = dynamic_cast<Method_symbol*>(symbol))
            methodPtr->print();
        else if (auto varPtr = dynamic_cast<Variable_symbol*>(symbol))
            varPtr->print();
        else if (auto assignPtr = dynamic_cast<Assign_symbol*>(symbol))
            assignPtr->print();

        for (auto* child : scope->children) {
            if (child->scope_name == symbol)
            {
                print_scope(child, indent + 2);
            }
        }
    }
}


void Symbol_table::print() {
    cout << "Global" << endl;
    print_scope(global_scope);
}

void Symbol_table::print_errors() {
    if (errors.size() == 0) return;
    cout << endl;
    int fault = 1;
    for (string error : errors) {
        cout << "ERROR #" << fault++ << "\n" << error << endl;
        
    }
}

void Symbol_table::enter_scope(Symbol * s) {
    Scope* new_scope = new Scope();
    new_scope->parent = current_scope;
    new_scope->scope_name = s;

    current_scope->children.push_back(new_scope);
    current_scope = new_scope;
}

void Symbol_table::leave_scope() {
    if (current_scope->parent != nullptr) {
        current_scope = current_scope->parent;
    }
}

Symbol* Symbol_table::lookup(const string& name) {
    Scope* temp = current_scope;

    while (temp != nullptr) {
        auto it = temp->symbols.find(name);
        if (it != temp->symbols.end()) {
            cout << it->first << endl;
            return it->second;
        }
        temp = temp->parent;
    }
    return nullptr;
}