add_executable(test__exercise_01_cvs
  test__exercise_01_cvs.cc
)
target_link_libraries(test__exercise_01_cvs PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test__exercise_01_cvs PRIVATE pthread)

