#include <iostream>

#include "PIDcontroller.hpp"

int main() {
  // Variable declaration
  double new_velocity;

  // Creating an object for the class PIDcontroller
  PIDcontroller my_controller(0.50, 0.01, 0.1, 1);

  // Set the actual velocity
  my_controller.setActualVelocity(100.0);

  // Compute the new velocity
  new_velocity = my_controller.compute(50.0);

  // Print the computed velocity
  std::cout << "The new computed velocity is " << new_velocity << '\n';

  // Reset the PID parameters
  my_controller.reset();
}
