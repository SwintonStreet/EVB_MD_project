#include <string>

#include <gtest/gtest.h>

#include "readlib.h"

TEST(readDoubleTests, rightValues)
{
    ASSERT_EQ(8.4, readlib::readDOU("8.4", ""));
    ASSERT_EQ(-96, readlib::readDOU("-96", ""));
    ASSERT_EQ(123, readlib::readDOU("123", ""));
}

TEST(readBooleanTests, rightValues)
{
    ASSERT_EQ(true, readlib::readBOO("Y", ""));
    ASSERT_EQ(false, readlib::readBOO("N", ""));
}

TEST(readIntegerTests, rightValues)
{
    ASSERT_EQ(123, readlib::readINT("123", ""));
    ASSERT_EQ(-45, readlib::readINT("-45", ""));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
