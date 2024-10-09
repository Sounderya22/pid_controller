# TDD PAIR B

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/Uthappa13/pid_controller/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/Uthappa13/pid_controller/branch/main/graph/badge.svg)](https://codecov.io/gh/Uthappa13/pid_controller) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)




## Overview

This project implements a **PID Controller** in C++, which computes a new velocity based on a target setpoint and an actual velocity. The project is structured with modularity in mind and uses GoogleTest for unit testing and CodeCov for test coverage reporting.

The **PID Controller** calculates the proportional, integral, and derivative error to adjust the system's velocity in response to the difference between a target (desired) velocity and an actual (measured) velocity. The controller parameters are preset and user-defined through class initialization.

## Features

- **Proportional (Kp)**, **Integral (Ki)**, and **Derivative (Kd)** gains.
- Ability to compute velocity for one time step based on the error between desired and actual velocities.
- Modular design with class declaration (`PIDcontroller.hpp`) and implementation (`PIDcontroller.cpp`).
- Stub implementation for initial testing and development.
- Unit tests with GoogleTest framework.
- Code coverage report generation with CodeCov.


## Part1
- Driver : Sounderya - (https://github.com/Sounderya22)
- Navigator: Sarang - (https://github.com/sarangnair1998)

## Part2
- Driver : Uthappa Madettira- (https://github.com/Uthappa13)
- Navigator: Keyur Borad - (https://github.com/keyurborad5)

## Discussion statement

The implementation passes the unit tests written and meets the expectation.

## Run program
```bash
  cd pid_controller
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/

#************CODE COVERAGE REPORT *********************
# Now, do a clean compile, run unit test, and generate the covereage report of unit tests
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

  # to see the code coverage of shell-app
  # Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html
#************  END ****************

#************RUN UNIT TEST *********************
# TO run test case
  ctest --test-dir build/
#************  END ****************

#************RUN SHELL-APP *********************
# Run program:
  ./build/app/shell-app

#************  END ****************


#************STATIC CODE ANAYLYSIS *********************
#Use clang-tidy for static code analysis (modify as needed):
# if you need to install clang-tidy, do
sudo apt install clang-tidy

# run in the top-level project directory (eg., in cpp-boilerplate-v2/)
clang-tidy -p ./ $( find . -name *.cpp | grep -v "/build/" )
#************  END ****************


#************Foramatting as per Google C++ style *********************
# first install clangd-format, if needed
sudo apt install clangd-format

# Change to directory where your cpp and hpp files are located
# Now, you can see the reformatted output
clang-format -style=Google your_file.cpp

# If you want to completely replace the source code (ie., keep changes in-place) do:
clang-format -style=Google -i your_file.cpp

#************  END ****************



#************Build Doxygen docs*********************
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
#************  END ****************

#************Remove Doxygen docs*********************
# Clean
  cmake --build build/ --target clean
#************  END ****************

#************Remove build folder*********************
# Clean and start over:
  rm -rf build/
#************  END ****************
