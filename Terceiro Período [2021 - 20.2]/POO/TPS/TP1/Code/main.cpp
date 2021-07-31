#include <string>
#include <iostream>
#include <vector>

#include <cstring>
#include <termios.h>

#include "Registros.hpp"
#include "Estilos.hpp"

// === Termios ===
#define STDIN_FILENO 0
#define CH_TERMINAL_H 80
#define CH_TERMINAL_V 24

//Enum para keys das setas do teclado
enum Arrow
{
  UP,
  DOWN,
  OTHER
};

using namespace std;

void printTabelaMenu(char *tituloMenu, string arrOp[], int numOp, int selected);

int menu(string arrOp[], int numOp, char *tituloMenu);

void printTitle(string title);

bool login(string &usuario, string &senha);

int menuGerenciaFuncionarios(Administrador &adm, Registros &reg);

int menuVendedor(Vendedor &vend, Registros &registro);

int menuVeterinario(Veterinario &vet, Registros &reg);

int menuAdministrador(Administrador &adm, Registros &reg);

Vendedor registrarVendedor();

void pressEnter();

int main()
{
  Registros reg;
  Vendedor vend;
  Veterinario vet;
  Administrador adm;
  int state = -1;

  char tMenuIni[] = "    Menu Inicial    ";
  string arrMenuIni[] = {
      "Administrador       ",
      "Vendedor            ",
      "Veterinario         ",
      "Sair                "};

  string usuario, senha;

  while (state != 4)
  {
    state = menu(arrMenuIni, ((*(&arrMenuIni + 1) - arrMenuIni)), tMenuIni);

    if (state == 1)
    { //menu administrados
      if (!adm.getStatusLog())
      {
        login(usuario, senha);
        if (!adm.verificarLogin(usuario, senha))
        { //Senha e/ou usuario incorretos
          cerr << "Error: Usuario ou senha incorreto. Press Enter to Continue ..." << endl;
          getchar();
          continue;
        }
      }
      state = menuAdministrador(adm, reg);
      if (state == 4) //se saiu volta para o menu inicial
        state = 0;
    }
    else if (state == 2)
    { //menu vendedor
      if (!vend.getStatusLog())
      {
        login(usuario, senha);
        vend = vend.verificarLogin(reg.vendedores, usuario, senha);
        if (!vend.getStatusLog())
        { //Senha e/ou usuario incorretos
          cerr << "Error: Usuario ou senha incorreto. Press Enter to Continue ..." << endl;
          getchar();
          continue;
        }
      }
      state = menuVendedor(vend, reg);
      if (state == 4) //se saiu volta para o menu inicial
        state = 0;
    }
    else if (state == 3)
    { //menu veterinario
      if (!vet.getStatusLog())
      {
        login(usuario, senha);
        vet = vet.verificarLogin(reg.veterinarios, usuario, senha);
        if (!vet.getStatusLog())
        { //Senha e/ou usuario incorretos
          cerr << "Error: Usuario ou senha incorreto. Press Enter to Continue ..." << endl;
          getchar();
          continue;
        }
      }
      state = menuVeterinario(vet, reg);
      if (state == 4) //se saiu volta para o menu inicial
        state = 0;
    }
  }

  return 0;
}

void pressEnter()
{
  cerr << "Pressione enter para continuar ...";
  getchar();
}

int menuAdministrador(Administrador &adm, Registros &reg)
{
  int state = 0;

  char tMenu[] = "   Menu do Administrador   ";
  string arrMenu[] = {
      "Gerenciador de funcionario ",
      "Clientes cadastrados       ",
      "Pagar conta                ",
      "Comprar                    ",
      "Relatorio                  ",
      "Sair                       "};

  while (state != 6)
  {
    state = menu(arrMenu, ((*(&arrMenu + 1) - arrMenu)), tMenu);
    if (state == 1)
    { //gerenciar os funcionarios
      state = menuGerenciaFuncionarios(adm, reg);
    }
    else if (state == 2)
    { //vosualizar clientes cadastrados
      printTitle("Clientes cadastrados");
      adm.visualizarClientes(reg.clientes);
      pressEnter();
    }
    else if (state == 3)
    { //pagar conta
      printTitle("Pagar conta");
      if (adm.visualizarContas(reg.contas))
      { //se houver contas à pagar
        cout << endl;
        int id;
        cout << "ID: ";
        cin >> id;
        if (!adm.pagarConta(reg.contas, id))
        {
          cerr << RED_ALERT << "Error: Não foi possivel pagar conta." << RESET_COLOR << endl;
          cerr << "Press Enter to Continue ..." << endl;
          getchar();
        }
        getchar();
        pressEnter();
      }
      else
      {
        pressEnter();
      }
    }
    else if (state == 4)
    { //comprar produto
      printTitle("Comprar");
      int quantidade;
      float valor;
      string nome, animal;
      cout << FONT_COLOR << "Sobre o produto" << RESET_COLOR << endl;
      cout << "Nome: ";
      getline(cin, nome);
      cout << "Animal: ";
      getline(cin, animal);
      cout << "Valor p/ unidade: ";
      cin >> valor;
      cout << "Quantidade: ";
      cin >> quantidade;

      int dia, mes, ano;
      string descricao;
      cout << FONT_COLOR << "Sobre a conta" << RESET_COLOR << endl;
      cout << "Data de vencimento" << endl;
      cout << "Dia: ";
      cin >> dia;
      cout << "Mês: ";
      cin >> mes;
      cout << "Ano: ";
      cin >> ano;
      cin.ignore();
      cout << "Descrição da conta: ";
      getline(cin, descricao);

      DataHorario dataVenc(dia, mes, ano, 23, 59);
      Produto nProduto(quantidade, valor, nome, animal);
      Conta nConta(dataVenc, descricao, (valor * quantidade));
      if (!adm.comprar(reg.produtos, reg.contas, nProduto, nConta))
      {
        cerr << RED_ALERT << "Error: Não foi possivel realizar compra." << RESET_COLOR << endl;
        cerr << "Press Enter to Continue ..." << endl;
        getchar();
      }
      pressEnter();
    }
    else if (state == 5)
    { //relatorio de contas e vendas
      printTitle("Relatorio");
      adm.gerarRelatorio(reg.contas, reg.vendas);
      pressEnter();
    }
  }

  adm.setStatusLog(false);
  return state;
}

int menuVeterinario(Veterinario &vet, Registros &reg)
{
  string nome, usuario, senha;
  int state = 0;

  char tMenu[] = "      Menu do Veterinario    ";
  string arrMenu[] = {
      "Visualizar ordem de servico  ",
      "Gerar relatorio              ",
      "Visualizar clientes          ",
      "Sair                         "};

  while (state != 4)
  {
    state = menu(arrMenu, ((*(&arrMenu + 1) - arrMenu)), tMenu);
    if (state == 1)
    {
      printTitle("Ordens de serviços");
      vet.visualizarOrdem(reg.ordensservico);
      pressEnter();
    }
    else if (state == 2)
    { // gerar relatorio
      printTitle("Gerar relatorio");
      int id;
      string relatorio;
      cout << "ID da ordem de serviço: ";
      cin >> id;
      cin.ignore();
      cout << "Relatorio: ";
      getline(cin, relatorio);
      if (!vet.registraRelatorio(reg.ordensservico, relatorio, id))
      {
        cerr << RED_ALERT << "Error: Não foi possivel gerar relatorio." << RESET_COLOR << endl;
        cerr << "Press Enter to Continue ..." << endl;
        getchar();
      }
      pressEnter();
    }
    else if (state == 3)
    { //visualizar clientes
      printTitle("Clientes cadastrados");
      vet.visualizarCliente(reg.clientes);
      pressEnter();
    }
  }

  vet.setStatusLog(false);
  return state;
}

int menuVendedor(Vendedor &vend, Registros &reg)
{
  int state = 0;

  char tMenu[] = "      Menu do Vendedor     ";
  string arrMenu[] = {
      "Cadastrar cliente          ",
      "Realizar venda de produto  ",
      "Gerar ordem de serviço     ",
      "Sair                       "};

  while (state != 4)
  {
    state = menu(arrMenu, ((*(&arrMenu + 1) - arrMenu)), tMenu);
    if (state == 1)
    { //cadastra cliente
      printTitle("Cadastro de cliente");
      string nome, endereco;
      cout << "Nome: ";
      getline(cin, nome);
      cout << "Endereco: ";
      getline(cin, endereco);
      Cliente newCliente(nome, endereco);
      if (!vend.cadastrarCliente(reg.clientes, newCliente))
      {
        cerr << RED_ALERT << "Error: Não foi possivel cadastrar novo cliente. " << RESET_COLOR << endl;
        cerr << "Press Enter to Continue ..." << endl;
        getchar();
      }
      pressEnter();
    }
    else if (state == 2)
    { //vender produto
      printTitle("Venda de produto");
      vend.visualizarProdutos(reg.produtos);
      int id, quantidade;
      cout << "ID: ";
      cin >> id;
      cout << "Quantidade: ";
      cin >> quantidade;
      if (!vend.realizarVenda(reg.produtos, reg.vendas, id, quantidade))
      {
        cerr << RED_ALERT << "Erro: Não foi possivel realizar venda" << RESET_COLOR << endl;
      };
      pressEnter();
      getchar();
    }
    else if (state == 3)
    { //gerar ordem de serviço
      printTitle("Gerar ordem de serviço");
      int iServico;
      do
      { //valida até ser um servico valido
        cout << FONT_COLOR_PRIMARY << "Tipo de Servico" << RESET_COLOR << endl;
        cout << "1 - " << reg.servicos[0].getNome() << " | 2 - " << reg.servicos[1].getNome() << endl;
        cin >> iServico;
      } while (iServico != 1 && iServico != 2);

      int dia, mes, ano, hora, minuto;
      cout << FONT_COLOR_PRIMARY << "Data do servico" << RESET_COLOR << endl;
      cout << "Dia: ";
      cin >> dia;
      cout << "Mês: ";
      cin >> mes;
      cout << "Ano: ";
      cin >> ano;
      cout << "Hora: ";
      cin >> hora;
      cout << "Minuto: ";
      cin >> minuto;
      DataHorario nData(dia, mes, ano, hora, minuto);
      Cliente nCliente;

      string nome;
      int escolha;
      if (reg.clientes.empty())
      { //nao existir clientes cadastrados
        cout << "Ainda não há clientes cadastrados" << endl;
        escolha = 2;
      }
      else
      {
        cout << "Cliente é cadastrado? " << endl
             << "1 - Sim | 2 - Nao" << endl;
        cin >> escolha;
      }
      if (escolha == 1)
      { //cliente eh cadastrado
        int id;
        bool clientExist = false;
        vend.visualizarCliente(reg.clientes);
        cout << endl;
        do
        { //garante que o ID seja valido
          cout << "Escolha o cliente pelo ID" << endl;
          cin >> id;
          nCliente = vend.getClienteById(reg.clientes, id, clientExist);
          if (!clientExist)
            cout << "Nenhum cliente foi encontrado com ID " << id << ". Tente novamente" << endl;
        } while (!clientExist);

        getchar();
      }
      else if (escolha == 2)
      { //não cadastrado
        cin.ignore();
        cout << "Nome do cliente: ";
        getline(cin, nome);
        cout << "Deseja cadastrar " << nome << " como cliente?" << endl
             << "1-Sim | 2-Nao" << endl;
        cin >> escolha;
        getchar();
        if (escolha == 1)
        { //cadastrar um novo cliente
          string endereco;
          cout << "Endereço: ";
          getline(cin, endereco);
          nCliente.setId();
          nCliente.setNome(nome);
          nCliente.setEndereco(endereco);
          if (!vend.cadastrarCliente(reg.clientes, nCliente))
          {
            cerr << RED_ALERT << "Error: Não foi possivel cadastrar usuario." << RESET_COLOR << endl;
            cerr << "Press Enter to Continue ..." << endl;
            getchar();
          };
        }
      }
      else
        cout << "Escolha inválida!" << endl;

      string nAnimal, nRelatorio;
      cout << "Animal: ";
      getline(cin, nAnimal);
      if (escolha == 1)
      { //Com cliente cadastrado
        OrdemServico newOrdemServico(reg.servicos[iServico - 1], nData, nCliente, nAnimal);
        if (!vend.realizarOrdemServico(reg.ordensservico, reg.vendas, reg.servicos[iServico - 1], newOrdemServico))
        {
          cerr << RED_ALERT << "Error: Não foi possivel gerar ordem de servico. " << RESET_COLOR << endl;
          cerr << "Press Enter to Continue ..." << endl;
          getchar();
        }
      }
      else
      { //Com cliente sem cadastrar no sistema
        OrdemServico newOrdemServico(reg.servicos[iServico - 1], nData, nome, nAnimal);
        if (!vend.realizarOrdemServico(reg.ordensservico, reg.vendas, reg.servicos[iServico - 1], newOrdemServico))
        {
          cerr << RED_ALERT << "Error: Não foi possivel gerar ordem de servico. " << RESET_COLOR << endl;
          cerr << "Press Enter to Continue ..." << endl;
          getchar();
        }
      }
      pressEnter();
    }
  }

  vend.setStatusLog(false);
  return state;
}

int menuGerenciaFuncionarios(Administrador &adm, Registros &reg)
{
  string nome, usuario, senha;
  float salario;
  int state = 0;

  char tMenu[] = "   Gerenciador de funcionario   ";
  string arrMenu[] = {
      "Cadastrar vendedor              ",
      "Cadastrar veterinario           ",
      "Veterinarios cadastrados        ",
      "Vendedores cadastrados          ",
      "Sair                            "};

  while (state != 5)
  {
    state = menu(arrMenu, ((*(&arrMenu + 1) - arrMenu)), tMenu);
    if (state == 1)
    { //cadastra vendedor
      printTitle("Cadastrar vendedor");
      cout << "Nome: ";
      getline(cin, nome);
      cout << "Usuario: ";
      getline(cin, usuario);
      cout << "Senha: ";
      cin >> senha;
      cout << "Salario: ";
      cin >> salario;
      Vendedor nVendedor(nome, usuario, senha, salario);
      if (!adm.cadastrarVendedor(reg.vendedores, nVendedor))
      {
        cerr << RED_ALERT << "Error: Não foi possivel cadastrar novo vendedor. " << RESET_COLOR << endl;
        cerr << "Press Enter to Continue ..." << endl;
        getchar();
      }
      getchar();
      pressEnter();
    }
    else if (state == 2)
    { //cadastrar veterinario
      printTitle("Cadastrar veterinario");
      cout << "Nome: ";
      getline(cin, nome);
      cout << "Usuario: ";
      getline(cin, usuario);
      cout << "Senha: ";
      cin >> senha;
      cout << "Salario: ";
      cin >> salario;
      Veterinario nVeterinario(nome, usuario, senha, salario);
      if (!adm.cadastrarVeterinario(reg.veterinarios, nVeterinario))
      {
        cerr << RED_ALERT << "Error: Não foi possivel cadastrar novo veterinario. " << RESET_COLOR << endl;
        cerr << "Press Enter to Continue ..." << endl;
        getchar();
      }
      getchar();
      pressEnter();
    }
    else if (state == 3)
    { //veterinarios cadastrados
      printTitle("Veterinarios cadastrados");
      adm.visualizarVeterinarios(reg.veterinarios);
      pressEnter();
    }
    else if (state == 4)
    { //vendores cadastrados
      printTitle("Vendedores cadastrados");
      adm.visualizarVendedores(reg.vendedores);
      pressEnter();
    }
  }

  return state;
}

bool login(string &usuario, string &senha)
{
  printTitle("Fazer Login");
  cout << FONT_COLOR_PRIMARY << "Usuario: ";
  getline(cin, usuario);
  cout << FONT_COLOR_PRIMARY << "Senha: ";
  cin >> senha;
  getchar();
  return true;
}

void printTitle(string title)
{
  //Print titulo com cores ANSI
  system("clear");
  cout
      << BACKGROUND_COLOR << FONT_COLOR
      << title
      << RESET_COLOR << endl;
}

int menu(string arrOp[], int numOp, char *tituloMenu)
{
  // To prevent Linux from buffering keystrokes.
  struct termios oldattr, newattr;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

  Arrow arrow; //Enum for key keyboard
  char c, d, e;
  int state = 0;

  system("clear");

  printTabelaMenu(tituloMenu, arrOp, numOp, state);

  while (1)
  {
    c = cin.get();
    if (c != 27)
    {
      if ((int)c == 10)
      {
        //cout << "Enter key was pressed\n";
        break;
      }
      goto reset_screen;
    }
    d = cin.get();
    e = cin.get();

    // Using 3 char type, Cause up down right left consist with 3 character
    if ((c == 27) && (d = 91))
    {
      if (e == 65)
      {
        arrow = UP;
      }
      else if (e == 66)
      {
        arrow = DOWN;
      }
      else if (e == 67 || e == 68) // RIGHT or LEFT
      {
        arrow = OTHER;
      }
    }

    if (arrow == 0)
    {
      if (state != 0)
        state -= 1;
      else
        state = (numOp - 1);
    }
    else if (arrow == 1)
    {
      if (state != (numOp - 1))
        state += 1;
      else
        state = 0;
    }

  reset_screen:
    system("clear");

    printTabelaMenu(tituloMenu, arrOp, numOp, state);
  }

  // To prevent Linux from buffering keystrokes
  system("stty echo");
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

  return (state + 1);
}

void printTabelaMenu(char *tituloMenu, string arrOp[], int numOp, int selected)
{
  int i;
  string tab = "     ";
  int strsTam = (unsigned)strlen(tituloMenu);
  int n = (strsTam + 15); //Tamanho da largura do menu
  if (n % 2 == 0)
    n += 1;
  int m = n - strsTam; // Tamanho da largura do menu - tamanho do titulo

  //=== Linha superior ===
  cout
      << OUTER_ULCORNER << BACKGROUND_COLOR << FONT_COLOR << tituloMenu << RESET_COLOR;
  for (i = 0; i < m; i++)
    cout << HOR_LINE;
  cout << INNER_URCORNER;
  cout << "\n";

  //=== Linha vazia ===
  cout << VER_LINE;
  for (i = 1; i <= n; i++)
    cout << " ";
  cout << VER_LINE << "\n";

  int k = n - (strsTam + 5 + 5); //Quantidade de espaços após a opção
  char *espacoPos = new char[k]; //Espaços após a opção
  for (i = 0; i < k; i++)
    espacoPos[i] = ' ';

  for (i = 1; i <= numOp; i++)
  {
    cout << VER_LINE;
    if ((i - 1) == selected)
      cout
          << tab
          << FONT_COLOR_PRIMARY << ARROW << "    "
          << BACKGROUND_COLOR << FONT_COLOR << arrOp[i - 1] << RESET_COLOR;
    else
      cout << tab
           << "     "
           << FONT_COLOR_PRIMARY << arrOp[i - 1] << RESET_COLOR;

    cout << espacoPos << VER_LINE << "\n";
  }

  //=== Linha vazia ===
  cout << VER_LINE;
  for (i = 1; i <= n; i++)
    cout << " ";
  cout << VER_LINE << "\n";

  //=== Linha inferior ===
  cout << OUTER_LLCORNER;
  for (i = 0; i < n; i++)
    cout << HOR_LINE;
  cout << INNER_LRCORNER;
  cout << "\n";

  delete[] espacoPos;
}