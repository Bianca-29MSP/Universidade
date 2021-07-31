#include "Administrador.hpp"
#include "Estilos.hpp"

#define USUARIO "admin"
#define SENHA "admin"

Administrador ::Administrador() : Usuario("Administrador", 0.0, "admin", "admin") {}

Administrador::~Administrador(){};

//Mostra na tela todos os clientes cadastrados
void Administrador::visualizarClientes(vector<Cliente> &clientes)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        if (clientes.empty())
        {
            cout << "Não há clientes cadastrados." << endl;
        }
        else
        {
            for (Cliente &cliente : clientes) //Percorre o vetor de cliente e exibe um por um na tela
            {
                cout << cliente << endl;
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

//Mostra na tela todos os funcionarios cadastrados
void Administrador::visualizarVeterinarios(vector<Veterinario> &veterinarios)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        if (veterinarios.empty())
        {
            cout << "Não há veterinarios cadastrados." << endl;
        }
        else
        {
            for (Veterinario &veterinario : veterinarios) //Percorre o vetor de veterinario e exibe um por um na tela
            {
                cout << veterinario << endl;
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

//Mostra na tela todos os funcionarios cadastrados
void Administrador::visualizarVendedores(vector<Vendedor> &vendedor)
{
    if (this->getStatusLog())
    {
        if (vendedor.empty()) //Verifica se o usuário está logado para realizar essa funcção
        {
            cout << "Não há vendedor cadastrados." << endl;
        }
        else
        {
            for (Vendedor &vendedor : vendedor) //Percorre o vetor de vendedor e exibe um por um na tela
            {
                cout << vendedor << endl;
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

bool Administrador::cadastrarVendedor(vector<Vendedor> &vendedores, Vendedor &vendedor)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        vendedores.push_back(vendedor); //Adiciona o vendedor no vetor de vendedores
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

bool Administrador::cadastrarVeterinario(vector<Veterinario> &veterinarios, Veterinario &veterinario)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        veterinarios.push_back(veterinario); //Adiciona o vendedor no vetor de vendedores
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

bool Administrador::pagarConta(vector<Conta> &contas, int id)
{
    int iterator = 0;
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        if (contas.empty()) //Verifica se há contas
        {
            cout << "Não há contas cadastrados." << endl;
        }
        else
        {
            for (Conta &conta : contas)
            {
                if (conta.getId() == id) //Busca a conta pelo ID
                {
                    if (conta.getEstaPaga()) //Verifica se a conta já está paga
                        return false;
                    conta.setDataPagto(); //registra a data do pagamento
                    conta.setEstaPaga();  //sinaliza que agora a conta está paga
                    return true;
                }
                iterator++;
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

bool Administrador::comprar(vector<Produto> &produtos, vector<Conta> &contas, Produto &produto, Conta &conta)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa funcção
    {
        produtos.push_back(produto); //Adiciona o produto comprado do estoque (vetor produtos)
        contas.push_back(conta);     //Adiciona a conta referente a compra às contas
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

//Exibe na tela as contas existentes que não estão pagas
bool Administrador::visualizarContas(vector<Conta> &contas)
{
    int count = 0;
    for (Conta &conta : contas)
    {
        if (!conta.getEstaPaga())
        {
            cout << conta;
            count += 1;
        }
    }

    if (count == 0)
    {
        cout << "Não há nenhuma conta à ser paga." << endl;
        return false;
    }

    return true;
}

//Relatório que mostra em tela as contas que existem  (pagas e não pagas) e as vendas realizadas
void Administrador::gerarRelatorio(vector<Conta> &contas, vector<Venda> &vendas)
{
    if (this->getStatusLog()) //Verifica se o usuário está logado para realizar essa função
    {
        cout << FONT_COLOR_PRIMARY << "\nContas" << RESET_COLOR << endl;
        if (contas.empty())
            cout << "Não há contas registradas.\n";
        else
        {
            for (Conta &conta : contas)
                cout << conta << endl; //imprime todas as contas na tela
        }

        cout << FONT_COLOR_PRIMARY << "\n\nVendas" << RESET_COLOR << endl;
        if (vendas.empty())
            cout << "Não há vendas registradas.\n";
        else
        {
            for (Venda &venda : vendas)
                cout << venda << endl; //imprime todas as vendas na tela
        }
    }
    else
    {
        cerr << "Erro: Ação não permitida, faça o login." << endl;
        cerr << "Pressione enter para continuar... ";
        getchar();
    }
}

bool Administrador::verificarLogin(string usuario, string senha)
{
    if (usuario == USUARIO && senha == SENHA) //compara o usuario e asenha com o padrão do administrador definido como admin admin
    {
        this->setStatusLog(true);
        return true;
    }
    this->setStatusLog(false);
    return false;
}
