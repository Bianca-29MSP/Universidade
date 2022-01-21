#ifndef SYSTEM_CPP
#define SYSTEM_CPP

#include <vector>
#include "string"

using namespace std;

//! Class System
/**
* Está classe representa o sistema/estoque da simulação.
*/
class System {
    private:
        string name; /*!< Esse atributo possui o nome do sistema */
        double value; /*!< Esse atributo possui o valor armazenado no sistema */
    protected:
    public:
        /*!
            Esse é o construtor padrão da classe System.
        */
        System(); 

        /*!
            Esse é um construtor que possui atributo inicial para o sistema.
            \param name nome do sistema.
        */
        System(string name);

        /*!
            Esse é o destrutor padrão da classe System.
        */
        virtual ~System();

        /*!
            Seta o nome do sistema
            \param name - o nome do sistema.
        */
        void setName(string name);

        /*!
            Retorna o nome do sistema.
            \return string - o nome do sistema.
        */
        string getName();

        /*!
            Seta o valor armazenado pelo sistema
            \param value - o valor a ser armazenado.
        */
        void setValue(double value);

        /*!
            Retornao valor armazenado pelo sistema
            \return double - o valor armazenado.
        */
        double getValue();

        /*!
            Operador de atribuição (=) sobrecarregado para a classe System.
        */
        System& operator=(const System&);
};

#endif
