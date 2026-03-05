#ifndef SYMBOL_H
#define SYMBOL_H
#include <vector>
#include <map>
using namespace std;

// https://medium.com/@pawan2505/understanding-structures-in-c-programming-ec638f710e6d

enum Kind {
    CLASS,
    METHOD,
    VARIABLE,
    MAIN,
    PARAMETER,
};

struct Symbol {
    string identifier;
    string type;
    virtual void print() {
        cout << type << " : " << identifier;
    }
    virtual ~Symbol() = default;
};


struct Scope {
    map<string, Symbol*> symbols;
    vector<Symbol*> ordered_symbols;
    Scope* parent;
    vector<Scope*> children;
    Symbol * scope_name;
};

struct Class_symbol : Symbol {
    void print() override {
        Symbol::print();
        cout << endl;
    }
};

struct Variable_symbol : Symbol {
    bool isVolatile = false;
    //list<string> value;
    string value;
    void print() override {
        if (isVolatile) {
            cout << "Volatile "; 
            Symbol::print();
            cout << " : " << value << endl;
        }
        else {
            Symbol::print();
            cout << " : " << value << endl;
        }
    }

};


struct Assign_symbol : Symbol {
    string value;
    void print() override{
        cout << Symbol::identifier << " : " << value << endl;
    }
};



struct Method_symbol : Symbol {
    vector<string> parameters;

    void print() override {
        cout << Symbol::identifier << "(";
        for (int i = 0; i < parameters.size(); i++) {
            if (i + 1 == parameters.size()) cout << parameters[i];
            else cout << parameters[i] << ", ";
        }
        cout << ")";
        cout << " : " << Symbol::type << endl;
    }
};



#endif