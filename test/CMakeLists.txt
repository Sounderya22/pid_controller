# Add executable for the PID controller test
add_executable(pid_controller_test
  # list of source cpp files:
  PIDcontroller_test.cpp
)


target_include_directories(pid_controller_test PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)


# Link libraries for pid_controller_test
target_link_libraries(pid_controller_test PUBLIC
  gtest
  gtest_main
  pid_controller_lib  # Link the PID controller library here
)

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(pid_controller_test)
