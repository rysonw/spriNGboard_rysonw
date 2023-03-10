#include <iostream>

using namespace std;

class Animal
{
  public:
    virtual void make_sound () const = 0;
};

void poke (Animal const & animal)
{ animal.make_sound(); }

class Cow : public Animal
{
  public:
    virtual void make_sound () const override
    { cout << "moo" << endl; }
};

class FullCow : public Cow
{
  public:
    virtual void make_sound () const override
    { cout << "Ooof - I ate too much" << endl; }
};

int main ()
{
  Cow c;
  FullCow fc;

  poke(c);
  poke(fc);

  return 0;
}

