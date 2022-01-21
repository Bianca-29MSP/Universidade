#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Usuario
{
    int id;
    string nome;
    float salario;
    string usuario;
    string senha;
    bool statusLog;

public:
    Usuario(string = "", float = 0.0, string = "", string = "");
    ~Usuario();

    int getId() const;
    string getNome() const;
    string getUsuario() const;
    string getSenha() const;
    bool getStatusLog() const;
    float getSalario() const;

    void setId(int);
    void setNome(string);
    void setSalario(float);
    void setUsuario(string);
    void setSenha(string);
    void setStatusLog(bool);

    friend ostream &operator<<(ostream &, const Usuario &);
};

#endif