#include "gray_image.hpp"
#include "graphs.hpp"
#include "mu_test.h"
#include <vector>

typedef gfx::GrayImage GrayImage;

BEGIN_TEST(line_test)
Point p1(0, 0);
Point p2(250, 250);
Line l(p1, p2);
GrayImage img(500, 500);
l.Draw(img, 10 ,15);
ASSERT_PASS();
END_TEST

BEGIN_TEST(line_test2)
Point p1(34, 55), p2(55, 300);
Line l(p1, p2);
GrayImage img(400, 400);
l.Draw(img, 5, 15);
ASSERT_PASS();
END_TEST

BEGIN_TEST(circle)
Point p(15, 15);
GrayImage img(30, 40);
Circle c(10, p);
c.Draw(img, 1, 15);
ASSERT_PASS();
END_TEST

BEGIN_TEST(square)
Point p(34, 200);
Square sqr(p, 120);
GrayImage img(500, 400);
sqr.Draw(img, 10, 15);
ASSERT_PASS();
END_TEST


BEGIN_TEST(complexShape)
GrayImage img(500, 500, 15, 0);
Point p1(0, 3), p2(30, 65), p3(100, 54), p4(44, 100);
Line l1(p1, p2), l2(p1, p3), l3(p4, p2), l4(p3, p4);
std::vector<Line> lines{l1, l2, l3, l4};
Circle c1(10, p1), c2(30, p2), c3(10, p3), c4(54, p4), c5(20, p1), c6(19, p4);
std::vector<Circle> circles{c1, c2, c3, c4, c5, c6};
Square s1(p2, 200), s2(p1, 44), s3(p4, 98), s4(p3, 100);
std::vector<Square> squares{s1, s2 ,s3, s4};
ComplexShape cs(lines, circles, squares);
cs.Draw(img, 3, 15);
ASSERT_PASS();
END_TEST


BEGIN_TEST(complexShape2)
GrayImage img(500, 500, 15, 0);
Point p1(0, 0), p2(499, 499), p3(100, 54), p4(440, 2);
Line l1(p1, p2), l2(p1, p3), l3(p1, p4), l4(p3, p4);
std::vector<Line> lines{l1, l2, l3, l4};
Circle c1(10, p1), c2(30, p2), c3(10, p3), c4(54, p4), c5(20, p1), c6(19, p4);
std::vector<Circle> circles{};//c1, c2, c3, c4, c5, c6};
Square s1(p3, 20), s2(p3, 44), s3(p4, 10), s4(p3, 100);
std::vector<Square> squares{s1, s2, s3, s4};
ComplexShape cs(lines, circles, squares);
cs.Draw(img, 10, 15);
ASSERT_PASS();
END_TEST


BEGIN_TEST(house)
GrayImage img(500, 500, 15, 0);
Point p1(125, 250), p2(250, 125), p3(125, 242), p4(375, 250), p5(190, 350), p6(190, 498),
p7(300, 350), p8(300, 498), p10(190, 350), p11(300, 350), p12(310, 280), p13(150, 110), p14(150, 218),
p15(180, 110), p16(180, 193), p17(150, 110), p18(180, 110), p19(165, 90), p20(165, 57), p21(165, 33) ;
Line l1(p3, p2), l2(p2, p4), l3(p5, p6), l4(p7, p8), l5(p10, p11), l6(p13, p14), l7(p15, p16), l8(p17, p18);
std::vector<Line> lines{l1, l2, l3, l4, l5, l6, l7, l8};
Circle c1(15, p19), c2(10, p20), c3(7, p21);
std::vector<Circle> circles{c1, c2, c3};
Square s1(p1, 245), s2(p12, 33);
std::vector<Square> squares{s1, s2};
ComplexShape cs(lines, circles, squares);
cs.Draw(img, 5, 15);
cs.Erase(img);
ASSERT_PASS();
END_TEST


BEGIN_TEST(lineErase)
Point p1(0, 0), p2(250, 250);
Line l(p1, p2);
GrayImage img(500, 500);
l.Draw(img, 10 ,15);
l.Erase(img);
ASSERT_PASS();
END_TEST



BEGIN_SUITE(tests)
	TEST(line_test)
    TEST(line_test2)
    TEST(circle)
    TEST(square)
    TEST(complexShape)
    TEST(complexShape2)
    TEST(house)
    TEST(lineErase)
END_SUITE




