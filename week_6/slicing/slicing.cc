#include <iostream>

using namespace std;

class Animal
{
  public:
    virtual void make_sound () const
    { cout << "I don't know how to make a sound!" << endl; }
};

void poke (Animal const & animal)
{ animal.make_sound(); }

class Cow : public Animal
{
  public:
    virtual void make_sound () const override
    { cout << "moo" << endl; }
};

int main ()
{
  Cow c;

  Animal & cr = c;
  Animal   cs = c;

  poke(c);
  poke(cr);
  poke(cs);

  return 0;
}

