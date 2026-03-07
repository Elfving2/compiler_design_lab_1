#ifndef SYMBOL_H
#define SYMBOL_H
#include <vector>
#include <map>
using namespace std;

// https://medium.com/@pawan2505/understanding-structures-in-c-programming-ec638f710e6d

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
    string index;
    void print() override{
        cout << Symbol::identifier << index << " : " << value << endl;
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

struct Print_symbol : Symbol {
    string value;

    void print() override {
        cout << "print"<< "(" << value << ")" << endl;
    }

};

struct Return_symbol : Symbol {
    string value;

    void print() override {
        cout << "return" << " " << value << endl;
    }
};

struct Main_symbol : Symbol {

    void print() override {
        cout << "Main()" << ":" << Symbol::type << endl;
    }
};

struct Read_symbol : Symbol {
    string value;

    void print() override {
        cout << "read"<< "(" << value << ")" << endl;
    }

};

struct For_symbol : Symbol {
    string part1;
    string part2;
    string part3;

    void print() override {
        cout << "for"<< "(" << part1 << ", "  << part2 << ", " << part3 << ")" << endl;
    }

};

struct If_symbol : Symbol {
    string part1;
    string op;
    string part2;
    void print() override {
        cout << "if(" << part1 << op << part2 <<")" << endl;
    }

};

struct Comment_symbol : Symbol {
    void print() override {
        cout << "Comment : " << Symbol::identifier << endl;
    }

};

struct Else_symbol : Symbol {
    void print() override {
        cout << "else" << endl;
    }
};

struct Break_symbol : Symbol {
    void print() override {
        cout << Symbol::identifier << endl;
    }
};

#endif