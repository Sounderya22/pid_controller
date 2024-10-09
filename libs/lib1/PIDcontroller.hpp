#pragma once

/**
 * @file PIDcontroller.hpp
 * @brief Declaration of the PID controller class.
 * @author Sounderya, Sarang
 * @copyright 2024
 */

class PIDcontroller {
 private:
  double Kp;              ///< Proportional gain
  double Ki;              ///< Integral gain
  double Kd;              ///< Derivative gain
  double prevError;       ///< Previous error for derivative calculation
  double integral;        ///< Sum of past errors for integral calculation
  double actualVelocity;  ///< Current velocity of the system

  double deltaTime;  ///< Time step for the PID control loop

 public:
  /**
   * @brief Constructor to initialize the PID controller gains and other
   * necessary parameters.
   * @param kp Proportional gain
   * @param ki Integral gain
   * @param kd Derivative gain
   * @param dt Time step for the controller loop
   */
  PIDcontroller(double kp, double ki, double kd, double dt);

  /**
   * @brief Set the current actual velocity (initial condition) of the system.
   * @param velocity The current actual velocity of the system
   */
  void setActualVelocity(double velocity);

  /**
   * @brief Compute the new velocity based on the target setpoint and actual
   * velocity. This method will calculate the error, update integral and
   * derivative terms, and output the computed velocity.
   * @param targetSetpoint The desired velocity (target setpoint)
   * @return The computed velocity after applying the PID control logic
   */
  double compute(double targetSetpoint);

  /**
   * @brief Reset the integral and previous error values (useful when restarting
   * the controller).
   */
  void reset();

  // Accessor methods for debugging or tuning purposes

  /**
   * @brief Get the proportional gain (Kp).
   * @return The proportional gain
   */
  double getKp() const;

  /**
   * @brief Get the integral gain (Ki).
   * @return The integral gain
   */
  double getKi() const;

  /**
   * @brief Get the derivative gain (Kd).
   * @return The derivative gain
   */
  double getKd() const;

  /**
   * @brief Get the current actual velocity.
   * @return The current actual velocity of the system
   */
  double getActualVelocity() const;

  /**
   * @brief Get the time step (delta time) for the controller.
   * @return The time step for the PID control loop
   */
  double getDeltaTime() const;
};
