#include "mu_test.h"
#include "pointer.hpp"

#include <assert.h>
#include <iostream>


BEGIN_TEST(smart_pointer)
using namespace pointer;
int* p = new int(10);
Pointer<int> ptr(p);
ASSERT_EQUAL(*ptr, 10);
ASSERT_PASS();
END_TEST

BEGIN_TEST(smart_pointer2)
using namespace pointer;
int* p = new int(10);
Pointer<int> ptr(p);
*ptr = 2;
ASSERT_EQUAL(*p, 2);
ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(smart_pointer)
	TEST(smart_pointer2)
    		
END_SUITE