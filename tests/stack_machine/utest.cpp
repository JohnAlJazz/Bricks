#include "mu_test.h"
#include "machine_vm.hpp"
#include <vector>

using namespace machineStack;


BEGIN_TEST(vm)
    std::vector<int64_t> vec{0, 1, 2, 3, 4, 5, 6, 7};
    std::stack<int64_t> stack{};
    MachineVm mVm(vec, stack, 10);
    mVm.Run();
    ASSERT_EQUAL(mVm.Top(), 3);
    ASSERT_PASS();
END_TEST



BEGIN_SUITE(tests)
	TEST(vm)
    
END_SUITE



