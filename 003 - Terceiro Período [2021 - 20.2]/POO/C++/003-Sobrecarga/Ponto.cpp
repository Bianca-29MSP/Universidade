#include <iostream>
#include "Ponto.h"

using namespace std;

Ponto::Ponto(int x, int y) : x(x), y(y) {}
Ponto::Ponto(const Ponto &P)
{
  x = P.x;
  y = P.y;
}

Ponto::~Ponto(){};

void Ponto::set(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Ponto::set(const Ponto &P)
{
  this->x = P.x;
  this->y = P.y;
}

//& é referencia
//a = a + 1
Ponto &Ponto::operator++()
{
  this->x++;
  this->y++;
  return *this;
}

Ponto &Ponto::operator++(int)
{
  this->operator++();
  return *this;
}

//c = a + b
Ponto Ponto::operator+(const Ponto &P2) const
{
  Ponto tmp;
  tmp.x = this->x + P2.x;
  tmp.y = this->y + P2.y;
  return tmp;
}

Ponto &Ponto::operator=(const Ponto &P)
{
  if (this == &P)
    return *this;
  this->x = P.x;
  this->y = P.y;
  return *this;
}

bool operator==(const Ponto &P1, const Ponto &P2)
{
  return (P1.x == P2.x && P1.y == P2.y);
}

void Ponto::print()
{
  cout << "(" << x << "," << y << ")\n";
}
