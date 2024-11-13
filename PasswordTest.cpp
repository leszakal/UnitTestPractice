/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Mixed case tests
TEST(PasswordTest, all_lowercase_alpha) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("super secure password");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, all_uppercase_alpha) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, all_lowercase_alphanumeric) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("sup3r s3cur3 passw0rd");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, all_uppercase_alphanumeric) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("PASSWORD123");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, mixedcase_alpha) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("Password");
	ASSERT_TRUE(has_mixed);
}

TEST(PasswordTest, mixedcase_alphanumeric) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("Sup3r s3cur3 Passw0rd");
	ASSERT_TRUE(has_mixed);
}


TEST(PasswordTest, all_lowercase_symbols_alphanum) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, all_uppercase_symbols_alphanum) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("P@SSW0RD!");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, mixed_case_symbols_alphanum) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("Sup3r s3cur3 P@ssw0rd!");
	ASSERT_TRUE(has_mixed);
}

TEST(PasswordTest, blank_password) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, spaces_only) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("    ");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, single_letter_uppercase) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("A");
	ASSERT_FALSE(has_mixed);
}

TEST(PasswordTest, single_letter_lowercase) {
	Password my_password;
	bool has_mixed = my_password.has_mixed_case("a");
	ASSERT_FALSE(has_mixed);
}

// Leading characters tests
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, four_identical_ints)
{
        Password my_password;
        int actual = my_password.count_leading_characters("0000");
        ASSERT_EQ(4, actual);
}
TEST(PasswordTest, single_nonletter_char)
{
        Password my_password;
        int actual = my_password.count_leading_characters("*");
        ASSERT_EQ(1, actual);
}
TEST(PasswordTest, double_alternating_caps)
{
        Password my_password;
        int actual = my_password.count_leading_characters("AaAa");
        ASSERT_EQ(1, actual);
}
