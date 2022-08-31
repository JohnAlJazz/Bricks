#include "mu_test.h"
#include "machine_vm.hpp"
#include "machine_compiler.hpp"
#include <vector>
#include <fstream>


using namespace machineStack;


BEGIN_TEST(NOP)
    std::vector<int64_t> vec{0};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 4);
    ASSERT_PASS();
END_TEST

BEGIN_TEST(ADD)
    std::vector<int64_t> vec{1};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 6);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(IN)
    std::vector<int64_t> vec{7};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 6);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(OUT)
    std::vector<int64_t> vec{8};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    // ASSERT_EQUAL(mVm.Top(), 6);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(LOAD)
    std::vector<int64_t> vec{9};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 0);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(STOR)
    std::vector<int64_t> vec{10};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.GetMemory(4), 2);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(JMP)
    std::vector<int64_t> vec{11, 0, 0, 0, 1};
    std::stack<int64_t> stack{};
    std::stack<int64_t> stackIp{};
    MachineVm mVm(vec, stack, 10, stackIp);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 3);
    ASSERT_PASS();
END_TEST


BEGIN_TEST(compiler)    
    MachineCompiler mComp;
    std::vector<int64_t> compiledFile = mComp.Compile("code");
    std::vector<int64_t> vec{1};
    std::stack<int64_t> stack{};       
    ASSERT_PASS();
    
    ASSERT_PASS();
END_TEST

BEGIN_SUITE(tests)
	TEST(NOP)
    TEST(ADD)
    TEST(IN)
    TEST(OUT)
    TEST(LOAD)
    TEST(STOR)
    TEST(JMP)
    TEST(compiler)
END_SUITE



