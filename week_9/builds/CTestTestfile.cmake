# CMake generated Testfile for 
# Source directory: /home/ryson/spriNGboard_rysonw/week_9
# Build directory: /home/ryson/spriNGboard_rysonw/week_9/builds
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test("test__regression" "/home/ryson/spriNGboard_rysonw/week_9/builds/test/regression/test__regression")
set_tests_properties("test__regression" PROPERTIES  _BACKTRACE_TRIPLES "/home/ryson/spriNGboard_rysonw/week_9/CMakeLists.txt;24;add_test;/home/ryson/spriNGboard_rysonw/week_9/CMakeLists.txt;0;")
add_test("test__Game" "/home/ryson/spriNGboard_rysonw/week_9/builds/test/game_lib/test__Game")
set_tests_properties("test__Game" PROPERTIES  _BACKTRACE_TRIPLES "/home/ryson/spriNGboard_rysonw/week_9/CMakeLists.txt;29;add_test;/home/ryson/spriNGboard_rysonw/week_9/CMakeLists.txt;0;")
subdirs("src")
subdirs("test")
