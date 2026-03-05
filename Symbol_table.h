#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "Node.h"
#include "Symbol.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Symbol_table {
    private:
        Scope* global_scope;
        Scope* current_scope;
        list<string> errors;
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