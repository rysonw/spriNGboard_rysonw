#include <iostream>
#include <memory>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

class MyClass
{
  public:
    MyClass ()
      : m_uid(cm_next_uid++),
        m_name("unnamed")
    { cout << "  default ctor " << desc() << endl; }

    MyClass (string name)
      : m_uid(cm_next_uid++),
        m_name(name)
    { cout << "  custom ctor " << desc() << endl; }

    MyClass (MyClass const & orig)
      : m_uid(cm_next_uid++),
        m_name("copy of " + orig.desc())
    { cout << "  copy ctor " << desc() << endl; }

#if 1
    MyClass (MyClass && orig) noexcept
      : m_uid(cm_next_uid++),
        m_name("moved from " + exchange(orig.m_name, "stolen"))
    { cout << "  move ctor " << desc() << endl; }
#endif

    MyClass& operator= (MyClass const & orig)
    {
      cout << "  copy assign " << desc() << " from " << orig.desc() << endl;

      if (this != &orig) {
        m_name = "=" + orig.desc();
      }
      return *this;
    }

#if 1
    MyClass& operator= (MyClass && orig) noexcept
    {
      cout << "  move assign " << desc() << " from " << orig.desc() << endl;

      if (this != &orig) {
        m_name = "moved from " + exchange(orig.m_name, "stolen");
      }
      return *this;
    }
#endif

    ~MyClass ()
    { cout << "  dtor " << desc() << endl; }

  private:

    string desc () const
    {
      ostringstream ostr;
      ostr << "(" << m_uid << "," << m_name << ")" << ends;
      return ostr.str();
    }

  private:

    static int cm_next_uid;

    int    m_uid;
    string m_name;
};

int MyClass::cm_next_uid = 1;

MyClass make_new_object_good ()
{
  MyClass x("x");
  return x;
}

MyClass make_new_object_bad ()
{
  MyClass y("y");
  return move(y);
}

int main ()
{
  cout << "MyClass o_1;" << endl;
  MyClass o_1;

  cout << "MyClass o_2(\"o_2\");" << endl;
  MyClass o_2("o_2");

  cout << "MyClass o_3 = o_2;" << endl;
  MyClass o_3 = o_2;

  cout << "MyClass o_4(\"o_4\");" << endl;
  MyClass o_4("o_4");

  cout << "o_4 = o_1;" << endl;
  o_4 = o_1;

  cout << "MyClass o_5(move(o_1));" << endl;
  MyClass o_5(move(o_1));

  cout << "o_1 = move(o_3);" << endl;
  o_1 = move(o_3);

  cout << "MyClass o_6 = make_new_object_good();" << endl;
  MyClass o_6 = make_new_object_good();

  cout << "MyClass o_7 = make_new_object_bad();" << endl;
  MyClass o_7 = make_new_object_bad();

  cout << "open brace (vectors)" << endl;
  {
    cout << "vector<MyClass> v_1;" << endl;
    vector<MyClass> v_1;

    cout << "v_1.emplace_back(\"v_1[0]\");" << endl;
    v_1.emplace_back("v_1[0]");

    cout << "v_1.push_back(MyClass(\"v_1[1]\"));" << endl;
    v_1.push_back(MyClass("v_1[1]"));

    cout << "v_1.emplace_back(MyClass(\"v_1[2]\"));" << endl;
    v_1.emplace_back(MyClass("v_1[2]"));

    cout << "vector<MyClass> v_2 = v_1;" << endl;
    vector<MyClass> v_2 = v_1;

    cout << "vector<MyClass> v_3 = move(v_1);" << endl;
    vector<MyClass> v_3 = move(v_1);

    cout << "closing brace (vectors)" << endl;
  }

  cout << "opening brace (pointers)" << endl;
  {
    cout << "auto up_1 = make_unique<MyClass>(\"u_1\");" << endl;
    auto up_1 = make_unique<MyClass>("u_1");

    cout << "auto sp_1 = make_shared<MyClass>(\"s_1\");" << endl;
    auto sp_1 = make_shared<MyClass>("s_1");

    cout << "opening brace (inner pointers)" << endl;
    {
      cout << "auto up_2 = make_unique<MyClass>(\"u_2\");" << endl;
      auto up_2 = make_unique<MyClass>("u_2");

      cout << "auto up_3 = move(up_1);" << endl;
      auto up_3 = move(up_1);

      cout << "auto sp_2 = make_shared<MyClass>(\"s_2\");" << endl;
      auto sp_2 = make_shared<MyClass>("s_2");

      cout << "sp_1 = sp_2;" << endl;
      sp_1 = sp_2;

      cout << "closing brace (inner pointers)" << endl;
    }
    cout << "closing brace (pointers)" << endl;
  }

  cout << "closing brace (main)" << endl;
}


