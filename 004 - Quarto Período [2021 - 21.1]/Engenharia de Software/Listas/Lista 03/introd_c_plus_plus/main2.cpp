#include <cstdlib>
#include <iostream>

using namespace std;
            
// QUEST�O 1: O c�digo desse exerc�cio � id�ntico ao do exerc�cio anterior. 
//          Por�m o operador "<<" foi sobrecarregado para permitir que 
//          programador implemente de maneira mais f�cil a sa�da do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1; 
//          
//          a) Explique porque o m�todo que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa? 
//          R.: Utilizando friend a classe permite que essa função de sobrecarga 
//          acesse atributos privados da classe e essa função pode ser invocada sem a 
//          necessidade de um objeto da classe.
//          b) Explique o funcionamento do novo operador "<<".
//          R.: A função de sobrecarga do operador “<<” retorna uma referência a um objeto
//          ostream, que neste caso retorna uma string que se refere a variável orc.
//

class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUEST�O 2: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
// R.: Inicialmente um objeto do tipo Casa, c1, é instanciado pelo construtor 
//  com orc = 7 e o endereço da outra váriavel do tipo Casa, c2, é o mesmo endereço de 
//  c1, ou seja, tudo que mudar em uma muda na outra, pois as duas pertencem à mesma 
//  unidade de memória.  
//  	SAÍDA:	
//          (1) Casa criada…
//          (2) C1: 7, C2: 7
//          (3) C1: 3, C2: 3
//          
//          (1) cout presente no construtor ao instanciar c1.
//          (2) Como c1 e c2 referencia na mesma porção na memória o valor de orc das duas variáveis é o mesmo.
//          (3) Antes disso, c2 trocou o valor de orc para 3 e acontece a mesma coisa que aconteceu na saída (3).

int main(int argc, char *argv[])
{
    Casa c1(7), &c2 = c1;
    
    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;
    c2.setOrc(3);
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

