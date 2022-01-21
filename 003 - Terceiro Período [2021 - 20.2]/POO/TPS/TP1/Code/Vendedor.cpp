#include "Vendedor.hpp"

Vendedor::Vendedor(string nome, string usuario, string senha, float salario)
    : Usuario(nome, salario, usuario, senha){};

Vendedor::~Vendedor(){};

//Busca o cliente no array de clientes pelo ID
Cliente Vendedor::getClienteById(vector<Cliente> &clientes, int id, bool &flag)
{
  if (this->getStatusLog()) //Verifica o login do vendedor
  {
    if (clientes.empty()) //verifica se há clientes
    {
      cout << "Não há clientes cadastrados." << endl;
    }
    else
    {
      for (Cliente &cliente : clientes)
      {
        if (cliente.getId() == id)
        { //procura o cliente pelo ID
          flag = true;
          return cliente;
        }
      }
    }
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
  Cliente temp;
  flag = false;
  return temp;
}

bool Vendedor::cadastrarCliente(vector<Cliente> &clientes, Cliente &cliente)
{
  if (this->getStatusLog()) //Verifica o login do vendedor
  {
    clientes.push_back(cliente); //Adiciona o cliente ao array de clientes
    return true;
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
  return false;
}

//Exibe os clientes cadastrados na tela
void Vendedor::visualizarCliente(vector<Cliente> &clientes)
{
  if (this->getStatusLog()) //Verifica o login do vendedor
  {
    if (clientes.empty()) //Verifica se há clientes
    {
      cout << "Não há clientes cadastrados." << endl;
    }
    else
    {
      for (Cliente &cliente : clientes)
      {
        cout << cliente << endl; //Exibe todos os clientes na tela
      }
    }
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
}

void Vendedor::visualizarProdutos(vector<Produto> &produtos)
{
  if (this->getStatusLog()) //Verifica o login do vendedor
  {
    if (produtos.empty()) //Verifica se há produtos
    {
      cout << "Não há produtos cadastrados." << endl;
    }
    else
    {
      for (Produto &produto : produtos)
      {
        cout << produto << endl; //Exibe todos os produtos em tela
      }
    }
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
}

bool Vendedor::realizarVenda(vector<Produto> &produtos, vector<Venda> &vendas, int id, int quantidade)
{
  if (this->getStatusLog()) //Verifica se o vendedor está logado
  {
    if (produtos.empty()) //verifica se há produtos para vender
      cout << "Não há produtos cadastrados." << endl;

    if (quantidade < 0)
      return false;

    for (Produto &produto : produtos)
    {
      if (produto.getId() == id) //verifica se é o produto desejado
      {
        if (produto.getQuantidade() >= quantidade) //verifica se há disponibilidade do produto
        {
          produto.atualizarQuantidade(quantidade);                                 //diminui a quantidade desejada à quantidade dos produtos
          Venda nVenda(produto, (produto.getValor() * quantidade), this->getId()); //cria uma nova venda
          vendas.push_back(nVenda);                                                //adiciona a venda às vendas
          return true;
        }
        else
        {
          return false;
        }
      }
    }
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
  return false;
}

bool Vendedor::realizarOrdemServico(vector<OrdemServico> &ordens, vector<Venda> &vendas, Servico &servico, OrdemServico &ordemServico)
{
  if (this->getStatusLog()) //Verifica se o vendedor está logado
  {
    ordens.push_back(ordemServico);                           //adiciona a ordem de serviço no vetor
    Venda nVenda(servico, servico.getValor(), this->getId()); //cria uma nova venda
    vendas.push_back(nVenda);                                 //adiciona a venda à vendas
    return true;
  }
  else
  {
    cerr << "Erro: Ação não permitida, faça o login." << endl;
    cerr << "Pressione enter para continuar... ";
    getchar();
  }
  return false;
}

Vendedor &Vendedor::verificarLogin(vector<Vendedor> &vendedores, string usuario, string senha)
{
  Login<Vendedor> login; //utilização da classe template
  return login.verificarLogin(vendedores, usuario, senha);
}
