#pragma once

/**
 * @file PIDcontroller.hpp
 * @brief Declaration of the PID controller class
 * @author Soundarya, Sarang
 * @copyright 2024
 */

class PIDcontroller {
 private:
  double Kp;
  double Ki;
  double Kd;

 public:
  /**
   * @brief Constructor to initialize the PID controller gains.
   * @param kp Proportional gain
   * @param ki Integral gain
   * @param kd Derivative gain
   */
  PIDcontroller(double kp, double ki, double kd);

  /**
   * @brief Compute the new velocity based on the target setpoint and actual velocity.
   * @param targetSetpoint The desired velocity
   * @param actualVelocity The current velocity
   * @return The computed velocity
   */
  double compute(double targetSetpoint, double actualVelocity);

  double getKp() const {
        return Kp;
    }

    double getKi() const {
        return Ki;
    }

    double getKd() const {
        return Kd;
    }
};