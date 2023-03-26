add_executable(test__regression
  test__regression.cc
)
target_link_libraries(test__regression PRIVATE Catch2::Catch2WithMain)


add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/create_golden_data.pl
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/create_golden_data.pl
  COMMAND ${CMAKE_COMMAND}
    -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/create_golden_data.pl
    ${CMAKE_CURRENT_BINARY_DIR}/create_golden_data.pl
)

## from: https://samthursfield.wordpress.com/2015/11/21/cmake-dependencies-between-targets-and-files-and-custom-commands/
add_custom_target(
  Trivia ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/create_golden_data.pl
)
