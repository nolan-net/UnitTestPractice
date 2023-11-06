/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, single_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, repeating_letters_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("AAABBB");
    ASSERT_EQ(3, actual);
}

/*
	Test if password has upper and lower
*/

TEST(PasswordTest, upper_and_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_TRUE(1, actual);
}
/*
	Test if password has upper and lower with numbers
*/
TEST(PasswordTest, upper_and_lower_with_numbers)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aA1");
	ASSERT_TRUE(actual);
}

/*
	Test if password has no letters but numbers and symbols
*/

TEST(PasswordTest, no_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1234^!@#$");
	ASSERT_TRUE(actual);
}

/*
	Test if Password has letters, numbers, and symbols
*/
TEST(PasswordTest, letters_numbers_symbols)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aA1!@#$");
	ASSERT_TRUE(actual);
}
