#include "PIDcontroller.hpp"

#include <gtest/gtest.h>

// Test to ensure the compute method returns the stub value (intentionally
// failing)
TEST(PIDcontrollerTest, TestCompute) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1
  pid.setActualVelocity(100.0);            // Set the actual velocity to 100.0

  // Compute the new velocity after the first step toward the setpoint of 50.0
  double result = pid.compute(50.0);  // Target setpoint of 50.0

  // Since the target setpoint is 50.0 and actual velocity is 100.0, the
  // velocity should decrease
  EXPECT_LT(result, 100.0);  // Expect the new velocity to be less than 100.0,
                             // moving toward the setpoint
}

// Test initialization of the PID controller (intentionally failing)
TEST(PIDcontrollerTest, TestInitialization) {
  PIDcontroller pid(1.0, 0.5, 0.1, 0.1);  // kp=1.0, ki=0.5, kd=0.1, dt=0.1

  // Intentionally incorrect expected values to fail the test
  EXPECT_EQ(pid.getKp(), 1.0);  // This will pass because Kp is actually 1.0
  EXPECT_EQ(pid.getKi(), 0.5);  // This will pass because Ki is actually 0.5
  EXPECT_EQ(pid.getKd(), 0.1);  // This will pass because Kd is actually 0.1
}

// Test the setActualVelocity method
TEST(PIDcontrollerTest, TestSetActualVelocity) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1
  pid.setActualVelocity(100.0);            // Set actual velocity to 100

  // Check that the actual velocity was set to 100.0
  EXPECT_EQ(pid.getActualVelocity(),
            100.0);  // This should pass because actual velocity is 100.0
}

// Test the reset method to ensure integral and previous error are reset
// (intentionally failing)
TEST(PIDcontrollerTest, TestReset) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1

  pid.setActualVelocity(100.0);        // Set velocity
  double result1 = pid.compute(50.0);  // Call compute

  // Call reset and intentionally expect failure by testing incorrect logic
  pid.reset();

  double result2 = pid.compute(50.0);

  EXPECT_NE(result2, result1);  //
}

// // Main entry point for the tests
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
