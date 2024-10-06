# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  main.cpp
)

# Create a library from the PIDcontroller.cpp file
add_library(pid_controller_lib
  # list of source cpp files:
  PIDcontroller.cpp
)

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(pid_controller_lib PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Any dependent libraries needed to build the shell-app target.
target_link_libraries(shell-app PUBLIC
  myLib1
  myLib2
)

# Set link options for shell-app.
target_link_options(shell-app PUBLIC
  --static
)
