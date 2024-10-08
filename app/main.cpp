#include "PIDcontroller.hpp"
#include <iostream>

int main(){

    double new_velocity;

    // creating an object for the class PIDcontroller
    PIDcontroller my_controller(0.50, 0.01, 0.1, 1);

    // Set the actual velocity
    my_controller.setActualVelocity(100.0);

    new_velocity = my_controller.compute(50.0);

    std::cout<<"The new computed velocity is "<<new_velocity<<'\n';

    my_controller.reset();



}
