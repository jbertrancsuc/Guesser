/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

// correct match
TEST(GuesserTest, correct_match)
{
  Guesser object("MYSECRET");
  int val = object.match("MYSECRET");
  ASSERT_EQ( 1, val );
}

// incorrect match less than 2
TEST(GuesserTest, decrease_guess_test)
{
  Guesser object("MYSECRET");
  int val = object.match("MYSECRETZ");
  ASSERT_EQ( 0, val );
}

// incorrect match greate than 2
TEST(GuesserTest, locked_account)
{
  Guesser object("MYSECRET");
  int val = object.match("MYSECRETABC");
  ASSERT_EQ( 0, val );
}


//	differecne greater than 2
// and a guess again  till
TEST(GuesserTest, locked_account_2)
{
  Guesser object("MYSECRET");
  int val = object.match("MYSECRETABC");

  // retuns false since account is locked
  int val2 = object.match("MYSECRETABCD");
  ASSERT_EQ( 0, val2 );
}

TEST(GuesserTest, locked_account_3)
{
  Guesser object("MYSECRET");
  int val = object.match("MYSECRETA");

  // retuns false since account is locked
  int val2 = object.match("MYSECRETB");
  int val3 = object.match("MYSECRETC");
  ASSERT_EQ( 0, val3 );
}


// DISTANCE TESTS - 3 - 
TEST(GuesserTest, distance_test)
{
  Guesser object("JEREMY");
  int val = object.distance("JEREMYABC");

  ASSERT_EQ( 3, val);
}
// 13 Char - DISSTANCE 10
TEST(GuesserTest, distance_test_2)
{
  Guesser object("JEREMYBERTRAN");
  int val = object.distance("JER");

  ASSERT_EQ( 10, val);
}
// BIGGER GUESS, max num is object val
TEST(GuesserTest, distance_test_3)
{
  Guesser object("WORM");
  int val = object.distance("JEREMYBERTRANISTHEBEST");

  ASSERT_EQ( 4, val);
}

// substr secret should trim string

TEST(GuesserTest, constructor_test)
{
  Guesser object("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFG");
  int val = object.match("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEF");

  ASSERT_EQ( 1, val);
}

TEST(GuesserTest, constructor_test_2)
{
  Guesser object("");
  int val = object.match("");

  ASSERT_EQ( 1, val);
}