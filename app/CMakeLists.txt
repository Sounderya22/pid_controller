

# Create a library from the PIDcontroller.cpp file
add_library(pid_controller_lib
  # list of source cpp files:
  PIDcontroller.cpp
)

target_include_directories(pid_controller_lib PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)
