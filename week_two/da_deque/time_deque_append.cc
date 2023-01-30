#include <iostream>
#include <iomanip>

#include <chrono>
#include <vector>

//////////////////////////////////
// ADD NECESSARY #includes HERE //
//////////////////////////////////

using namespace std;

int main ()
{
  vector<vector<int32_t>> time_data;

  int32_t const num_runs  =      5;
  int32_t const num_elems = 10'000;

  for (int32_t run_idx=0; run_idx<num_runs; ++run_idx)
  {
    time_data.push_back(vector<int32_t>(num_elems, 0));

    ////////////////////////////////////////////////
    // CREATE AN EMPTY DEQUE NAMED container HERE //
    ////////////////////////////////////////////////

    for (int32_t elem_idx=0; elem_idx<num_elems; ++elem_idx)
    {
      auto start = chrono::high_resolution_clock::now();

      //////////////////////////////////////////////////////
      // INSERT CODE TO APPEND elem_idx TO container HERE //
      //////////////////////////////////////////////////////

      auto end = chrono::high_resolution_clock::now();
      auto elapsed__ns = chrono::duration_cast<chrono::nanoseconds>(
        end-start
      ).count();

      time_data[run_idx][elem_idx] = elapsed__ns;
    }
  }

  for (int32_t elem_idx=0; elem_idx<num_elems; ++elem_idx)
  {
    cout << setw(10) << elem_idx << " ";

    for (int32_t run_idx=0; run_idx<num_runs; ++run_idx) {
      cout << setw(10) << time_data[run_idx][elem_idx] << " ";
    }

    cout << endl;
  }

  return 0;
}

