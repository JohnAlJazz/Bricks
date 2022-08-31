#ifndef MACHINE_COMPILER_H__
#define MACHINE_COMPILER_H__


#include "machine_exceptions.hpp"

#include <vector>
#include <map>
#include <cstdint>
#include <string>
#include <fstream>

namespace machineStack {

class MachineCompiler {
public:     
    MachineCompiler() = default;
    ~MachineCompiler() = default;
    MachineCompiler(const MachineCompiler& a_comp) = default;
    MachineCompiler& operator=(const MachineCompiler& a_comp) = default;

    const std::vector<int64_t> Compile(std::string const& m_stream);

private:
    
    // Parser InitParser(std::ifstream& a_code);
};

class CompilerExceptions : public AbstractSMError {
public:
    CompilerExceptions(const char* fn, const char* w) : AbstractSMError(fn, w){}
};


} //machineStack





#endif //MACHINE_COMPILER_H__