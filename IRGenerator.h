#ifndef IRGENERATOR_H
#define	IRGENERATOR_H

#include <iostream>
#include "IR.h"
#include "Node.h"
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

class IRGenerator {
private:
    vector<TAC> instructions;
    int temp_count = 0;
    int label_count = 0;
    stack<string> loop_end_labels;
public:
    string new_temp();

    string new_label();

    void emit(string result, string arg1, string op, string arg2);

    string gen_expr(Node* node);

    void gen_stmt(Node* node);

    vector<basic_block> build_basic_blocks();
    void build_cfg(vector<basic_block>& blocks);

    void execute(Node* root);

    void gen_if(Node* node);
    void gen_assign(Node * node);
    void gen_print(Node* node);
    void gen_return(Node* node);
    void gen_for(Node* node);
    void gen_break(Node * node);
    void gen_read(Node* node);
    void gen_function(Node* node);

    void print_TAC();


    void generate_dot(vector<basic_block>& blocks);

};

#endif