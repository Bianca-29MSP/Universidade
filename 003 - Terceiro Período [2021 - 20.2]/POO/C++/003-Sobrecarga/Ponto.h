#ifndef PONTO_H
#define PONTO_H

class Ponto
{
  int x, y;

public:
  Ponto(int = 0, int = 0);
  Ponto(const Ponto &);
  ~Ponto();

  void set(int, int);
  void set(const Ponto &);

  //Declaração operadores unários como método membro
  Ponto &operator++();    //p++
  Ponto &operator++(int); //++p

  //Declaração operadores binários como método membro
  Ponto operator+(const Ponto &) const;
  Ponto &operator=(const Ponto &);

  //Declaração operadores binários com função friend
  friend bool operator==(const Ponto &, const Ponto &);

  void print();
};

#endif
