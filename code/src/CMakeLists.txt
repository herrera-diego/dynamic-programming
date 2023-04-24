set(CMAKE_CXX_STANDARD 11)

add_executable(dp main.cpp)

# Define the custom command and target to copy the executable to the bin/ directory
add_custom_command(TARGET dp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dp> ${CMAKE_BINARY_DIR})
add_custom_target(copy_dp ALL DEPENDS dp)