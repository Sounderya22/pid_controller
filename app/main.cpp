#include <iostream>
#include "PIDcontroller.hpp"

int main() {
    
    PIDcontroller pid(1.0, 0.1, 0.01, 0.1); 

    
    pid.setActualVelocity(100.0);

    
    double targetSetpoint = 50.0;

    
    double newVelocity = pid.compute(targetSetpoint);

    
    std::cout << "New velocity after applying PID control: " << newVelocity << std::endl;

    return 0;
}
