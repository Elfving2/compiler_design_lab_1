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
    bool create_scope = false;

    Symbol * symPtr = nullptr;
    if (root->type == "Class") {
        symPtr = Class_s(symPtr, root);
        create_scope = true;
    }
    else if(root->type == "function_def") {
        symPtr = Method_s(symPtr, root);
        create_scope = true;
    }
    else if(root->type == "Main") {
        symPtr = Main_s(symPtr, root);
        create_scope = true;
    }
    else if(root->type == "If_statement") {
        symPtr = If_s(symPtr, root);
        create_scope = true;
    }
    else if(root->type == "For_loop") {
        symPtr = For_s(symPtr, root);
        create_scope = true;
        if (symPtr) {
            current_scope->symbols[symPtr->identifier] = symPtr;
            current_scope->ordered_symbols.push_back(symPtr);
        }

        enter_scope(symPtr);

        // Kör endast body av loopen
        for (Node* child : root->children) {
            if (child->type == "Block") {
                execute(child);
            }
        }

        leave_scope();
        return;

    }
    else if (root->type == "varDecl") {
        symPtr = Variable_s(symPtr, root);
    }
    else if (root->type == "Assign") {
        symPtr = Assign_s(symPtr, root);
    }
    else if (root->type == "Return") {
        symPtr = Return_s(symPtr, root);
    }
    else if (root->type == "Print") {
        symPtr = Print_s(symPtr, root);
    }
    else if (root->type == "Read") {
        symPtr = Read_s(symPtr, root);
    }
    else if (root->type == "Comment") {
        symPtr = Comment_s(symPtr, root);
    }





    if (symPtr) {
        current_scope->symbols[symPtr->identifier] = symPtr;
        current_scope->ordered_symbols.push_back(symPtr);
    }

    if (create_scope) enter_scope(symPtr);
    

    for (Node* child : root->children)
        execute(child);
    
    if (create_scope) leave_scope();

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
        else if (child->type == "Modifier") {
            variable_symbol->isVolatile = true;
        }
        else if (child->type == "Value") {
            variable_symbol->value = child->value;
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
        else if (
            child->type == "Add" ||
            child->type == "Multiply" ||
            child->type == "Minus" ||
            child->type == "Power" 
        ) assign_symbol->value = build_expr(child, 0);
        else if (child->type == "Array" && child->value == "1") {
            for (Node * x : child->children) {
                if (x->type == "Identifier") {
                    assign_symbol->identifier =  x->value;
                }
                else if(x->type == "Index") {
                    for (Node * q : x->children) {
                        if (
                            q->type == "Add" ||
                            q->type == "Multiply" ||
                            q->type == "Minus" ||
                            q->type == "Power"
                        ) assign_symbol->index += '[' + build_expr(q, 0) +']';
                        else if (q->type == "Value") {
                             assign_symbol->index += '[' + q->value +']';
                        }
                    }
                }
            }        
        }
        else if (child->type == "Array" && (child->value == "2" || child->value == "")) {
            for (Node * x : child->children) {
                if (x->type == "Identifier") {
                    assign_symbol->value =  x->value;
                }
                else if(x->type == "Index") {
                    for (Node * q : x->children) {
                        if (
                            q->type == "Add" ||
                            q->type == "Multiply" ||
                            q->type == "Minus" ||
                            q->type == "Power"
                        ) assign_symbol->value += '[' + build_expr(q, 0) +']';
                        else if (q->type == "Value") {
                             assign_symbol->value += '[' + q->value +']';
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

string Symbol_table::build_expr(Node* node, int parentPrec) {

    if (node->type == "Value" || node->type == "Identifier")
        return node->value;

    string op;

    if (node->type == "Add") op = "+";
    else if (node->type == "Minus") op = "-";
    else if (node->type == "Multiply") op = "*";
    else if (node->type == "Divide") op = "/";
    else if (node->type == "Power") op = "^";

    auto it = node->children.begin();
    string left = build_expr(*it++, precedence(node->type));
    string right = build_expr(*it,  precedence(node->type));

    string expr = left + " " + op + " " + right;

    if (precedence(node->type) < parentPrec)
        expr = "(" + expr + ")";

    return expr;
}

int Symbol_table::precedence(const string& type) {
    if (type == "Add" || type == "Minus") return 1;
    if (type == "Multiply" || type == "Divide") return 2;
    if (type == "Power") return 3;
    return 4;
}


Symbol * Symbol_table::Return_s(Symbol * &symPtr, Node * root) {
    symPtr = new Return_symbol();
    Return_symbol * return_symbol = static_cast<Return_symbol*>(symPtr);
    
    for (Node* child : root->children) {
        if (child->type == "Value") {
            return_symbol->value = child->value;
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
        else if (child->type == "Array") {
            for (Node * x : child->children) {
                if (x->type == "Identifier") {
                    print_symbol->value =  x->value;
                }
                else if(x->type == "Index") {
                    for (Node * q : x->children) {
                        if (
                            q->type == "Add" ||
                            q->type == "Multiply" ||
                            q->type == "Minus" ||
                            q->type == "Power"
                        ) print_symbol->value += '[' + build_expr(q, 0) +']';
                        else if (q->type == "Value") {
                            print_symbol->value += '[' + q->value + ']';
                        }
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
            for (Node * c : child->children) {
                if (c->type == "Identifier") {
                    for_symbol->part3 += c->value + " := ";
                }
                else if (c->type == "Value") {
                    for_symbol->part3 += c->value;
                }
                else if (
                    c->type == "Add" ||
                    c->type == "Multiply" ||
                    c->type == "Minus" ||
                    c->type == "Power" 
                ) for_symbol->part3 += build_expr(c, 0);
            }
        }
        else if (
            child->type == "Greater_than_or_equal_to" ||
            child->type ==  "Less_than_or_equal_to" || 
            child->type ==  "Greater_than" ||
            child->type ==  "Less_than"
        ) {
            int index = 0;
            string temp[2];
            for (Node * c : child->children) {
                if (c->type == "Value") {
                    temp[index++] = c->value;
                }
                else if (
                    c->type == "Add" ||
                    c->type == "Multiply" ||
                    c->type == "Minus" ||
                    c->type == "Power" 
                ) temp[index++] += build_expr(c, 0);
            }
            if (child->type == "Greater_than_or_equal_to") for_symbol->part2 = temp[0] + " >= " + temp[1];
            else if (child->type == "Less_than_or_equal_to") for_symbol->part2 = temp[0] + " <= " + temp[1];
            else if (child->type == "Greater_than") for_symbol->part2 = temp[0] + " > " + temp[1];
            else if (child->type == "Less_than") for_symbol->part2 = temp[0] + " < " + temp[1];
        }
    }
    return symPtr;
}

Symbol * Symbol_table::If_s(Symbol * &symPtr, Node * root) {
    symPtr = new If_symbol();
    If_symbol * if_symbol = static_cast<If_symbol*>(symPtr);
    
    for (Node* child : root->children) {
        if (child->type == "Equal_to") {
            if_symbol->op = " = ";
            for (Node * c : child->children) {
                if (
                    c->type == "Add" ||
                    c->type == "Multiply" ||
                    c->type == "Minus" ||
                    c->type == "Power" ) {
                        if_symbol->part1 = build_expr(c, 0);
                    }
                else if (c->type == "Value") if_symbol->part2 = c->value;
            }
        }
        else if (
            child->type == "Greater_than_or_equal_to" ||
            child->type ==  "Less_than_or_equal_to" || 
            child->type ==  "Greater_than" ||
            child->type ==  "Less_than"
        ) 
        {
            int index = 0;
            string temp[2];
            for (Node * c : child->children) {
                if (c->type == "Array") {
                    for (Node * x : c->children) {
                        if (x->type == "Identifier") {
                            temp[index] += x->value;
                        }
                        else if(x->type == "Index") {
                            for (Node * q : x->children) {
                                if (
                                    q->type == "Add" ||
                                    q->type == "Multiply" ||
                                    q->type == "Minus" ||
                                    q->type == "Power"
                                ) temp[index] += '[' + build_expr(q, 0) +']';
                                else if (q->type == "Value") {
                                    temp[index] += '[' + q->value +']';
                                }
                            }
                        }
                    }
                }
                else if (c->type == "Value") {
                    temp[index] = c->value;
                }
                index++;
            }
            if_symbol->part1 = temp[0];
            if_symbol->part2 = temp[1];
            if (child->type == "Greater_than_or_equal_to") if_symbol->op = '>=';
            else if (child->type == "Less_than_or_equal_to") if_symbol->op = '<=';
            else if (child->type == "Greater_than") if_symbol->op = '>';
            else if (child->type == "Less_than") if_symbol->op = '<';
        }
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