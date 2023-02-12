#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
  //
  // Output the header lines.
  //

  cout << setw(5) << "";
  for (int32_t denom=1; denom<=10; ++denom) {
    cout << setw(4) << showpos << denom;
  }
  cout << endl;

  cout << setfill('-') << setw(5) << "";
  for (int32_t denom=1; denom<=10; ++denom) {
    cout << setfill('-') << setw(4) << "";
  }
  cout << endl;
  cout << setfill(' '); // need to reset the fill character

  //
  // Fill in the table rows.
  //

  for (int32_t numer=1; numer<=10; ++numer)
  {
    cout << setw(3) << showpos << numer << ": ";
    for (int32_t denom=1; denom<=10; ++denom)
    {
      int32_t result = numer/denom;
      cout << setw(4) << result;
    }
    cout << endl;
  }
}

