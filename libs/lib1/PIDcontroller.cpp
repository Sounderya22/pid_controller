#include "PIDcontroller.hpp"

#include <iostream>

/**
 * @brief Constructor to initialize the PID controller gains and time step.
 * @param kp Proportional gain
 * @param ki Integral gain
 * @param kd Derivative gain
 * @param dt Time step for the controller loop
 */
PIDcontroller::PIDcontroller(double kp, double ki, double kd, double dt)
    : Kp(kp),
      Ki(ki),
      Kd(kd),
      deltaTime(dt),
      prevError(0),
      integral(0),
      actualVelocity(0) {}

/**
 * @brief Set the current actual velocity (initial condition) of the system.
 * @param velocity The current actual velocity of the system
 */
void PIDcontroller::setActualVelocity(double velocity) {
  actualVelocity = velocity;
}

/**
 * @brief Compute the new velocity based on the target setpoint and actual
 * velocity. This is a stub that currently returns a constant value for
 * demonstration.
 * @param targetSetpoint The desired velocity (target setpoint)
 * @return The computed velocity (currently a stub that returns a constant
 * value)
 */
double PIDcontroller::compute(double targetSetpoint) {
  double error = targetSetpoint - actualVelocity;

  integral += error;

  double new_velocity =
      Kp * (error) + Ki * (integral) + Kd * (error - prevError);

  actualVelocity = actualVelocity + new_velocity;

  prevError = error;

  return actualVelocity;
}

/**
 * @brief Reset the integral and previous error values (useful when restarting
 * the controller).
 */
void PIDcontroller::reset() {
  integral = 0;
  prevError = 0;
}

/**
 * @brief Get the proportional gain (Kp).
 * @return The proportional gain
 */
double PIDcontroller::getKp() const { return Kp; }

/**
 * @brief Get the integral gain (Ki).
 * @return The integral gain
 */
double PIDcontroller::getKi() const { return Ki; }

/**
 * @brief Get the derivative gain (Kd).
 * @return The derivative gain
 */
double PIDcontroller::getKd() const { return Kd; }

/**
 * @brief Get the current actual velocity.
 * @return The current actual velocity of the system
 */
double PIDcontroller::getActualVelocity() const { return actualVelocity; }

/**
 * @brief Get the time step (delta time) for the controller.
 * @return The time step for the PID control loop
 */
double PIDcontroller::getDeltaTime() const { return deltaTime; }
