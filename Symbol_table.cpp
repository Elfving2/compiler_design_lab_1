#include "Symbol_table.h"

    void Symbol_table::pre_order(Node * root) {
        if (root == nullptr) return;

        cout << endl;
        cout << "id -> " << root->id << endl;
        cout << "Type -> " << root->type << endl;
        cout << "value -> " << root->value << endl;
        cout << endl;

        for (Node * child : root->children) pre_order(child);
    }


    void Symbol_table::post_order(Node * root) {
        if (root == nullptr) return;
        for (Node* child : root->children) post_order(child);

        cout << endl;
        cout << "id -> " << root->id << endl;
        cout << "Type -> " << root->type << endl;
        cout << "value -> " << root->value << endl;
        cout << endl;
    }

    void Symbol_table::execute(Node * root) {

    }
