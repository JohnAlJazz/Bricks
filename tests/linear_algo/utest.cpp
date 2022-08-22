#include "linear_algo.hpp"
#include <iterator>
#include <vector>
#include <list>
#include "mu_test.h"
#include <assert.h>


BEGIN_TEST(t1)
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
Print(v);
ASSERT_PASS();
END_TEST


BEGIN_TEST(t2)
std::vector<double> vec;
vec = CreateChaos(10);
Print(vec);
ASSERT_PASS();
END_TEST

BEGIN_TEST(sum)
std::vector<int> vec = {1, 2, 3, 4, 5};
int sum = Sum(vec);
ASSERT_THAT(sum == 15);
END_TEST

BEGIN_TEST(sum2)
std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};
double sum = Sum(vec);
ASSERT_THAT(sum == 16.15);
END_TEST


BEGIN_TEST(aboveAvg)
std::vector<int> vec = {3, 7, 1, 6, 8};
int above = CountAboveAverage(vec);
ASSERT_THAT(above == 3);
END_TEST


BEGIN_TEST(aboveAvg2)
std::list<int> lst = {3, 7, 1, 6, 8};
int above = CountAboveAverage(lst);
ASSERT_THAT(above == 3);
END_TEST


BEGIN_TEST(oddsOut)
std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
OddsOut(vec);
ASSERT_THAT(vec.size() == 5);
END_TEST

BEGIN_TEST(extreme)
std::vector<int> vec = {3, 4, 5, 6, 7, 8};
MinMax<int> m = Extreme(vec);
// m.m_max = 12;
ASSERT_THAT(m.m_min == 3 && m.m_max == 8);
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	// TEST(t1)
    // TEST(t2)
    // TEST(sum)
    // // TEST(sum2)
    // TEST(aboveAvg)
    // TEST(aboveAvg2)
    TEST(oddsOut) 
    TEST(extreme)    		
END_SUITE




