#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <vector>

#include "Venda.hpp"
#include "Conta.hpp"
#include "Cliente.hpp"
#include "Usuario.hpp"
#include "Produto.hpp"
#include "Vendedor.hpp"
#include "Veterinario.hpp"
#include "OrdemServico.hpp"

using namespace std;

class Administrador : virtual public Usuario
{

public:
    Administrador();
    virtual ~Administrador();

    void visualizarClientes(vector<Cliente> &);
    void visualizarVendedores(vector<Vendedor> &);
    void visualizarVeterinarios(vector<Veterinario> &);
    bool visualizarContas(vector<Conta> &);

    bool cadastrarVendedor(vector<Vendedor> &, Vendedor &);
    bool cadastrarVeterinario(vector<Veterinario> &, Veterinario &);
    bool pagarConta(vector<Conta> &, int);
    bool comprar(vector<Produto> &, vector<Conta> &, Produto &, Conta &);
    void registraConta(Conta &);
    void gerarRelatorio(vector<Conta> &, vector<Venda> &);
    bool verificarLogin(string, string);
};

#endif
