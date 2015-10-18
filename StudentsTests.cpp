/*
 *  Assignment 4   GoogleTests 
 *
 *  Name           Calvin Chhour, Van Dy
 *  Date           October 9,2015
 *
 *  A file that will run a test to check the functionality of 
 *  Students.cpp. Uses Googletest library.
 */

#include "gtest/gtest.h"
#include "Students.h"

int main (int argc, char** argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
 * Tests functionality of addUser and numberOfNames
 */
TEST(StudentTest, addUser) 
{	
	Students* stu = new Students();
    	stu->addUser("Van", 12345);
    	EXPECT_EQ(1, stu->numberOfNames());
    	stu->addUser("Calvin", 6789);
    	EXPECT_EQ(2, stu->numberOfNames());
}


/*
 *   Tests functionality of addUser and what happens when you add two of the same 
 *   name to a map. Logically, you could have the name stored twice with two 
 *   different id's but a map wouldn't allow for that so it should erase the 
 *   previous ID value "12345"
 *
 *   
 */
TEST(StudentTest, mapTest)
{
        Students* stu = new Students();
        stu->addUser("Van", 12345);
        EXPECT_EQ(1, stu->numberOfNames());
        stu->addUser("Van", 6789);
        // Ideally, we should see Van match both but it will likely override and fail the test.
	EXPECT_EQ(12345, stu->idForName("Van"));
}

/*
 *  Tests functionality of idForName
 *  Possible error in idForName
 *
 *  Appears to be returning an address? 
 */

TEST(StudentTest, idForName)
{	
	Students* stu = new Students();
   	 
	stu->addUser("Van", 12345);
    	EXPECT_EQ(12345, stu->idForName("Van"));
    	stu->addUser("Calvin", 6789);
    	EXPECT_EQ(6789, stu->idForName("Calvin"));
}

/*
 *  Tests functionality of idForName checking negative into unsigned
 *  Possible error in idForName
 */

TEST(StudentTest, idForNameNegative)
{
        Students* stu = new Students();

        stu->addUser("Van", -12345);
        EXPECT_EQ(-12345, stu->idForName("Van"));
        stu->addUser("Calvin", -6789);
        EXPECT_EQ(-6789, stu->idForName("Calvin"));
}


/*
 *  Tests functionality of idForName with an unsigned int
 *  Possible error in idForName
 */

TEST(StudentTest, idForNameTest)
{
        Students* stu = new Students();

	unsigned int a = 12345;
	unsigned int b = 6789;
        stu->addUser("Van", a);
        EXPECT_EQ(a, stu->idForName("Van"));
        stu->addUser("Calvin", b);
        EXPECT_EQ(b, stu->idForName("Calvin"));
}


/*
 *  Tests functionality of addPhoneNumbers and phoneForName
 */
TEST(StudentTest, addPhoneNumbers) 
{
	Students* stu = new Students();
    	stu->addUser("Van", 12345);
    	stu->addUser("Calvin", 6789);
    	stu->addPhoneNumbers(12345, "801-560-6870");
    	stu->addPhoneNumbers(6789, "801-555-5555");
    	EXPECT_EQ("801-560-6870", stu->phoneForName("Van"));
    	EXPECT_EQ("801-555-5555", stu->phoneForName("Calvin"));
}

/*
 * Tests functionality of addGrade and gradeForName
 */
TEST(StudentTest, addGrade) 
{
	Students* stu = new Students();
   	stu->addUser("Van", 12345);
    	stu->addUser("Calvin", 6789);
    	stu->addGrade(12345, 'a');
    	stu->addGrade(6789, 'b');
    	EXPECT_EQ('a', stu->gradeForName("Van"));
    	EXPECT_EQ('b', stu->gradeForName("Calvin"));
 }

/*
 *  Tests functionality for nameExists
 */ 
TEST(StudentTest, nameExists)
{
	Students* stu = new Students();
    	stu->addUser("Van", 12345);
    	stu->addUser("Calvin", 6789);
    	EXPECT_EQ(true, stu->nameExists("Van"));
    	EXPECT_EQ(true, stu->nameExists("Calvin"));
    	EXPECT_EQ(false, stu->nameExists("Trent"));
}

/*
 *  Tests functionality of fullRecord
 */
TEST(StudentTest, fullRecord)
{
	Students* stu = new Students();
  	stu->addUser("Van", 123);
  	stu->addPhoneNumbers(123, "801-560-6870");
  	stu->addGrade(123, 'a');
	std::string name = "Van";
	std::string number = "801-560-6870";
 	unsigned int id = 123;
	char a = 'a';
	EXPECT_EQ(true, stu->fullRecord(name, id,number, a));
}

/*
 *  Tests functionality of removeStudents
 */
TEST(StudentTest, removeStudent) 
{
	Students* stu = new Students();
  	stu->addUser("Van", 123);
  	EXPECT_EQ(1, stu->numberOfNames());
  	stu->removeStudent("Van");
  	EXPECT_EQ(0, stu->numberOfNames());
}

/*
 *  Tests functionality of removeList
 */ 
TEST(StudentTest, removeList)
{
	Students* stu = new Students();
  	stu->addUser("Van", 123);
  	stu->addUser("Calvin", 321);
  	stu->addUser("Random",1244);
	stu->addUser("Name",1222);
	std::vector<std::string> list;
  	list.push_back("Van");
  	list.push_back("Calvin");
        list.push_back("Random");
        list.push_back("Name");	
	EXPECT_EQ(4, stu->numberOfNames());
	stu->removeList(list);
	EXPECT_EQ(0, stu->numberOfNames());
}

/*
 * Tests functionality of clearAll
 */
TEST(StudentTest, clearAll)	
{
	Students* stu = new Students();
  	stu->addUser("Van", 123);
  	stu->addUser("Calvin", 321);
  	EXPECT_EQ(2, stu->numberOfNames());
  	stu->clearAll();
  	EXPECT_EQ(0, stu->numberOfNames());
}
