#ifndef CODEGENERATOR_H
#define	CODEGENERATOR_H

#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include "IRGenerator.h"

using namespace std;

class CodeGenerator
{

public:
    void generate(std::vector<basic_block>& blocks);

private:
    set<int> visited;
    void visit_block(int id, vector<basic_block>& blocks, ofstream& file);
    void generate_instruction(TAC& instr, ofstream& file);

    void declare_variables(ofstream& file);
};
#endif