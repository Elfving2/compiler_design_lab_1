#include "IRGenerator.h"

void IRGenerator::execute(Node* root) {
    if (!root) return;

    if (root->type == "If_statement") {
        gen_if(root);
        return;
    }

    else if (root->type == "function_def") {
        gen_function(root);
        return;
    }

    else if (root->type == "Class") {
        for (Node* child : root->children)
            execute(child);
        return;
    }

    else if (root->type == "For_loop") {
        gen_for(root);
        return;
    }

    else if (root->type == "Assign") {
        gen_assign(root);
        return;
    }

    else if (root->type == "Return") {
        gen_return(root);
        return;
    }

    else if (root->type == "Print") {
        gen_print(root);
        return;
    }
    
    else if (root->type == "Break") {
        gen_break(root);
        return;
    }
    else if (root->type == "varDecl") {

        bool hasValue = false;

        for (Node* child : root->children) {
            if (child->type == "Value" ||
                child->type == "Add" ||
                child->type == "Minus" ||
                child->type == "Multiply" ||
                child->type == "Divide" ||
                child->type == "Power" ||
                child->type == "Array" ||
                child->type == "function_call" ||
                child->type == "Array_literal"
            )
            {
                hasValue = true;
            }
        }

        if (hasValue)
            gen_assign(root);
        
        return;
    }
    else if (root->type == "Read") {
        gen_read(root);
        return;
    }

    else if (root->type == "Identifier") {

        auto it = root->children.begin();

        if (it != root->children.end()) {

            Node* next = *it;

            if (next->type == "function_call") {
                gen_expr(root);
                return;
            }
        }
    }

    for (Node* child : root->children)
        execute(child);
}

void IRGenerator::gen_if(Node* node) {

    Node* condition = nullptr;
    Node* thenBlock = nullptr;
    Node* elseBlock = nullptr;

    for (Node* child : node->children) {

        if (child->type == "Block" && !thenBlock)
            thenBlock = child;

        else if (child->type == "Else")
            elseBlock = child;

        else
            condition = child;
    }

    string cond = gen_expr(condition);

    string Ltrue = new_label();
    string Lfalse = new_label();
    string Lend = new_label();

    emit(Ltrue, cond, "if", "");
    emit(Lfalse, "", "goto", "");
    
    // THEN
    emit(Ltrue, "", "label", "");

    if (thenBlock)
        execute(thenBlock);

    emit(Lend, "", "goto", "");

    // ELSE
    emit(Lfalse, "", "label", "");

    if (elseBlock)
        execute(elseBlock);

    emit(Lend, "", "label", "");
}


string IRGenerator::gen_expr(Node* node) {

    if (!node) return "";

    // VALUE
    if (node->type == "Value")
        return node->value;

    // ARRAY LITERAL
    if (node->type == "Array_literal") {

        int size = node->children.size();
        string type = "int";

        string temp = new_temp();
        emit(temp, "new " + type + "[" + to_string(size) + "]", "", "");

        int i = 0;
        for (Node* v : node->children) {
            string val = gen_expr(v);
            emit(temp + "[" + to_string(i) + "]", val, "=", "");
            i++;
        }

        return temp;
    }

    // IDENTIFIER (kan vara method call)
    if (node->type == "Identifier") {

        for (Node* child : node->children) {

            if (child->type == "function_call") {

                string func = child->value;
                vector<string> args;

                for (Node* argNode : child->children) {

                    if (argNode->type == "Arguments") {

                        for (Node* arg : argNode->children)
                            args.push_back(gen_expr(arg));
                    }
                }

                string arglist;
                for (size_t i = 0; i < args.size(); i++) {
                    if (i > 0) arglist += ", ";
                    arglist += args[i];
                }

                string temp = new_temp();
                emit(temp, "call " + func + "(" + arglist + ")", "", "");

                return temp;
            }
        }

        return node->value;
    }

    if (node->type == "Class") {

        // skip class go to its children and generate code for them (e.g., method calls)
        for (Node* child : node->children)
            return gen_expr(child);

        return "";
    }

    // UNARY NOT
    if (node->type == "!") {

        auto it = node->children.begin();
        string val = gen_expr(*it);

        string temp = new_temp();
        emit(temp, val, "!", "");

        return temp;
    }

    // ARRAY ACCESS
    if (node->type == "Array") {

        string base;
        string index;

        for (Node* child : node->children) {

            if (child->type == "Identifier") {

                base = child->value;

                for (Node* sub : child->children) {

                    if (sub->type == "function_call" && sub->value == "length") {

                        string temp = new_temp();
                        emit(temp, base + ".length", "", "");
                        return temp;
                    }
                }
            }

            else if (child->type == "Index") {

                auto it = child->children.begin();

                if (it != child->children.end())
                    index = gen_expr(*it);
            }

            else if (child->type == "Array_literal") {

                int size = child->children.size();
                string type = node->value;

                string temp = new_temp();
                emit(temp, "new " + type + "[" + to_string(size) + "]", "", "");

                int i = 0;
                for (Node* v : child->children) {
                    string val = gen_expr(v);
                    emit(temp + "[" + to_string(i) + "]", val, "=", "");
                    i++;
                }

                return temp;
            }
        }

        string temp = new_temp();
        emit(temp, base + "[" + index + "]", "load", "");

        return temp;
    }

    // NORMAL FUNCTION CALL
    if (node->type == "function_call") {

        string func = node->value;
        vector<string> args;

        for (Node* child : node->children) {

            if (child->type == "Arguments") {

                for (Node* arg : child->children)
                    args.push_back(gen_expr(arg));
            }
        }

        string arglist;
        for (size_t i = 0; i < args.size(); i++) {

            if (i > 0) arglist += ", ";
            arglist += args[i];
        }

        string temp = new_temp();
        emit(temp, "call " + func + "(" + arglist + ")", "", "");

        return temp;
    }

    // BINARY OPERATORS
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
    else if (node->type == "Equal_to") op = "==";
    else
        return "";

    if (node->children.size() < 2)
        return "";

    auto it = node->children.begin();

    Node* leftNode = *it;
    ++it;
    Node* rightNode = *it;

    string left = gen_expr(leftNode);
    string right = gen_expr(rightNode);

    string temp = new_temp();
    emit(temp, left, op, right);

    return temp;
}

void IRGenerator::gen_assign(Node* node) {

    Node* lhsNode = nullptr;
    Node* rhsNode = nullptr;

    for (Node* child : node->children) {

        if (!lhsNode && (child->type == "Identifier" || child->type == "Array"))
            lhsNode = child;
        else
            rhsNode = child;
    }

    if (!lhsNode || !rhsNode)
        return;

    string lhs;

    if (lhsNode->type == "Identifier") {
        lhs = lhsNode->value;
    }
    else if (lhsNode->type == "Array") {

        string base;
        string index;

        for (Node* c : lhsNode->children) {

            if (c->type == "Identifier")
                base = c->value;

            else if (c->type == "Index") {

                auto it = c->children.begin();

                if (it != c->children.end())
                    index = gen_expr(*it);
            }
        }

        lhs = base + "[" + index + "]";
    }

    string rhs = gen_expr(rhsNode);

    emit(lhs, rhs, "=", "");
}

void IRGenerator::gen_print(Node* node) {

    for (Node* child : node->children) {

        string val = gen_expr(child);

        emit("", val, "print", "");
    }
}

void IRGenerator::gen_read(Node* node) {

    for (Node* child : node->children) {

        if (child->type == "Value")
            emit("", child->value, "read", "");
    }
}


void IRGenerator::gen_return(Node* node) {

    for (Node* child : node->children) {

        string val = gen_expr(child);

        emit("", val, "return", "");
    }
}

void IRGenerator::gen_for(Node* node) {

    Node* init = nullptr;
    Node* condition = nullptr;
    Node* update = nullptr;
    Node* block = nullptr;

    for (Node* child : node->children) {

        if (child->type == "Assign" && !init)
            init = child;

        else if (child->type == "Assign")
            update = child;

        else if (child->type == "Block")
            block = child;

        else
            condition = child;
    }
    if (init)
        execute(init);

    string Lstart = new_label();
    string Lbody = new_label();
    string Lend = new_label();

    loop_end_labels.push(Lend);


    emit(Lstart, "", "label", "");

    string cond = gen_expr(condition);

    emit(Lbody, cond, "if", "");
    emit(Lend, "", "goto", "");

    emit(Lbody, "", "label", "");
    if (block)
        execute(block);

    if (update)
        execute(update);

    emit(Lstart, "", "goto", "");

    emit(Lend, "", "label", "");
    loop_end_labels.pop();
}

void IRGenerator::gen_break(Node* node) {

    if (!loop_end_labels.empty()) {
        string Lend = loop_end_labels.top();
        emit(Lend, "", "goto", "");
    }
}

void IRGenerator::gen_function(Node* node) {

    string name;
    Node* block = nullptr;

    for (Node* child : node->children) {

        if (child->type == "Identifier")
            name = child->value;

        else if (child->type == "Block")
            block = child;
    }

    emit(name, "", "function", "");

    if (block)
        execute(block);

    emit("", "", "endfunc", "");
}


void IRGenerator::emit(string result, string arg1, string op, string arg2) {
    instructions.push_back({result, arg1, op, arg2});
}

string IRGenerator::new_label() {
    return "L" + to_string(label_count++);
}

string IRGenerator::new_temp() {
    return "T" + to_string(temp_count++);
}

void IRGenerator::print_TAC() {

    for (auto &instr : instructions) {

        if (instr.operation == "label")
            cout << instr.result << ":" << endl;

        else if (instr.operation == "goto")
            cout << "goto " << instr.result << endl;

        else if (instr.operation == "if")
            cout << "if " << instr.arg1 << " goto " << instr.result << endl;

        else if (instr.operation == "print")
            cout << "print " << instr.arg1 << endl;

        else if (instr.operation == "return")
            cout << "return " << instr.arg1 << endl;

        else if (instr.operation == "=") {
            if (instr.arg2.empty())
                cout << instr.result << " = " << instr.arg1 << endl;
            else
                cout << instr.result << " = "
                    << instr.arg1 << " "
                    << instr.operation << " "
                    << instr.arg2 << endl;
        }

        else if (instr.operation == "!")
            cout << instr.result << " = !" << instr.arg1 << endl;

        else if (instr.operation == "load")
            cout << instr.result << " = " << instr.arg1 << endl;

        else if (instr.operation == "read")
            cout << "read " << instr.arg1 << endl;
        else if (instr.operation == "function")
            cout << "function " << instr.result << endl;
        else if (instr.operation == "endfunc")
            cout << "end" << endl;
        else
            cout << instr.result << " = "
                << instr.arg1 << " "
                << instr.operation << " "
                << instr.arg2 << endl;
    }
    
}

vector<basic_block> IRGenerator::build_basic_blocks() {

    vector<basic_block> blocks;
    set<int> leaders;

    int n = instructions.size();

    if (n == 0) return blocks;

    leaders.insert(0);

    for (int i = 0; i < n; i++) {

        if (instructions[i].operation == "goto" ||
            instructions[i].operation == "if") {

            string label = instructions[i].result;

            for (int j = 0; j < n; j++) {
                if (instructions[j].operation == "label" &&
                    instructions[j].result == label) {

                    leaders.insert(j);
                }
            }

            if (i + 1 < n)
                leaders.insert(i + 1);
        }

        if (instructions[i].operation == "function" ) {
            leaders.insert(i);
        }
    }

    basic_block block;
    block.id = 0;

    for (int i = 0; i < n; i++) {

        if (leaders.count(i) && i != 0 && !block.instructions.empty()) {

            string lastOp = block.instructions.back().operation;

            if (lastOp != "goto" && lastOp != "return" && lastOp != "endfunc") {

                blocks.push_back(block);

                block.instructions.clear();
                block.successors.clear();
                block.id = blocks.size();
            }
        }

        block.instructions.push_back(instructions[i]);

        if (instructions[i].operation == "goto" ||
            instructions[i].operation == "return" || 
            instructions[i].operation == "endfunc") {

            blocks.push_back(block);

            block.instructions.clear();
            block.successors.clear();
            block.id = blocks.size();
        }
    }

    if (!block.instructions.empty())
        blocks.push_back(block);

    return blocks;
}

void IRGenerator::build_cfg(vector<basic_block>& blocks) {

    map<string,int> label_to_block;

    // hitta label → block
    for (auto &b : blocks) {
        for (auto &instr : b.instructions) {
            if (instr.operation == "label") {
                label_to_block[instr.result] = b.id;
            }
        }
    }

    for (int i = 0; i < blocks.size(); i++) {

        auto &block = blocks[i];
        auto &last = block.instructions.back();

        if (last.operation == "goto") {

            block.successors.push_back(label_to_block[last.result]);
        }

        else if (last.operation == "if") {

            block.successors.push_back(label_to_block[last.result]);

            if (i + 1 < blocks.size())
                block.successors.push_back(i + 1);
        }

        else if (last.operation != "return" &&
                last.operation != "endfunc")
        {
            if (i + 1 < blocks.size())
                block.successors.push_back(i + 1);
        }
    }
}

void IRGenerator::generate_dot(vector<basic_block>& blocks) {

    ofstream file("cfg.dot");

    file << "digraph CFG {\n\n";
    file << "node [shape=box];\n\n";

    for (auto &b : blocks) {

        file << "B" << b.id << " [label=\"Block " << b.id << "\\n";

        for (auto &instr : b.instructions) {

            if (instr.operation == "label")
                file << instr.result << ":\\n";

            else if (instr.operation == "goto")
                file << "goto " << instr.result << "\\n";

            else if (instr.operation == "if")
                file << "if " << instr.arg1 << " goto " << instr.result << "\\n";

            else if (instr.operation == "print")
                file << "print " << instr.arg1 << "\\n";

            else if (instr.operation == "return")
                file << "return " << instr.arg1 << "\\n";

            else if (instr.operation == "=") {

                if (instr.arg2.empty())
                    file << instr.result << " = " << instr.arg1 << "\\n";
                else
                    file << instr.result << " = "
                        << instr.arg1 << " "
                        << instr.operation << " "
                        << instr.arg2 << "\\n";
            }

            else if (instr.operation == "!")
                file << instr.result << " = !" << instr.arg1 << "\\n";

            else if (instr.operation == "load")
                file << instr.result << " = " << instr.arg1 << "\\n";
            else if (instr.operation == "read")
                file << "read " << instr.arg1 << "\\n";
            else if (instr.operation == "function")
                file << "function " << instr.result << "\\n";
            else if (instr.operation == "endfunc")
                file << "end\\n";

            else
                file << instr.result << " = "
                     << instr.arg1 << " "
                     << instr.operation << " "
                     << instr.arg2 << "\\n";
        }

        file << "\"];\n\n";
    }

    for (auto &b : blocks) {
        for (auto s : b.successors) {

            file << "B" << b.id
                 << " -> B"
                 << s
                 << ";\n";
        }
    }

    file << "\n}\n";

    file.close();
}