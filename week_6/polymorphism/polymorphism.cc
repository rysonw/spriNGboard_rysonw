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
    void make_sound () const override
    { cout << "moo" << endl; }
};

class FullCow : public Cow
{
  public:
    void make_sound () const override
    { cout << "Ooof - I ate too much" << endl; }
};

class Phoenix : public Animal
{
  public:
    void make_sound () const override
    { cout << "Cuh Caw" << endl; }
    
    void spit_fire() const
    { cout << "*Spits Fire*" << endl; }
};

class Fish : public Animal
{
  public:
    void make_sound () const override
    { cout << "Blub Blub" << endl; }
    
};


int main ()
{
  Cow c;
  FullCow fc;
  Phoenix p;
  Fish f;

  poke(p);
  p.spit_fire();
  poke(f);
  
  return 0;
}
