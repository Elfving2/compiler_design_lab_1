#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "Node.h"
#include "Symbol.h"
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Symbol_table {
    private:
        Scope* global_scope;
        Scope* current_scope;
        list<string> errors;
        Symbol * Class_s(Symbol * &symPtr, Node * root);
        Symbol * Method_s(Symbol * &symPtr, Node * root);
        Symbol * Variable_s(Symbol * &symPtr, Node * root);
        Symbol * Assign_s(Symbol * &symPtr, Node * root);
        Symbol * Return_s(Symbol * &symPtr, Node * root);
        Symbol * Print_s(Symbol * &symPtr, Node * root);
        Symbol * Main_s(Symbol * &symPtr, Node * root);
        Symbol * Read_s(Symbol * &symPtr, Node * root);
        Symbol * For_s(Symbol * &symPtr, Node * root);
        string build_expr(Node* node, int parentPrec);
        int precedence(const string& type);


    public:
        Scope * get_global_scope();
        Symbol_table();
        void traverse(Node * root);
        void execute (Node * root);
        void enter_scope(Symbol * s);
        void leave_scope();
        void print_scope(Scope* scope, int indent = 2);
        void indentation(int indent);
        void print();
        void print_errors();
        Symbol* lookup(const string& name);
};


#endif