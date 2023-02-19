#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> v{10,5};
  // vector<int> v = {10,5};
  // vector<int> v(10,5);
  // vector<int> v = (10,5);

  for (auto& elem : v) {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}

