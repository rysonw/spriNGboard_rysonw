add_executable(test__exercise_02_rcs
  test__exercise_02_rcs.cc
)
target_link_libraries(test__exercise_02_rcs PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test__exercise_02_rcs PRIVATE pthread)

