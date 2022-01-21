#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"
#include "string"

using namespace std;

//! Struct System
/**
* Está estrutura representa a esquação armazenada e executada pelo fluxo(flow)
*/
struct Equation {
    double constant; /*!< Esse variavl possui a constante da equação */
    int PMax; /*!< Esse variavl possui o PMax da equação */
    string observedSystem; /*!< Esse variavl possui o nome do sistema observado pelo fluxo na equação */
};

//! Class Flow
/**
* Está classe representa fluxo da simulação.
*/
class Flow {
    private:
        //Atributos
        string name; /*!< Esse atributo possui o nome do fluxo */

        System *input; /*!< Esse atributo possui um ponteiro para o sistema de entrada do fluxo */
        System *output; /*!< Esse atributo possui um ponteiro para o sistema de saída do fluxo */
        Equation equation; /*!< Esse atributo possui a equação armazenada e executada fluxo */

    protected:
    public:
        /*!
            Esse é o construtor padrão da classe Flow
        */
        Flow();

        /*!
            Esse é um construtor que possui atributo inicial para o fluxo
            \param name o nome do fluxo.
        */
        Flow(string name);

        /*!
            Esse é o destrutor padrão da classe Flow
        */
        virtual ~Flow();

        /*!
            Seta o ponteiro para o sistema de entrada do fluxo.
            \param input - ponteiro para um sistema.
        */
        void setInput(System * input);

        /*!
            Retorna o ponteiro do sistema de entrada do fluxo.
            \return System * - ponteiro para um sistema.
        */
        System * getInput(void);

        /*!
            Seta o ponteiro para o sistema de saída do fluxo.
            \param output - ponteiro um sistema.
        */
        void setOutput(System * output);

        /*!
            Retorna o ponteiro do sistema de saída do fluxo.
            \return System * - ponteiro para um sistema.
        */
        System * getOutput(void);

        /*!
            Seta os valores para a equação do fluxo exponencial.
            \param constant - constante(taxa) a ser multiplicação na equação.
            \param observedSystem - nome do sistema a ser observado pelo fluxo na equação.
        */
        void setEquation(double constant, string observedSystem);

        /*!
            Seta os valores para a equação do fluxo logístico.
            \param constant - constante(taxa) a ser multiplicação na equação.
            \param observedSystem - nome do sistema a ser observado pelo fluxo na equação.
            \param Pmax - valor máximo em que um sistema pode atingir.
        */
        void setEquation(double constant, string observedSystem, int Pmax);
        
                /*!
            Retorna parte da expressão, o valor contante(taxa).
            \return double - constante da expressão.
        */
        double getConstant() const;

        /*!
            Retorna parte da expressão, o nome do sistema observado pelo fluxo.
            \return string - nome do sistema
        */
        string getObservedSystem() const;

        /*!
            Retorna parte da expressão, o Pmax, valor máximo que o sistema observado pode atingir durante a execução.
            \return int - valor maximo que o sistema observado pode atingir.
        */
        int getPMax() const;

        /*!
            Seta o nome do fluxo
            \param name - o nome do fluxo.
        */
        void setName(string name);

        /*!
            Retorna o nome do fluxo.
            \return string - o nome do fluxo.
        */
        string getName();

        /*!
            Executa a equação exponencial do fluxo.
            \return double - o resultado da equação.
            \param sys - sistema observado pelo fluxo que terá seu valor utililizado na expressão.
        */
        double exponential(System * sys);

        /*!
            Executa a equação logístico do fluxo.
            \return double - o resultado da equação.
            \param sys - sistema observado pelo fluxo que terá seu valor utililizado na expressão.
        */
        double logistical(System * sys);

        /*!
            Executa a equação tanto logístico quanto exponencial, dependendo do fluxo.
            \return double - o resultado do calculo.
        */
        double run();

        /*!
            Operador de atribuição (=) sobrecarregado para a classe Flow.
        */
        Flow& operator=(const Flow& flow);
};

#endif
