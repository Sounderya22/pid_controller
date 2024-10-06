# cpp-boilerplate-v2

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/Sounderya22/pid_controller/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/Sounderya22/pid_controller/branch/main/graph/badge.svg)](https://codecov.io/gh/Sounderya22/pid_controller) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)




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


## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2
  cd cpp-boilerplate-v2
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

ref: https://cmake.org/cmake/help/latest/manual/cmake.1.html

## Building for code coverage (for assignments beginning in Week 4)

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```
