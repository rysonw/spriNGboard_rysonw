#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

#include <catch2/catch_test_macros.hpp>

using namespace std;

void increment_counter (size_t & counter, std::mutex & counter_mutex, size_t num_times)
{
  for (size_t idx=0; idx<num_times; ++idx) {
    this_thread::sleep_for(1ms); // simluate a complicated calculation
    counter++;
  }
}

TEST_CASE("increment example")
{
  size_t const num_times   = 1'000;
  size_t       counter     = 0;
  std::mutex   counter_mutex;

  std::thread t_1(increment_counter, std::ref(counter), std::ref(counter_mutex), num_times);
  std::thread t_2(increment_counter, std::ref(counter), std::ref(counter_mutex), num_times);
  std::thread t_3(increment_counter, std::ref(counter), std::ref(counter_mutex), num_times);
  t_1.join();
  t_2.join();
  t_3.join();

  REQUIRE(counter == 3*num_times);
}

