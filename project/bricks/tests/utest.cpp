#include "mu_test.h"
#include "game.hpp"
#include <iostream>
#include <fstream>


BEGIN_TEST(t1)
using namespace bricks;
Game game("test.txt");
game.Run();

ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(t1)
	
END_SUITE