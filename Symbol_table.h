#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "Node.h"
using namespace std;

class SymbolTable {
    private:
        
    public:
        void pre_order(Node * root) {
            if (root == nullptr) return;
            
                cout << endl;
                cout << "id -> " << root->id << endl;
                cout << "Type -> " << root->type << endl;
                cout << "value -> " << root->value << endl;
                cout << endl;

            for (Node * child : root->children) pre_order(child);
            
        }

        void post_order(Node * root) {
            if (root == nullptr) return;
            for (Node* child : root->children) post_order(child);

            cout << endl;
            cout << "id -> " << root->id << endl;
            cout << "Type -> " << root->type << endl;
            cout << "value -> " << root->value << endl;
            cout << endl;
        }


        void execute (Node * root) {
            
        }
};


#endif