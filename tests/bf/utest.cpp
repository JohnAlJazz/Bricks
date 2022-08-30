#include "mu_test.h"
#include "vm_bf.hpp"

typedef bf::VmBf Vm;

BEGIN_TEST(vm1)
    Vm vm("+++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ ++++++ ++++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++++.");
    vm.Run();
ASSERT_PASS();
END_TEST




BEGIN_SUITE(tests)
	TEST(vm1)
    
END_SUITE



