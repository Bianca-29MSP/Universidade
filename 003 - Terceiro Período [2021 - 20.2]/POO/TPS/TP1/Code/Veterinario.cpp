#include "Veterinario.hpp"

Veterinario ::Veterinario(string nome,
                          string usuario,
                          string senha,
                          float salario) : Usuario(nome, salario, usuario, senha)
{
}

Veterinario::~Veterinario() {}

//Função que visualiza ordem de serviço
void Veterinario::visualizarOrdem(vector<OrdemServico> &ordens)
{
    if (this->getStatusLog())
    { //Caso veterinario não estej autenticado no login
        if (ordens.empty())
        { //Caso não tenha ordens cadastradas
            cout << "Não há ordens cadastradas." << endl;
        }
        else
        {
            for (OrdemServico &ordem : ordens)
            { //
                if (ordem.getServico().getNome() == "Consulta")
                    cout << ordem << endl
                         << endl;
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

bool Veterinario::registraRelatorio(vector<OrdemServico> &ordens, string relatorio, int id)
{
    if (this->getStatusLog())
    { //Caso veterinario não estej autenticado no login
        if (ordens.empty())
        { //Caso não tenha clientes cadastrados
            cout << "Não há ordens cadastradas." << endl;
        }
        else
        {
            for (OrdemServico &ordem : ordens)
            {
                if (ordem.getId() == id)
                    ordem.setRelatorio(relatorio);
                return true;
            }
        }
        return false;
    }
    else
    {
        cerr << "Erro: Ação não permitida, faça o login." << endl;
        cerr << "Pressione enter para continuar... ";
        getchar();
    }
    return false;
}

void Veterinario::visualizarCliente(vector<Cliente> &clientes)
{
    if (this->getStatusLog())
    { //Caso veterinario não estej autenticado no login
        if (clientes.empty())
        { //Caso não tenha clientes cadastrados
            cout << "Não há clientes cadastrados." << endl;
        }
        else
        {
            for (Cliente &cliente : clientes)
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

Veterinario &Veterinario::verificarLogin(vector<Veterinario> &veterinarios, string usuario, string senha)
{
    Login<Veterinario> login; //utilização da classe template
    return login.verificarLogin(veterinarios, usuario, senha);
}
