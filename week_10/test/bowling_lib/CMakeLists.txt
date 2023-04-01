add_executable(test__Bowling
  test__Bowling.cc
)
target_link_libraries(test__Bowling PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test__Bowling PRIVATE Bowling)

