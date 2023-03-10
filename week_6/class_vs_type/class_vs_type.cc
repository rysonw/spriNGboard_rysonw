#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string x{"hello"}; // LINE 1

  string       & rx  = x; // LINE 2
  string const & crx = x; // LINE 3

  cout << "&x   = " << &x   << endl;
  cout << "&rx  = " << &rx  << endl;
  cout << "&crx = " << &crx << endl;

  cout << "=== append() test ===" << endl;
  cout << "x before: " << x << endl;
  //x.append("_x");     // LINE 4
  //rx.append("_rx");   // LINE 5
  //crx.append("_crx"); // LINE 6

  cout << "x after:  " << x << endl;

  return 0;
}
