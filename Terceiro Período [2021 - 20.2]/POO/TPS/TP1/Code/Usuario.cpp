#include "Usuario.hpp"
#include "Estilos.hpp"

static int _id = 0;

Usuario::Usuario(string nome, float salario, string usuario, string senha)
    : nome(nome), salario(salario), usuario(usuario), senha(senha)
{
    this->id = _id++;
}

Usuario::~Usuario(){};

int Usuario::getId() const
{
    return id;
}
string Usuario::getNome() const
{
    return nome;
}

string Usuario::getUsuario() const
{
    return usuario;
}

string Usuario::getSenha() const
{
    return senha;
}

float Usuario::getSalario() const
{
    return salario;
}

bool Usuario::getStatusLog() const
{
    return statusLog;
}

void Usuario::setNome(string nome)
{
    this->nome = nome;
}

void Usuario::setSalario(float salario)
{
    this->salario = salario;
}

void Usuario::setUsuario(string usuario)
{
    this->usuario = usuario;
}

void Usuario::setSenha(string senha)
{
    this->senha = senha;
}

void Usuario::setStatusLog(bool status)
{
    this->statusLog = status;
}

ostream &operator<<(ostream &out, const Usuario &usuario)
{
    out
        << FONT_COLOR << "ID  " << FONT_COLOR_PRIMARY << usuario.getId() << FONT_COLOR << "  |  " << RESET_COLOR
        << FONT_COLOR << "NOME  " << FONT_COLOR_PRIMARY << usuario.getNome() << FONT_COLOR << "  |  " << RESET_COLOR
        << FONT_COLOR << "USUARIO  " << FONT_COLOR_PRIMARY << usuario.getUsuario() << FONT_COLOR << "  |  " << RESET_COLOR
        << FONT_COLOR << "SALARIO " << FONT_COLOR_PRIMARY << fixed << setprecision(2) << usuario.getSalario() << RESET_COLOR;
    return out;
}