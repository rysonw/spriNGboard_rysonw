#include <iostream>
#include <string>

using namespace std;

void fizzbuzz (int input) {
  if (input % 3 == 0 and input % 5 == 0) {
    cout << "fizzbuzz" << endl;
  }

  else if (input % 3 == 0) {
    cout << "fizz" << endl;
  }

  else if (input % 5 == 0) {
    cout << "buzz" << endl;
  }

  else {
    std::string s = std::to_string(input);
    cout << s << endl;
  }
}

int main ()
{
  for (int n=1; n<=50; ++n)
  {
    fizzbuzz(n)
  }

  return 0;
}