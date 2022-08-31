#include "machine_compiler.hpp"
#include "machine_opCodes.hpp"


#include <fstream>

namespace machineStack{

typedef std::map<std::string, int64_t> Parser;

static void InitOpCodes(Parser& a_parser) {    

    a_parser["NOP"] = NOP;  
    a_parser["ADD"] = ADD;    
    a_parser["SUB"] = SUB;   
    a_parser["AND"] = AND;    
    a_parser["OR"] = OR;    
    a_parser["XOR"] = XOR;    
    a_parser["NOT"] = NOT;    
    a_parser["IN"] = IN;      
    a_parser["OUT"] = OUT;     
    a_parser["LOAD"] = LOAD;     
    a_parser["STOR"] = STOR;      
    a_parser["JMP"] = JMP;         
    a_parser["JZ"] = JZ;        
    a_parser["PUSH"] = PUSH;         
    a_parser["DUP"] = DUP;    
    a_parser["SWAP"] = SWAP;     
    a_parser["ROL3"] = ROL3;    
    a_parser["OUTNUM"] = OUTNUM;     
    a_parser["INNUM"] = INNUM;          
    a_parser["JNZ"] = JNZ;    
    a_parser["DROP"] = DROP;     
    a_parser["COMPL"] = COMPL;    
    a_parser["HLT"] = HLT;   
    a_parser["PUSHIP"] = PUSHIP;    
    a_parser["POPIP"] = POPIP;   
    a_parser["DROPIP"] = DROPIP;    
}

static Parser InitParser(std::ifstream& a_code) {
    int64_t counter = 0;
    std::string string;
    Parser parser;

    while(! a_code.eof()) {
        a_code >> string;       

        if(string.back() == ':') {
            string.pop_back();
            parser.insert({string, counter});
        }
        else {
         ++counter;
        }
    }
    InitOpCodes(parser);  
    return parser;  
}

static const std::vector<int64_t> Parse(std::ifstream& a_code, const Parser& a_parser) {
    
    std::vector<int64_t> program;
    std::string word;
    Parser::const_iterator end = a_parser.end();
    while(! a_code.eof()) {
        a_code >> word;
        if(word.back() != ':') {
            Parser::const_iterator it = a_parser.find(word);
               
            if(it == end) {
                throw CompilerExceptions("Parse()", "requested key wasn't found");
            }

            int64_t value = it->second;
            program.push_back(value);

            if(it->first == "PUSH") {
                a_code >> word;
                int64_t num = std::stol(word);
                program.push_back(num);
            }
        }            
    } 
    return program;
}

const std::vector<int64_t> MachineCompiler::Compile(std::string const& a_stream) {    
    
    std::ifstream code(a_stream);
    Parser parser = InitParser(code);   
    code.clear();

    code.seekg(0); 
    return Parse(code, parser);
}


} //machineStack