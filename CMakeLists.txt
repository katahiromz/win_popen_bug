# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# enable testing
enable_testing()

# project name and language
project(getoptbug C)

##############################################################################
# executables

# cmdline.exe
add_executable(cmdline1 cmdline.c)
set_target_properties(cmdline1 PROPERTIES OUTPUT_NAME "cmdline")

# "cm dline.exe"
add_executable(cmdline2 cmdline.c)
set_target_properties(cmdline2 PROPERTIES OUTPUT_NAME "cm dline")

# win_popen_bug.exe
add_executable(win_popen_bug win_popen_bug.c)
