#ifndef VETERINARIO_H
#define VETERINARIO_H

#include "Usuario.hpp"
#include "OrdemServico.hpp"
#include "Login.hpp"
#include "Cliente.hpp"

#include <vector>

using namespace std;

class Veterinario : virtual public Usuario
{

public:
    Veterinario(string = "", string = "", string = "", float = 0.0);
    virtual ~Veterinario();

    void visualizarOrdem(vector<OrdemServico> &);
    void visualizarCliente(vector<Cliente> &);
    Veterinario &verificarLogin(vector<Veterinario> &, string, string);
    bool registraRelatorio(vector<OrdemServico> &, string, int);
};

#endif
