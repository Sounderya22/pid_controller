#include "PIDcontroller.hpp"

/**
 * @brief Constructor to initialize the PID controller gains.
 * @param kp Proportional gain
 * @param ki Integral gain
 * @param kd Derivative gain
 */
PIDcontroller::PIDcontroller(double kp, double ki, double kd)
    : Kp(kp), Ki(ki), Kd(kd) {}

/**
 * @brief Compute the new velocity based on the target setpoint and actual velocity.
 * @param targetSetpoint The desired velocity
 * @param actualVelocity The current velocity
 * @return The computed velocity (currently a stub that returns a constant value)
 */
double PIDcontroller::compute(double targetSetpoint, double actualVelocity) {
    return 25.0; // Stub implementation
}
