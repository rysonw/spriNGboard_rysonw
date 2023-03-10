#include <iostream>
#include <string>

using namespace std;

void non_const_by_ref (string & s) {
  cout << "non_const_by_ref() called on " << s << endl;
  cout << "  &s       = " << &s << endl;
  cout << "  s.size() = " << s.size() << endl;
  s.append(" has been modified");
}

void non_const_by_val (string s) {
  cout << "non_const_by_val() called on " << s << endl;
  cout << "  &s       = " << &s << endl;
  cout << "  s.size() = " << s.size() << endl;
  s.append(" has been modified");
}

void const_by_ref (string const & s) {
  cout << "const_by_ref() called on " << s << endl;
  cout << "  &s       = " << &s << endl;
  cout << "  s.size() = " << s.size() << endl;
  //s.append(" has been modified"); // LINE 1
}

void const_by_val (string const s) {
  cout << "const_by_val() called on " << s << endl;
  cout << "  &s       = " << &s << endl;
  cout << "  s.size() = " << s.size() << endl;
  //s.append(" has been modified"); // LINE 2
}

void overloaded_func (string & s)
{
  cout << "overloaded_func() with non-const ref called on " << s << endl;
}

void overloaded_func (string const & s)
{
  cout << "overloaded_func() with const ref called on " << s << endl;
}

int main ()
{
  //
  // non-const string experiments
  //

  {
    cout << string(10,'=') << endl;
    string ncs = "non-const string";
    cout << "ncs before: " << ncs << endl;
    cout << "&ncs = " << &ncs << endl;
    non_const_by_ref(ncs);
    cout << "ncs after:  " << ncs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string ncs = "non-const string";
    cout << "ncs before: " << ncs << endl;
    cout << "&ncs = " << &ncs << endl;
    non_const_by_val(ncs);
    cout << "ncs after:  " << ncs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string ncs = "non-const string";
    cout << "ncs before: " << ncs << endl;
    cout << "&ncs = " << &ncs << endl;
    const_by_ref(ncs);
    cout << "ncs after:  " << ncs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string ncs = "non-const string";
    cout << "ncs before: " << ncs << endl;
    cout << "&ncs = " << &ncs << endl;
    const_by_val(ncs);
    cout << "ncs after:  " << ncs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string ncs = "non-const string";
    overloaded_func(ncs);
  }

  //
  // const string experiments
  //

  {
    cout << string(10,'=') << endl;
    string const cs = "const string";
    cout << "cs before: " << cs << endl;
    cout << "&cs = " << &cs << endl;
    //non_const_by_ref(cs); // LINE 3
    cout << "cs after:  " << cs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string const cs = "const string";
    cout << "cs before: " << cs << endl;
    cout << "&cs = " << &cs << endl;
    non_const_by_val(cs);
    cout << "cs after:  " << cs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string const cs = "const string";
    cout << "cs before: " << cs << endl;
    cout << "&cs = " << &cs << endl;
    const_by_ref(cs);
    cout << "cs after:  " << cs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string const cs = "const string";
    cout << "cs before: " << cs << endl;
    cout << "&cs = " << &cs << endl;
    const_by_val(cs);
    cout << "cs after:  " << cs << endl;
  }

  {
    cout << string(10,'=') << endl;
    string const cs = "const string";
    overloaded_func(cs);
  }

  return 0;
}

