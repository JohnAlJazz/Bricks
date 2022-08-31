#ifndef MACHINE_CODE_SEGMENT_H__
#define MACHINE_CODE_SEGMENT_H__

#include <vector>
#include <cstdint>

namespace machineStack{

class CodeSegment {
public:
    CodeSegment() = delete;
    CodeSegment(std::vector<int64_t> a_code);
    CodeSegment(const CodeSegment& a_other) = default;
    CodeSegment& operator=(CodeSegment& a_other) = default;
    ~CodeSegment() = default;

    void MoveIndex(int64_t a_num);
    int64_t Read();
    // int64_t const Index();
    bool IsProgramEnded();

private:
    std::vector<int64_t> m_codeSegment;
    int64_t m_index;
};

#include "inl/machine_code_segment.hxx"

}
#endif //MACHINE_CODE_SEGMENT_H__