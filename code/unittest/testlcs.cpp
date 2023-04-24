#include <gtest/gtest.h>
#include <string>
#include "../src/dplib.h"

using namespace std;

TEST(TestLCS, Test1) {
    dplib  test;
    string input1 = "AGGTAB";
    string input2 = "GXTXAYB";
    int size1 = input1.length();
    int size2 = input2.length();
    int result = test.lcs(input1,input2,size1,size2);
    EXPECT_EQ(result, 4);
}

TEST(TestLCS, Test2) {
    dplib  test;
    string input1 = "AGGTAB";
    string input2 = "GXPXAYB";
    int size1 = input1.length();
    int size2 = input2.length();
    int result = test.lcs(input1,input2,size1,size2);
    EXPECT_EQ(result, 3);
}