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

void Symbol_table::execute(Node* root) {
    if (!root) return;

    Symbol* symPtr = nullptr;

    if (root->type == "Class") {
        symPtr = Class_s(symPtr, root);

        current_scope->symbols[symPtr->identifier] = symPtr;
        current_scope->ordered_symbols.push_back(symPtr);

        enter_scope(symPtr);
        for (Node* child : root->children)
            execute(child);
        leave_scope();
        return;
    }

    else if (root->type == "function_def") {
        symPtr = Method_s(symPtr, root);

        current_scope->symbols[symPtr->identifier] = symPtr;
        current_scope->ordered_symbols.push_back(symPtr);

        enter_scope(symPtr);
        for (Node* child : root->children)
            execute(child);
        leave_scope();
        return;
    }

    else if (root->type == "Main") {
        symPtr = Main_s(symPtr, root);

        current_scope->symbols["main"] = symPtr;
        current_scope->ordered_symbols.push_back(symPtr);

        enter_scope(symPtr);
        for (Node* child : root->children)
            execute(child);
        leave_scope();
        return;
    }

    else if (root->type == "If_statement") {
        symPtr = If_s(symPtr, root);

        current_scope->ordered_symbols.push_back(symPtr);

        for (Node* child : root->children) {
            if (child->type == "Block") {
                enter_scope(symPtr);
                execute(child);
                leave_scope();
            }
            else if (child->type == "Else") {
                Symbol* elseSym = nullptr;
                elseSym = Else_s(elseSym, child);

                current_scope->ordered_symbols.push_back(elseSym);

                for (Node* elseChild : child->children) {
                    if (elseChild->type == "Block") {
                        enter_scope(elseSym);
                        execute(elseChild);
                        leave_scope();
                    }
                }
            }
        }
        return;
    }

    else if (root->type == "For_loop") {
        symPtr = For_s(symPtr, root);

        current_scope->ordered_symbols.push_back(symPtr);

        enter_scope(symPtr);
        for (Node* child : root->children) {
            if (child->type == "Block")
                execute(child);
        }
        leave_scope();
        return;
    }

    else if (root->type == "varDecl") {
        symPtr = Variable_s(symPtr, root);
        current_scope->symbols[symPtr->identifier] = symPtr;
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Assign") {
        symPtr = Assign_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Return") {
        symPtr = Return_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Print") {
        symPtr = Print_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Read") {
        symPtr = Read_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Comment") {
        symPtr = Comment_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }

    else if (root->type == "Block" || root->type == "Else") {
        for (Node* child : root->children)
            execute(child);
        return;
    }
    else if (root->type == "Break") {
        symPtr = Break_s(symPtr, root);
        current_scope->ordered_symbols.push_back(symPtr);
        return;
    }
}


Symbol * Symbol_table::Class_s(Symbol * &symPtr, Node * root) {
    symPtr = new Class_symbol();
    Class_symbol* class_s = static_cast<Class_symbol*>(symPtr);
    class_s->identifier = root->value;
    class_s->type = root->type;
    return symPtr;

}


Symbol * Symbol_table::Method_s(Symbol * &symPtr, Node * root) {
    symPtr = new Method_symbol();
    Method_symbol* method = static_cast<Method_symbol*>(symPtr);

    for (Node* child : root->children) {
        if (child->type == "Identifier") {
            method->identifier = child->value;
        }
        else if (child->type == "Return_type") {
            for (const auto& p : child->children)
                method->type = p->value;
        }
        else if (child->type == "Parameters") {
            for (const auto& parameter : child->children)
                for (const auto& p : parameter->children)
                    if (p->type == "Type")
                        method->parameters.push_back(p->value);
        }
    }
    return symPtr;
}


Symbol * Symbol_table::Variable_s(Symbol * &symPtr, Node * root) {
    symPtr = new Variable_symbol();
    Variable_symbol * variable_symbol = static_cast<Variable_symbol*>(symPtr);

    for (Node* child : root->children) {
        if (child->type == "Identifier")
            variable_symbol->identifier = child->value;
        else if (child->type == "Type")
            variable_symbol->type = child->value;
        else if (child->type == "Class")
            variable_symbol->value = child->value + "()";
        else if (child->type == "Modifier") {
            variable_symbol->isVolatile = true;
        }
        else if (child->type == "Value") {
            variable_symbol->value = child->value;
        }
else if (child->type == "Class") {

    bool has_call = false;

    for (Node* c : child->children)
        if (c->type == "function_call")
            has_call = true;

    // Constructor  QS()
    if (!has_call) {
        variable_symbol->value = child->value + "()";
    }

    // Method call  qs.Start(10)
    else {

        for (Node* c : child->children) {

            if (c->type == "function_call") {

                variable_symbol->value = child->value + "." + c->value;

                for (Node* argNode : c->children) {

                    if (argNode->type == "Arguments") {

                        variable_symbol->value += "(";

                        bool first = true;

                        for (Node* arg : argNode->children) {

                            if (!first)
                                variable_symbol->value += ", ";

                            variable_symbol->value += build_expr(arg,0);

                            first = false;
                        }

                        variable_symbol->value += ")";
                        }
                    }
                }
            }
        }
    }
        else if (
            child->type == "Add" ||
            child->type == "Multiply" ||
            child->type == "Minus" ||
            child->type == "Power" 
        )
        variable_symbol->value = build_expr(child, 0);
        else if (child->type == "Array_literal") {
            string temp = variable_symbol->type;
            temp.erase(temp.size() - 1);
            for (Node * c : child->children) {
                if (c->type == "Value") {
                    temp += c->value + ",";
                }
            }
            temp[temp.size() - 1] = ']';
            variable_symbol->value = temp;
        }
        else if (child->type == "Array") {
            for (Node * c : child->children) {
                if (c->type == "Identifier") variable_symbol->value = c->value;
                for (Node * v : c->children) {
                    if (v->type == "function_call") variable_symbol->value += '.' + v->value; 
                }
            }
        }
    }
    if (current_scope->symbols.find(variable_symbol->identifier) != current_scope->symbols.end()  ) {
        errors.push_back(variable_symbol->identifier + " duplication in scope");
    }

    return symPtr;
}


Symbol * Symbol_table::Assign_s(Symbol * &symPtr, Node * root) {
    symPtr = new Assign_symbol();
    Assign_symbol * assign_symbol = static_cast<Assign_symbol*>(symPtr);
    
    for (Node* child : root->children) {

        if (child->type == "Identifier")
            assign_symbol->identifier = child->value;

        else if (child->type == "Value")
            assign_symbol->value = child->value;


        else if (child->type == "function_call") {

            assign_symbol->value = child->value;

            for (Node* argNode : child->children) {
                if (argNode->type == "Arguments") {

                    assign_symbol->value += "(";
                    bool first = true;

                    for (Node* arg : argNode->children) {
                        if (!first) assign_symbol->value += ", ";
                        assign_symbol->value += build_expr(arg, 0);
                        first = false;
                    }

                    assign_symbol->value += ")";
                }
            }
        }


        else if (
            child->type == "Add" ||
            child->type == "Multiply" ||
            child->type == "Minus" ||
            child->type == "Power" ||
            child->type == "&" ||
            child->type == "|" ||
            child->type == "!" ||
            child->type == "Less_than" ||
            child->type == "Greater_than" ||
            child->type == "Less_than_or_equal_to" ||
            child->type == "Greater_than_or_equal_to" ||
            child->type == "Equal_to"
        )
            assign_symbol->value = build_expr(child, 0);


        else if (child->type == "Array" && child->value == "1") {

            for (Node * x : child->children) {

                if (x->type == "Identifier") {
                    assign_symbol->identifier = x->value;
                }

                else if (x->type == "Index") {

                    for (Node * q : x->children) {

                        if (
                            q->type == "Add" ||
                            q->type == "Multiply" ||
                            q->type == "Minus" ||
                            q->type == "Power" ||
                            q->type == "&" ||
                            q->type == "|" ||
                            q->type == "!" ||
                            q->type == "Less_than" ||
                            q->type == "Greater_than" ||
                            q->type == "Less_than_or_equal_to" ||
                            q->type == "Greater_than_or_equal_to" ||
                            q->type == "Equal_to"
                        )
                            assign_symbol->index += '[' + build_expr(q, 0) + ']';

                        else if (q->type == "Value")
                            assign_symbol->index += '[' + q->value + ']';
                    }
                }
            }
        }


        else if (child->type == "Array" && (child->value == "2" || child->value == "")) {
            bool literal = false;

            for (Node* x : child->children)
                if (x->type == "Array_literal")
                    literal = true;


            // ARRAY LITERAL  number := int[1,2,3]
            if (literal) {

                string type;

                for (Node* x : child->children) {

                    if (x->type == "Type")
                        type = x->value;

                    else if (x->type == "Array_literal") {

                        assign_symbol->value = type + "[";

                        bool first = true;

                        for (Node* v : x->children) {

                            if (!first)
                                assign_symbol->value += ",";

                            assign_symbol->value += v->value;

                            first = false;
                        }

                        assign_symbol->value += "]";
                    }
                }
            }
            else {

                for (Node * x : child->children) {

                    if (x->type == "Identifier") {
                        assign_symbol->value = x->value;
                    }

                    else if (x->type == "Index") {

                        for (Node * q : x->children) {

                            if (
                                q->type == "Add" ||
                                q->type == "Multiply" ||
                                q->type == "Minus" ||
                                q->type == "Power"
                            )
                                assign_symbol->value += '[' + build_expr(q, 0) + ']';

                            else if (q->type == "Value")
                                assign_symbol->value += '[' + q->value + ']';
                        }
                    }
                }
            }
        }
    }


    Symbol* found = lookup(assign_symbol->identifier);

    if (found == nullptr) {
        errors.push_back("Variable '" + assign_symbol->identifier + "' not declared in this scope.");
    }

    return symPtr;
}

int Symbol_table::precedence(const string& type) {

    if (type == "|") return 1;
    if (type == "&") return 2;

    if (
        type == "Less_than" ||
        type == "Greater_than" ||
        type == "Less_than_or_equal_to" ||
        type == "Greater_than_or_equal_to" ||
        type == "Equal_to"
    ) return 3;

    if (type == "Add" || type == "Minus") return 4;

    if (type == "Multiply" || type == "Divide") return 5;

    if (type == "Power") return 6;

    if (type == "!") return 7;

    return 8;
}

string Symbol_table::build_expr(Node* node, int parentPrec) {

    if (!node) return "";

    // VALUE / IDENTIFIER
    if (node->type == "Value" || node->type == "Identifier")
        return node->value;


    // NOT operator  !x
    if (node->type == "!") {

        auto it = node->children.begin();

        return "!" + build_expr(*it, precedence(node->type));
    }


    // ARRAY ACCESS  values[i]
    if (node->type == "Array") {

        string result;

        for (Node* child : node->children) {

            if (child->type == "Identifier")
                result += child->value;

            else if (child->type == "Index") {

                result += "[";

                bool first = true;

                for (Node* idx : child->children) {

                    if (!first)
                        result += ",";

                    result += build_expr(idx, 0);

                    first = false;
                }

                result += "]";
            }
        }

        return result;
    }


    // FUNCTION CALL
    if (node->type == "function_call") {

        string result = node->value;

        for (Node* child : node->children) {

            if (child->type == "Arguments") {

                result += "(";

                bool first = true;

                for (Node* arg : child->children) {

                    if (!first)
                        result += ", ";

                    result += build_expr(arg, 0);

                    first = false;
                }

                result += ")";
            }
        }

        return result;
    }


    // ARGUMENT LIST
    if (node->type == "Arguments") {

        string result;
        bool first = true;

        for (Node* child : node->children) {

            if (!first)
                result += ", ";

            result += build_expr(child, 0);

            first = false;
        }

        return result;
    }


    // OPERATORS
    string op;

    if (node->type == "Add") op = "+";
    else if (node->type == "Minus") op = "-";
    else if (node->type == "Multiply") op = "*";
    else if (node->type == "Divide") op = "/";
    else if (node->type == "Power") op = "^";

    else if (node->type == "&") op = "&";
    else if (node->type == "|") op = "|";

    else if (node->type == "Less_than") op = "<";
    else if (node->type == "Greater_than") op = ">";
    else if (node->type == "Less_than_or_equal_to") op = "<=";
    else if (node->type == "Greater_than_or_equal_to") op = ">=";
    else if (node->type == "Equal_to") op = "=";

    else
        return "";


    auto it = node->children.begin();

    string left = build_expr(*it++, precedence(node->type));
    string right = build_expr(*it, precedence(node->type));

    string expr = left + " " + op + " " + right;

    if (precedence(node->type) < parentPrec)
        expr = "(" + expr + ")";

    return expr;
}

Symbol * Symbol_table::Return_s(Symbol * &symPtr, Node * root) {
    symPtr = new Return_symbol();
    Return_symbol * return_symbol = static_cast<Return_symbol*>(symPtr);

    for (Node* child : root->children) {

        if (child->type == "Value" || child->type == "Identifier") {
            return_symbol->value = child->value;
        }

        else if (
            child->type == "Add" ||
            child->type == "Minus" ||
            child->type == "Multiply" ||
            child->type == "Divide" ||
            child->type == "Power" ||
            child->type == "function_call"
        ) {
            return_symbol->value = build_expr(child, 0);
        }
    }

    return symPtr;
}


Symbol * Symbol_table::Print_s(Symbol * &symPtr, Node * root) {
    symPtr = new Print_symbol();
    Print_symbol * print_symbol = static_cast<Print_symbol*>(symPtr);
    
    for (Node* child : root->children) {

        if (child->type == "Value") {
            print_symbol->value = child->value;
        }
        else if (child->type == "Class") {

            print_symbol->value = child->value;

            for (Node* c : child->children) {

                if (c->type == "function_call") {

                    print_symbol->value += "." + c->value;

                    for (Node* argNode : c->children) {

                        if (argNode->type == "Arguments") {

                            print_symbol->value += "(";

                            bool first = true;

                            for (Node* arg : argNode->children) {

                                if (!first) print_symbol->value += ", ";

                                print_symbol->value += build_expr(arg, 0);

                                first = false;
                            }

                            print_symbol->value += ")";
                        }
                    }
                }
            }
        }
        else if (child->type == "Identifier") {

            print_symbol->value = child->value;

            for (Node* c : child->children) {

                if (c->type == "function_call") {

                    print_symbol->value += "." + c->value;

                    for (Node* argNode : c->children) {

                        if (argNode->type == "Arguments") {

                            print_symbol->value += "(";

                            bool first = true;

                            for (Node* arg : argNode->children) {

                                if (!first) print_symbol->value += ", ";

                                print_symbol->value += build_expr(arg, 0);

                                first = false;
                            }

                            print_symbol->value += ")";
                        }
                    }
                }
            }
        }

        else if (child->type == "Array") {

            for (Node * x : child->children) {

                if (x->type == "Identifier") {
                    print_symbol->value = x->value;
                }

                else if (x->type == "Index") {

                    for (Node * q : x->children) {

                        if (
                            q->type == "Add" ||
                            q->type == "Multiply" ||
                            q->type == "Minus" ||
                            q->type == "Power"
                        )
                            print_symbol->value += '[' + build_expr(q, 0) + ']';

                        else if (q->type == "Value")
                            print_symbol->value += '[' + q->value + ']';
                    }
                }
            }
        }
    }

    return symPtr;
}

Symbol * Symbol_table::Main_s(Symbol * &symPtr, Node * root) {
    symPtr = new Main_symbol();
    Main_symbol * main_symbol = static_cast<Main_symbol*>(symPtr);
    main_symbol->type = root->value;
    return symPtr;
}

Symbol * Symbol_table::Read_s(Symbol * &symPtr, Node * root) {
    symPtr = new Read_symbol();
    Read_symbol * read_symbol = static_cast<Read_symbol*>(symPtr);
    
    for (Node* child : root->children) {
        if (child->type == "Value") {
            read_symbol->value = child->value;
        }
    }
    return symPtr;
}

Symbol * Symbol_table::For_s(Symbol * &symPtr, Node * root) {
    symPtr = new For_symbol();
    For_symbol * for_symbol = static_cast<For_symbol*>(symPtr);

    for (Node* child : root->children) {

        if (child->type == "Assign" && child->value == "1") {
            for (Node * c : child->children) {
                if (c->type == "Identifier") {
                    for_symbol->part1 += c->value + " := ";
                }
                else if (c->type == "Value") {
                    for_symbol->part1 += c->value;
                }
            }
        } 

        else if (child->type == "Assign" && child->value == "2") {

            bool first = true;

            for (Node * c : child->children) {

                if ((c->type == "Identifier" || c->type == "Value") && first) {
                    for_symbol->part3 += c->value + " := ";
                    first = false;
                }

                else if (c->type == "Identifier" || c->type == "Value") {
                    for_symbol->part3 += c->value;
                }

                else if (
                    c->type == "Add" ||
                    c->type == "Multiply" ||
                    c->type == "Minus" ||
                    c->type == "Power"
                ) {
                    for_symbol->part3 += build_expr(c, 0);
                }
            }
        }

        else if (
            child->type == "Greater_than_or_equal_to" ||
            child->type == "Less_than_or_equal_to" || 
            child->type == "Greater_than" ||
            child->type == "Less_than"
        ) {

            int index = 0;
            string temp[2];

            for (Node * c : child->children) {

                if (c->type == "Value") {
                    temp[index++] = c->value;
                }

                else if (c->type == "Array") {

                    for (Node * x : c->children) {

                        if (x->type == "Identifier") {
                            temp[index] += x->value;
                        }

                        for (Node * v : x->children) {
                            if (v->type == "function_call") {
                                temp[index] += "." + v->value;
                            }
                        }
                    }

                    index++;
                }

                else if (
                    c->type == "Add" ||
                    c->type == "Multiply" ||
                    c->type == "Minus" ||
                    c->type == "Power"
                ) {
                    temp[index++] += build_expr(c, 0);
                }
            }

            if (child->type == "Greater_than_or_equal_to")
                for_symbol->part2 = temp[0] + " >= " + temp[1];

            else if (child->type == "Less_than_or_equal_to")
                for_symbol->part2 = temp[0] + " <= " + temp[1];

            else if (child->type == "Greater_than")
                for_symbol->part2 = temp[0] + " > " + temp[1];

            else if (child->type == "Less_than")
                for_symbol->part2 = temp[0] + " < " + temp[1];
        }

        else if (child->type == "Value") {
            for_symbol->part2 = child->value;
        }
    }

    return symPtr;
}

Symbol * Symbol_table::If_s(Symbol * &symPtr, Node * root) {
    symPtr = new If_symbol();
    If_symbol * if_symbol = static_cast<If_symbol*>(symPtr);

    bool negation = false;

    for (Node* child : root->children) {

        if (child->type == "!") {
            negation = true;

            for (Node* inner : child->children) {

                if (
                    inner->type == "Greater_than_or_equal_to" ||
                    inner->type == "Less_than_or_equal_to" ||
                    inner->type == "Greater_than" ||
                    inner->type == "Less_than" ||
                    inner->type == "Equal_to"
                ) {

                    auto it = inner->children.begin();

                    string left = build_expr(*it++, 0);
                    string right = build_expr(*it, 0);

                    if_symbol->part1 = left;
                    if_symbol->part2 = right;

                    if (inner->type == "Greater_than_or_equal_to") if_symbol->op = ">=";
                    else if (inner->type == "Less_than_or_equal_to") if_symbol->op = "<=";
                    else if (inner->type == "Greater_than") if_symbol->op = ">";
                    else if (inner->type == "Less_than") if_symbol->op = "<";
                    else if (inner->type == "Equal_to") if_symbol->op = "=";
                }
            }
        }
        else if (
            child->type == "Greater_than_or_equal_to" ||
            child->type == "Less_than_or_equal_to" ||
            child->type == "Greater_than" ||
            child->type == "Less_than" ||
            child->type == "Equal_to"
        ) {

            auto it = child->children.begin();

            string left = build_expr(*it++, 0);
            string right = build_expr(*it, 0);

            if_symbol->part1 = left;
            if_symbol->part2 = right;

            if (child->type == "Greater_than_or_equal_to") if_symbol->op = ">=";
            else if (child->type == "Less_than_or_equal_to") if_symbol->op = "<=";
            else if (child->type == "Greater_than") if_symbol->op = ">";
            else if (child->type == "Less_than") if_symbol->op = "<";
            else if (child->type == "Equal_to") if_symbol->op = "=";
        }
        else if (child->type == "Value") {
            if_symbol->part1 = child->value; 
        }
    }

    // APPLY NEGATION IF NEEDED
    if (negation) {
        if_symbol->part1 = "!(" + if_symbol->part1;
        if_symbol->part2 = if_symbol->part2 + ")";
    }

    return symPtr;
}

Symbol * Symbol_table::Comment_s(Symbol * &symPtr, Node * root) {
    symPtr = new Comment_symbol();
    Comment_symbol * comment_symbol = static_cast<Comment_symbol*>(symPtr);
    for (Node * child : root->children) {
        if (child->type == "Value") {
            comment_symbol->identifier = child->value;
        }
    }
    return symPtr;
}

Symbol* Symbol_table::Else_s(Symbol*& symPtr, Node* root) {
    symPtr = new Else_symbol();
    symPtr->identifier = "else";
    return symPtr;
}

Symbol * Symbol_table::Break_s(Symbol * &symPtr, Node * root) {
    symPtr = new Break_symbol();
    symPtr->identifier = root->value;
    
    return symPtr;
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
        else if (auto returnPtr = dynamic_cast<Return_symbol*>(symbol))
            returnPtr->print();
        else if (auto printPtr = dynamic_cast<Print_symbol*>(symbol))
            printPtr->print();
        else if (auto mainPtr = dynamic_cast<Main_symbol*>(symbol))
            mainPtr->print();
        else if (auto readPtr = dynamic_cast<Read_symbol*>(symbol))
            readPtr->print();
        else if (auto forPtr = dynamic_cast<For_symbol*>(symbol))
            forPtr->print();
        else if (auto ifPtr = dynamic_cast<If_symbol*>(symbol))
            ifPtr->print();
        else if (auto CommentPtr = dynamic_cast<Comment_symbol*>(symbol))
            CommentPtr->print();
        else if (auto elsePtr = dynamic_cast<Else_symbol*>(symbol))
            elsePtr->print();
        else if (auto breakPtr = dynamic_cast<Break_symbol*>(symbol))
            breakPtr->print();

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

            return it->second;
        }
        temp = temp->parent;
    }
    return nullptr;
}


