#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

////////////////////////////////////
// INCLUDE NECESSARY HEADERS HERE //
////////////////////////////////////


using namespace std;

void print_vector (const vector<int>& v);

void test_algorithms (int N)
{
  //////////////////////////////
  // CREATE A VECTOR v OF int //
  // WITH SIZE N              //
  // FILLED WITH ZEROS        //
  //////////////////////////////

  std::vector<int> v(N, 0);


  print_vector(v);

  ///////////////////////////////
  // USE iota TO FILL v        //
  // WITH VALUES STARTING AT 5 //
  ///////////////////////////////

  std::iota(v.begin(), v.end(), 5);

  print_vector(v);

  ///////////////////////////////////////
  // USE reverse TO REVERSE THE VALUES //
  // BETWEEN THE THIRD AND FIFTH FROM  //
  // LAST POSITIONS                    //
  ///////////////////////////////////////

  std::reverse(v.end()-5, v.end()-2);


  print_vector(v);

  /////////////////////////////////////
  // USE fill TO FILL THE FIRST FOUR //
  // VALUES WITH 20s                 //
  /////////////////////////////////////

  std::fill(v.begin(), v.begin() + 4, 20);


  print_vector(v);

  ////////////////////////////////////////
  // USE sort TO SORT ALL BUT THE FIRST //
  // AND LAST VALUES                    //
  ////////////////////////////////////////

  std::sort(v.begin() + 1, v.end() - 1);

  print_vector(v);

  ///////////////////////////////////////////
  // USE sort WITH A COMPARISON LAMBDA     //
  // TO SORT ALL EVEN NUMBERS TO THE       //
  // FRONT AND ALL ODD NUMBERS TO THE BACK //
  ///////////////////////////////////////////

  std::sort(v.begin(), v.end(), [](int l, int r) { //lambda is brackets
    if (l % 2 == 0 && r % 2 != 0) {
      return true;
    } 
    
    else if (l % 2 != 0 && r % 2 == 0) {
      return false;
    } 
    
    else {
      return l < r;
    }
  });

  print_vector(v);
}

int main ()
{
  test_algorithms(15);
}

void print_vector (const vector<int>& v)
{
  cout << "v = ";
  for (auto& elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

