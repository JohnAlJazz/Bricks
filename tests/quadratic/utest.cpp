#include "mu_test.h"
#include "rational.hpp"
#include "quadratic.hpp"
#include <assert.h>


BEGIN_TEST(t1)
experis::Rational r1(1, 3);
experis::Rational r2(7, 8);
experis::Rational r3(3, 5);
experis::Quadratic quad(r1, r2, r3);
ASSERT_THAT(r1.GetDenominator() == 3 && r1.GetNumerator() == 1 && r2.GetDenominator() == 8 && r2.GetNumerator() == 7);
quad.PrintPolynomial();
END_TEST

BEGIN_TEST(t2)
experis::Rational r1(1, 2);
experis::Rational r2(4, 9);
experis::Rational r3(3);
experis::Quadratic quad(r1, r2, r3);
experis::Roots roots;
ASSERT_THAT(r1.GetDenominator() == 2);
roots = quad.CalcRoots();
quad.PrintPolynomial();
TRACER << "num of roots: " << roots.m_numOfRoots << ". x1 = " << roots.m_x1 <<  " x2 = " << roots.m_x2;
END_TEST

BEGIN_TEST(t3)
experis::Rational r1(5);
experis::Rational r2(-9);
experis::Rational r3(-7);
experis::Quadratic quad(r1, r2, r3);
ASSERT_PASS();
quad.PrintPolynomial();
experis::Roots r = quad.CalcRoots();
TRACER << "num of roots: " << r.m_numOfRoots << ". x1 = " << r.m_x1 <<  " x2 = " << r.m_x2;
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(t1)
    TEST(t2)
    TEST(t3)		
END_SUITE