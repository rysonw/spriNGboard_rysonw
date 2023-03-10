#include <iostream>

using namespace std;

void func (int & x)
{ cout << "func(int & x): lvalue ref" << endl; }

#if 1
void func (int const & x)
{ cout << "func(int const & x): const lvalue ref" << endl; }
#endif

void func (int && x)
{ cout << "func(int && x) rvalue ref" << endl; }

#if 1
void func (int const && x)
{ cout << "func(int const && x) const rvalue ref" << endl; }
#endif

int main ()
{
  func(5);
  func(2+3);
  func(int{5});

  int x = 5;
  func(x);
  func(x/2);
  func(move(x));

  const int y = 5;
  func(y);
  func(y/2);
  func(move(y));
};
