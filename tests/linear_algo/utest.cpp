#include "linear_algo.hpp"
#include <iterator>
#include <vector>
#include <list>
#include "mu_test.h"
#include <assert.h>


BEGIN_TEST(print)
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
Print(v);
ASSERT_PASS();
END_TEST


BEGIN_TEST(print2)
std::vector<int> v = {3};
Print(v);
ASSERT_PASS();
END_TEST


BEGIN_TEST(print3)
std::vector<int> v = {};
Print(v);
ASSERT_PASS();
END_TEST


BEGIN_TEST(randomD)
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
double delta = 16.15 - sum;
ASSERT_THAT(delta < 0.000001);
END_TEST


BEGIN_TEST(aboveAvg)
std::vector<int> vec = {3, 7, 1, 6, 8};
int above = CountAboveAverage(vec);
ASSERT_THAT(above == 3);
END_TEST


BEGIN_TEST(aboveAvg2)
std::list<int> lst = {3, 7, 1, 6, 8, 4, 6, 1, 45, 76};
int above = CountAboveAverage(lst);
ASSERT_THAT(above == 2);
END_TEST


BEGIN_TEST(oddsOut)
std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
OddsOut(vec);
ASSERT_THAT(vec.size() == 5);
END_TEST


BEGIN_TEST(oddsOut2)
std::vector<int> vec = {};
OddsOut(vec);
ASSERT_THAT(vec.size() == 0);
END_TEST


BEGIN_TEST(oddsOut3)
std::vector<int> vec = {2, 4, 6, 8, 10};
OddsOut(vec);
ASSERT_THAT(vec.size() == 5);
END_TEST


BEGIN_TEST(oddsOut4)
std::vector<int> vec = {1, 3, 5, 7, 9};
OddsOut(vec);
ASSERT_THAT(vec.size() == 0);
END_TEST

BEGIN_TEST(extreme)
std::vector<int> vec = {3, 4, 5, 6, 7, 89};
MinMax<int> m = Extreme(vec);
ASSERT_THAT(m.m_min == 3 && m.m_max == 89);
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(print)
    TEST(print2)
    TEST(print3)
    TEST(randomD)
    TEST(sum)
    TEST(sum2)
    TEST(aboveAvg)
    TEST(aboveAvg2)
    TEST(oddsOut)
    TEST(oddsOut2)
    TEST(oddsOut3) 
    TEST(oddsOut4)    
    TEST(extreme)    		
END_SUITE




