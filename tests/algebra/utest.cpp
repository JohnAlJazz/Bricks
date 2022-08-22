#include "mu_test.h"


#include "algebra.hpp"

BEGIN_TEST(add_two_small_integers_test)
	int a = 42;
	int b = 3;
	int r = add(a, b);
	
	ASSERT_THAT( r > a);
	ASSERT_THAT( r > b);
	ASSERT_EQUAL(r, a+b);	
END_TEST

BEGIN_TEST(add_two_small_opposite_integers_test)
	int a = 42;
	int b = -a;
	int r = add(a, b);		
	
	ASSERT_EQUAL(r, 0);

	// ASSERT_EQUAL(a, b);
	ASSERT_NOT_EQUAL(a, b);
	// ASSERT_THAT( a > b);
	// ASSERT_PASS();
	// ASSERT_FAIL("panic");

	// if( r >= 0){
	// 	ASSERT_PASS();
	// }else{
	// 	ASSERT_FAIL("panic");
	// }
	

END_TEST

BEGIN_TEST(add_two_big_integers_test)
	int a = 298342894;
	int b = 238904789;
	int r = add(a, b);
	
	ASSERT_THAT( r > a);
	ASSERT_THAT( r > b);
	ASSERT_EQUAL(r, a+b);
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(add_two_small_integers_test)
	TEST(add_two_small_opposite_integers_test)
	TEST(add_two_big_integers_test)
END_SUITE
