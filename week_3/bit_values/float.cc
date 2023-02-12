#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
  uint32_t x = 0;

  //////////////////////////
  // MANIPULATE BITS HERE //
  //////////////////////////


  float f = reinterpret_cast<float&>(x);
  cout << "x = " << x << endl;
  cout << "f = " << showpos << scientific << setprecision(8) << f << endl;
}

