#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <assert.h>

#include "Estudante.hpp"
#include "ConjOrdenado.hpp"
#include "ConjNaoOrdenado.hpp"
#include "Disciplina.hpp"
#include "Estatistica.cpp"

#define TEST

using namespace std;

bool ord(Estudante i1, Estudante i2) 
{
    return (i1.getNome() < i2.getNome());
}

#ifdef TEST
int main( int argc, char *argv[] )
{
    //Instanciando estudantes
    Estudante es1("estudante5", "medicina", 1924678, (float)9);
    Estudante es2("estudante0", "medicina", 1924671, (float)3);
    Estudante es3("estudante6", "medicina", 1924670, (float)9);
    Estudante es4("estudante9", "medicina", 1924679, (float)8);
    Estudante es5("estudante2", "medicina", 1924677, (float)5);

    //Teste
    assert(es1.getNome() == "estudante5");
    assert(es1.getCurso() == "medicina");
    assert(es1.getMatricula() == 1924678);
    assert(es1.getCoeficiente() == (float)9);

    cout << "Done [Estudantes]!" << endl;
    

    //Conjutos de estudantes
    ConjNaoOrdenado<Estudante> conjuntoNaoOrd__estudante;
    conjuntoNaoOrd__estudante.add(es1);
    conjuntoNaoOrd__estudante.add(es2);
    conjuntoNaoOrd__estudante.add(es3);
    conjuntoNaoOrd__estudante.add(es4);
    conjuntoNaoOrd__estudante.add(es5);

    //Testes
    assert(conjuntoNaoOrd__estudante[0] == "estudante5");
    assert(conjuntoNaoOrd__estudante[1] == "estudante0");
    assert(conjuntoNaoOrd__estudante[2] == "estudante6");
    assert(conjuntoNaoOrd__estudante[3] == "estudante9");
    assert(conjuntoNaoOrd__estudante[4] == "estudante2");

    cout << "Done [Estudante Conjunto nao Ordenado]!" << endl;

    //Conjutos de estudantes
    ConjOrdenado<string, Estudante> conjuntoOrd__estudante;
    conjuntoOrd__estudante.add(es1.getNome(), es1);
    conjuntoOrd__estudante.add(es2.getNome(), es2);
    conjuntoOrd__estudante.add(es3.getNome(), es3);
    conjuntoOrd__estudante.add(es4.getNome(), es4);
    conjuntoOrd__estudante.add(es5.getNome(), es5);

    assert(conjuntoOrd__estudante[0] == "estudante0");
    assert(conjuntoOrd__estudante[1] == "estudante2");
    assert(conjuntoOrd__estudante[2] == "estudante5");
    assert(conjuntoOrd__estudante[3] == "estudante6");
    assert(conjuntoOrd__estudante[4] == "estudante9");

    cout << "Done [Estudante Conjunto Ordenado]!" << endl;

    //Estatisticas
    assert(count(conjuntoOrd__estudante.getConjunto(), (float)9) == 2);
    assert(sum(conjuntoOrd__estudante.getConjunto()) == (float)34);
    assert(average(conjuntoOrd__estudante.getConjunto()) == (float)6.8);
    

    cout << "Done [Estudante Estatistica]!" << endl;


    //Instanciando disciplinas
    Disciplina disc1("DECOM", "disciplina4", "BCC201", 40, 35);
    Disciplina disc2("DECOM", "disciplina6", "BCC267", 40, 30);
    Disciplina disc3("DEMAT", "disciplina0", "MAT409", 60, 59);
    Disciplina disc4("DEMAT", "disciplina3", "MAT34", 60, 47);
    Disciplina disc5("DECOM", "disciplina9", "BCC205", 40, 23);

    //Teste
    assert(disc1.getNome() == "disciplina4");
    assert(disc1.getDepartamento() == "DECOM");
    assert(disc1.getCodigo() == "BCC201");
    assert(disc1.getVagasDisponiveis() == 5);

    cout << "Done [Disciplina]!" << endl;

    //Conjuntos de desciplinas
    ConjNaoOrdenado<Disciplina> conjuntoNaoOrd__disciplina;
    conjuntoNaoOrd__disciplina.add(disc1);
    conjuntoNaoOrd__disciplina.add(disc2);
    conjuntoNaoOrd__disciplina.add(disc3);
    conjuntoNaoOrd__disciplina.add(disc4);
    conjuntoNaoOrd__disciplina.add(disc5);

    //Testes
    assert(conjuntoNaoOrd__disciplina[0].getNome() == "disciplina4");
    assert(conjuntoNaoOrd__disciplina[1].getNome() == "disciplina6");
    assert(conjuntoNaoOrd__disciplina[2].getNome() == "disciplina0");
    assert(conjuntoNaoOrd__disciplina[3].getNome() == "disciplina3");
    assert(conjuntoNaoOrd__disciplina[4].getNome() == "disciplina9");

    cout << "Done [Disciplina Conjunto nao Ordenado]!" << endl;

    //Conjuntos de desciplinas
    ConjOrdenado<string, Disciplina> conjuntoOrd__disciplina;
    conjuntoOrd__disciplina.add(disc1.getNome(), disc1);
    conjuntoOrd__disciplina.add(disc2.getNome(), disc2);
    conjuntoOrd__disciplina.add(disc3.getNome(), disc3);
    conjuntoOrd__disciplina.add(disc4.getNome(), disc4);
    conjuntoOrd__disciplina.add(disc5.getNome(), disc5);
    
    assert(conjuntoOrd__disciplina[0].getNome() == "disciplina0");
    assert(conjuntoOrd__disciplina[1].getNome() == "disciplina3");
    assert(conjuntoOrd__disciplina[2].getNome() == "disciplina4");
    assert(conjuntoOrd__disciplina[3].getNome() == "disciplina6");
    assert(conjuntoOrd__disciplina[4].getNome() == "disciplina9");

    cout << "Done [Disciplina Conjunto Ordenado]!" << endl;

    //Estatisticas
    assert(count(conjuntoOrd__disciplina.getConjunto(), "DECOM") == 3);
    assert(sum(conjuntoOrd__disciplina.getConjunto()) == 46);
    assert(average(conjuntoOrd__disciplina.getConjunto()) == (float)9.2);

    cout << "Done [Disciplina Estatistica]!" << endl;

    return 0;
}

#else
int main( int argc, char *argv[] )
{
    
    return 0;
}

#endif
