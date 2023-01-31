#include <iostream>
#include <string>

using namespace std;

string fizzbuzz (int input) {
  if (input % 3 == 0 and input % 5 == 0) {
    return "fizzbuzz";
  }

  else if (input % 3 == 0) {
    return "fizz";
  }

  else if (input % 5 == 0) {
    return "buzz";
  }

  else {
    std::string s = std::to_string(input);
    return s;
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

