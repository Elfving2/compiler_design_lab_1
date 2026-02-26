#ifndef SYMBOL_H
#define SYMBOL_H
#include "Node.h"
using namespace std;

struct Symbol_base {
    String identifier;
    virtual ~Symbol_base() = default;
}

// https://medium.com/@pawan2505/understanding-structures-in-c-programming-ec638f710e6d

 
struct classSymbol : Symbol_base {

}


#endif