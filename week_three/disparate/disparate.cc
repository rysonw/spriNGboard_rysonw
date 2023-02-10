#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
  {
    /////////////////////////////////
    // CREATE THREE int32_t VALUES //
    // (big, small, sum)           //
    /////////////////////////////////


    cout << "int32_t:" << endl;
    cout << "  big   = " << big   << endl;
    cout << "  small = " << small << endl;
    cout << "  sum   = " << sum   << endl;
  }

  {
    ///////////////////////////////
    // CREATE THREE float VALUES //
    // (big, small, sum)         //
    ///////////////////////////////


    cout << "float:" << endl;
    cout << "  big   = " << fixed << setprecision(1) << big   << endl;
    cout << "  small = " << fixed << setprecision(1) << small << endl;
    cout << "  sum   = " << fixed << setprecision(1) << sum   << endl;
  }
}

