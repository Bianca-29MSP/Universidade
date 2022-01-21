#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUEST�O 1: Critique o c�digo abaixo e aponte seus problemas com rela��o:
//          a) � flexibilidade da implementa��o: altera��es em pequenos trechos 
//             do c�digo n�o deveriam exigir recodifica��o de outras partes
//          b) � legibilidade do c�digo: lendo o c�digo � f�cil entrender os 
//             objetos e processos que ele representa. Qual � seu objetivo?
//          R.: O código não apresenta uma boa legibilidade devido aos nomes das variáveis, por elas não dá pra saber de fato o que cada uma representa e armazena. E por esse motivo o objetivo não é claro, mas pode-se resumir o objetivo como algo simples, criar um objeto Casa com dois atributos, uma float e um int.

class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na quest�o 1.
class Casa {
      // Coloque suas corre��es aqui..
      float price;
      int number;
public:
      Casa( float price, int number ):price(price), number(number){ cout << "Casa criada..." << endl; }
      void setPrice( float price ) { this->price = price; }
      float getPrice( void ) const { return price; }
      void setNumber( float number ) { this->number = number; }
      float getNumber( void ) const { return number; }
};
// ...e aqui se necess�rio.
#endif

// QUESTAO 3: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
// R.: Inicialmente cria-se um objeto de Casa chamado c1 com orc = 7, logo um apontador para Casa c2 aponta para o endereço de memória de c1, e por fim a variável c3 tem seu endereço na memória igual ao de c1, ou seja, essa variável se refere a mesma porção de memória de c1, pode-se imaginar como sendo a mesma variável.
//	SAÍDA:
//            (1)Casa criada…
//            (2)C1: 7
//            (3)C2: 3, C3: 3
//            (4)C2: 0x7ffff111a2e0, C3: 0x7ffff111a2e0
//
//            (1) A saída se refere ao cout presente no construtor ao instanciar a variável c1.
//            (2)Através do getOrc() é retornado o valor de orc que no momento é 7.
//            (3)Antes dessa saída, o valor de orc de c1 foi mudado para 3 e como c2 aponta para o endereço de c1, o valor impresso em tela é 3, assim como c3 se refere ao mesmo endereço que c1 e também imprime 3.
//            (4)c2 aponta para o endereço de c1 e c3 tem o mesmo endereço que c1, por isso na saída mostra o endereço.

int main(int argc, char *argv[])
{
    Casa c1(7), *c2 = &c1, &c3 = c1;
    
    cout << "C1: " << c1.getOrc() << endl;
    c1.setOrc(3);
    cout << "C2: " << c2->getOrc() << ", ";
    cout << "C3: " << c3.getOrc() << endl;
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?
// R.: Uma vez. O construtor foi invocado apenas em Casa c1(7).