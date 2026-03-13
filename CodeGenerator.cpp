#include "CodeGenerator.h"

void CodeGenerator::generate(vector<basic_block>& blocks) {
    ofstream file("generatedCode.cpp");
    file << "#include <iostream>\n";
    file << "using namespace std;\n\n";

    file << "int main() {\n\n";

    // Start visiting blocks from vector of basic blocks from IRGenerator
    visit_block(0, blocks, file);

    file << "\n}\n";

    file.close();
}


void CodeGenerator::visit_block(int id, vector<basic_block>& blocks, ofstream& file)
{
    if (visited.count(id))
        return;

    visited.insert(id);

    basic_block &block = blocks[id];
    
    //cout << "L" << id << ":" << endl;
    file << "L" << id << ":" << endl;

    for (auto &instr : block.instructions)
        generate_instruction(instr, file);

    for (auto s : block.successors)
        visit_block(s, blocks, file);
}


void CodeGenerator::generate_instruction(TAC &instr, ofstream& file)
{
    if (instr.operation == "label")
    {
        file << instr.result << ":" << endl;
    }

    else if (instr.operation == "goto")
    {
        file << "goto " << instr.result << ";" << endl;
    }

    else if (instr.operation == "if")
    {
        file << "if (" << instr.arg1 << ") goto "
             << instr.result << ";" << endl;
    }

    else if (instr.operation == "print")
    {
        file << "cout << " << instr.arg1 << " << endl;" << endl;
    }

    else if (instr.operation == "read")
    {
        file << "cin >> " << instr.arg1 << ";" << endl;
    }

    else if (instr.operation == "return")
    {
        file << "return " << instr.arg1 << ";" << endl;
    }

    else if (instr.operation == "=")
    {
        file << instr.result << " = " << instr.arg1 << ";" << endl;
    }

    else
    {
        file << instr.result << " = "
             << instr.arg1 << " "
             << instr.operation << " "
             << instr.arg2 << ";" << endl;
    }
}