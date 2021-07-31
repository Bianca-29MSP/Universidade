#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Vendedor.hpp"
#include "Veterinario.hpp"

using namespace std;

template <typename T>
class Login
{
private:
public:
  Login();
  ~Login();

  T &verificarLogin(vector<T> &, string usuario, string senha) const;
};

template <typename T>
Login<T>::Login() {}

template <typename T>
Login<T>::~Login() {}

template <typename T>
T &Login<T>::verificarLogin(vector<T> &arr, string usuario, string senha) const
{ //Percoorre arr
  for (T &item : arr)
  { //Validação do usuário e senha
    if (item.getUsuario() == usuario && item.getSenha() == senha)
    {
      item.setStatusLog(true);
      return item;
      break;
    }
  }
  T *aux = new T;
  aux->setStatusLog(false);
  return *aux;
}

#endif
