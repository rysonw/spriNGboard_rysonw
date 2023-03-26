#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct RunResults
{
  string seed;
  string golden;
  string actual;
};

RunResults run_trivia_with_seed (string const seed)
{
  RunResults results;

  results.seed = seed;

  string const trivia_executable       = "./src/game_runner/trivia";
  string const actual_output_filename  = "/tmp/trivia_actual.txt";
  string const golden_output_filename  =
    string("../test/regression/golden_data/seed_") +
    string(seed) +
    string(".txt");

  {
    string const command =
      trivia_executable +
      string(" ") + seed +
      string(" > ") +
      actual_output_filename;

    //cout << "command = (" << command << ")" << endl;

    auto status = system(command.c_str());
    REQUIRE(status == 0);
  }

  {
    ifstream file(actual_output_filename);
    stringstream buffer;
    buffer << file.rdbuf();
    results.actual = buffer.str();
  }

  {
    ifstream file(golden_output_filename);
    stringstream buffer;
    buffer << file.rdbuf();
    results.golden = buffer.str();
  }

  return results;
}

TEST_CASE ("check for regressions against golden data")
{
  auto seed = GENERATE(range(0,50));
  string const seed_str = to_string(seed);

  SECTION(seed_str)
  {
    auto result = run_trivia_with_seed(seed_str);
    REQUIRE(result.actual == result.golden);
  }
}

