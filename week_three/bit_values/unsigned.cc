#include <iostream>

using namespace std;

int main ()
{
  uint32_t x = 0;

  cout << "initially:" << endl;
  cout << "  x = " << x << endl;

  ///////////////////////////////////
  // SET THE APPROPRIATE BITS HERE //
  ///////////////////////////////////

  cout << "after setting bits:" << endl;
  cout << "  x = " << x << endl;

  ///////////////////////
  // TOGGLE BIT 3 HERE //
  ///////////////////////

  cout << "after first bit 3 toggle:" << endl;
  cout << "  x = " << x << endl;

  //////////////////////////////////////
  // REPEAT YOUR PREVIOUS ACTION HERE //
  //////////////////////////////////////

  cout << "after second bit 3 toggle:" << endl;
  cout << "  x = " << x << endl;

  //////////////////////
  // CLEAR BIT 7 HERE //
  //////////////////////

  cout << "after clearing bit 7:" << endl;
  cout << "  x = " << x << endl;

  ///////////////////////////
  // CLEAR BITS 16-31 HERE //
  ///////////////////////////

  cout << "after clearing bits 16-31:" << endl;
  cout << "  x = " << x << endl;
}

