#include "gtest/gtest.h"
#include "Students.h"

int main (int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

TEST(StudentTest, addUser) {
    Students* stu = new Students();
    stu->addUser("Van", 12345);
    EXPECT_EQ(1, stu->numberOfNames());
    stu->addUser("Calvin", 6789);
    EXPECT_EQ(2, stu->numberOfNames());
}

TEST(StudentTest, addPhoneNumbers) {
}
