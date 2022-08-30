#include "mu_test.h"
#include "machine_vm.hpp"
#include <vector>

using namespace machineStack;


BEGIN_TEST(vm)
    std::vector<int64_t> vec = {1, 3, 0, 6, 9};
    MachineVm mVm(vec, 10);
    mVm.Run();
    ASSERT_PASS();
END_TEST






BEGIN_SUITE(tests)
	TEST(vm)
    
END_SUITE



