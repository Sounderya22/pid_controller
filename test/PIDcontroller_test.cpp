#include <gtest/gtest.h>
#include "PIDcontroller.hpp"

// Test to ensure the compute method returns the stub value (intentionally failing)
TEST(PIDcontrollerTest, TestCompute) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1
  pid.setActualVelocity(100.0);  // Set the actual velocity to 100.0

  // Check if the compute method returns an incorrect expected value to fail the test
  double result = pid.compute(50.0);  // Target setpoint of 50.0
  EXPECT_EQ(result, 0.0);  // This will fail since the stub returns 25.0
}

// Test initialization of the PID controller (intentionally failing)
TEST(PIDcontrollerTest, TestInitialization) {
  PIDcontroller pid(1.0, 0.5, 0.1, 0.1);  // kp=1.0, ki=0.5, kd=0.1, dt=0.1
  
  // Intentionally incorrect expected values to fail the test
  EXPECT_EQ(pid.getKp(), 2.0);  // This will fail because Kp is actually 1.0
  EXPECT_EQ(pid.getKi(), 1.0);  // This will fail because Ki is actually 0.5
  EXPECT_EQ(pid.getKd(), 0.2);  // This will fail because Kd is actually 0.1
}

// Test the setActualVelocity method (intentionally failing)
TEST(PIDcontrollerTest, TestSetActualVelocity) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1
  pid.setActualVelocity(100.0);  // Set actual velocity to 100

  // Intentionally check for an incorrect actual velocity
  EXPECT_EQ(pid.getActualVelocity(), 50.0);  // This will fail because actual velocity is 100.0
}

// Test the reset method to ensure integral and previous error are reset (intentionally failing)
TEST(PIDcontrollerTest, TestReset) {
  PIDcontroller pid(1.0, 0.1, 0.01, 0.1);  // kp=1.0, ki=0.1, kd=0.01, dt=0.1
  
  // Simulate some previous state (stub values for test)
  pid.setActualVelocity(100.0);  // Set velocity
  pid.compute(50.0);  // Call compute
  
  // Call reset and intentionally expect failure by testing incorrect logic
  pid.reset();
  
  // Since the internal state is private, we can't directly check it, but we can make the test fail by expecting wrong behavior
  EXPECT_EQ(pid.compute(50.0), 0.0);  // This will fail because the stub returns 25.0
}

// Main entry point for the tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
