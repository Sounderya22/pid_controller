#include <gtest/gtest.h>
#include "PIDcontroller.hpp"

// Test to ensure the compute method returns a constant value (stub test)
TEST(PIDcontrollerTest, TestCompute) {
  PIDcontroller pid(1.0, 0.1, 0.01);
  double result = pid.compute(10.0, 5.0);
  EXPECT_EQ(result, 0.0); 
}

// Another test case
TEST(PIDcontrollerTest, TestInitialization) {
    PIDcontroller pid(1.0, 0.5, 0.1);

    // Intentionally setting incorrect expected values to make the test fail
    EXPECT_EQ(pid.getKp(), 2.0);  // This will fail because Kp is actually 1.0
    EXPECT_EQ(pid.getKi(), 1.0);  // This will fail because Ki is actually 0.5
    EXPECT_EQ(pid.getKd(), 0.2);  // This will fail because Kd is actually 0.1
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
