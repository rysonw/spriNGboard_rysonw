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

   x = 0b10100000101010100010101010101100; // Set to 2695506604

  cout << "after setting bits:" << endl;
  cout << "  x = " << x << endl;

  ///////////////////////
  // TOGGLE BIT 3 HERE //
  ///////////////////////

  x ^= (1 << 3); // Toggle Bit 3 once...

  cout << "after first bit 3 toggle:" << endl;
  cout << "  x = " << x << endl;

  //////////////////////////////////////
  // REPEAT YOUR PREVIOUS ACTION HERE //
  //////////////////////////////////////

  x ^= (1 << 3); // then twice

  cout << "after second bit 3 toggle:" << endl;
  cout << "  x = " << x << endl;

  //////////////////////
  // CLEAR BIT 7 HERE //
  //////////////////////

  x &= ~(1 << 7); // Negate/Clear bit 7

  cout << "after clearing bit 7:" << endl;
  cout << "  x = " << x << endl;

  ///////////////////////////
  // CLEAR BITS 16-31 HERE //
  ///////////////////////////

  x &= 0xFFFF; // Clear bits 16-31 in one go

  cout << "after clearing bits 16-31:" << endl;
  cout << "  x = " << x << endl;
}

