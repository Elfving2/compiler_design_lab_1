#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "Node.h"
using namespace std;

class Symbol_table {
    private:
        
    public:
        void pre_order(Node * root);
        void post_order(Node * root);
        void execute (Node * root);
};


#endif