#ifndef IR_H
#define	IR_H

#include <string>
#include <vector>
using namespace std;


struct TAC {
    string result;
    string arg1;
    string operation;
    string arg2;
    
};

struct basic_block {
    int id;
    vector<TAC> instructions;
    vector<int> successors;
    
};

#endif