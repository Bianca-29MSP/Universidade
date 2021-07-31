#include <vector>

#include "Vendedor.hpp"
#include "Veterinario.hpp"
#include "Cliente.hpp"
#include "Administrador.hpp"
#include "Produto.hpp"
#include "Conta.hpp"
#include "OrdemServico.hpp"
#include "Servico.hpp"
#include "Venda.hpp"

//Struct que armazena todos os registros através do vector durante a execução
typedef struct
{
  vector<Vendedor> vendedores;
  vector<Veterinario> veterinarios;
  vector<Cliente> clientes;
  vector<OrdemServico> ordensservico;

  vector<Produto> produtos;
  vector<Conta> contas;
  vector<Venda> vendas;

  Servico servicos[2] = {
      Servico("Banho e tosa", 80.0),
      Servico("Consulta", 90.0)};
} Registros;