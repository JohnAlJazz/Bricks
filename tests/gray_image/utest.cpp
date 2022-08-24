#include "gray_image.hpp"
#include "mu_test.h"

typedef experis::gfx::GrayImage GrayImage;

BEGIN_TEST(create_image)
GrayImage img(400, 300);
ASSERT_EQUAL(img.GetHeight(), 300);
ASSERT_EQUAL(img.GetWidth(), 400);
ASSERT_THAT(img.GetColorDepth() == 15 && img.GetPixelValue() == 15);
END_TEST

BEGIN_TEST(create_image2)
GrayImage img(400, 300, 255);
ASSERT_EQUAL(img.GetHeight(), 300);
ASSERT_EQUAL(img.GetWidth(), 400);
ASSERT_THAT(img.GetColorDepth() == 255 && img.GetPixelValue() == 255);
END_TEST

BEGIN_TEST(create_image3)
GrayImage img(400, 300, 255, 4);
ASSERT_EQUAL(img.GetHeight(), 300);
ASSERT_EQUAL(img.GetWidth(), 400);
ASSERT_THAT(img.GetColorDepth() == 255 && img.GetPixelValue() == 4);

END_TEST

BEGIN_TEST(clear)
GrayImage img(400, 300, 255, 4);
img.Clear(5);
ASSERT_THAT(img.GetPixelValue() == 5);
ASSERT_PASS();
END_TEST

BEGIN_TEST(EqOperator)
GrayImage img1(400, 300, 255, 4);
GrayImage img2(400, 300, 255, 4);
ASSERT_THAT(img1 == img2);
END_TEST

BEGIN_TEST(EqOperator2)
GrayImage img1(400, 300, 255, 4);
GrayImage img2(400, 300, 25, 5);
ASSERT_THAT(img1 != img2);
END_TEST


BEGIN_TEST(AndOperator)
GrayImage img1(10, 10, 15, 15), img2(10, 10, 15, 1), img3 = img1 & img2;
ASSERT_THAT(img3.GetPixelValue() == 1);
END_TEST


BEGIN_TEST(OrOperator)
GrayImage img1(10, 10, 15, 15), img2(10, 10, 15, 2), img3 = img1 | img2;
ASSERT_THAT(img3.GetPixelValue() == 15);
END_TEST


BEGIN_TEST(saveToFile)
GrayImage img(10, 10, 15, 11);
img.SaveImageToFile("test file");
ASSERT_PASS();
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(create_image)
    TEST(create_image2)
    TEST(create_image3)
     TEST(clear)
    TEST(EqOperator)
    TEST(EqOperator2)
    TEST(AndOperator)
    TEST(OrOperator)
    TEST(saveToFile)
     		
END_SUITE




