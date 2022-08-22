#include "mu_test.h"
#include "rational.hpp"
#include <assert.h>


BEGIN_TEST(t1)
experis::Rational ratio(2);
ASSERT_THAT(ratio.GetNumerator() == 2 && ratio.GetDenominator() == 1);
END_TEST

BEGIN_TEST(t2)
experis::Rational ratio(2, 3);
ASSERT_THAT(ratio.GetNumerator() == 2 && ratio.GetDenominator() == 3);
END_TEST

BEGIN_TEST(t3)
experis::Rational ratio(2, 2);
ASSERT_THAT(ratio.GetNumerator() == 1 && ratio.GetDenominator() == 1);
END_TEST

BEGIN_TEST(t4)
experis::Rational ratio(6, 8);
ASSERT_THAT(ratio.GetNumerator() == 3 && ratio.GetDenominator() == 4 && ratio.GetRational() == 3 / 4);
END_TEST

BEGIN_TEST(t7)
experis::Rational ratio(8, 6);
ASSERT_THAT(ratio.GetNumerator() == 4 && ratio.GetDenominator() == 3 && ratio.GetRational() == 4 / 3);
END_TEST

BEGIN_TEST(t5)
experis::Rational ratio(6, 8);
ratio.SetNumerator(3);
ASSERT_THAT(ratio.GetRational() == 9 / 24);
END_TEST

BEGIN_TEST(t6)
experis::Rational ratio(6, 8);
experis::Rational ratio2(1, 2);
experis::Rational ratio3 = ratio + ratio2;
ASSERT_THAT(ratio3.GetRational() == 5 / 4);
END_TEST

BEGIN_TEST(t8)
experis::Rational ratio(6, 8);
experis::Rational ratio2(1, 2);
experis::Rational ratio3 = ratio - ratio2;
ASSERT_THAT(ratio3.GetRational() == 1 /4);
END_TEST

BEGIN_TEST(t9)
experis::Rational ratio(6, 8);
experis::Rational ratio2(1, 2);
experis::Rational ratio3 = ratio * ratio2;
ASSERT_THAT(ratio3.GetRational() == 3 / 8);
END_TEST

BEGIN_TEST(t10)
experis::Rational ratio(2, 4);
experis::Rational ratio2(1, 2);
experis::Rational ratio3 = ratio / ratio2;
ASSERT_THAT(ratio3.GetRational() == 1 / 1);
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(t1)
	TEST(t2)
	TEST(t3)
	TEST(t4)
	TEST(t5)
	TEST(t6)
	TEST(t7)	
	TEST(t8)
	TEST(t9)
	TEST(t10)
END_SUITE