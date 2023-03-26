add_executable(test__Game
  test__Game.cc
)
target_link_libraries(test__Game PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test__Game PRIVATE Game)

