#include "isSorted.hpp"
#include "mu_test.h"
#include <vector>
#include <list>


BEGIN_TEST(sorted_test)
std::vector<int> v = {1, 2, 3, 4, 5};
ASSERT_THAT(IsSorted(v) == 1);
END_TEST

BEGIN_TEST(sorted_test2)
std::list<int> lst = {1, 22, 31, 4, 5};
ASSERT_THAT(IsSorted(lst) == 0);
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(sorted_test)
    TEST(sorted_test2)
         		
END_SUITE




