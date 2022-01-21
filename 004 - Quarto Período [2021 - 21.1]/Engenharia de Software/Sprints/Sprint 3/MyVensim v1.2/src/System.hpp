#ifndef SYSTEM_HPP
#define SYSTEM_HPP

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
        Esse é um construtor que possui um atributo inicial para o sistema.
        \param name nome do sistema.
    */
    System(string name){
        setName(name);
    }

     /*!
        Esse é um construtor que possui dois atributos iniciais para o sistema.
        \param name nome do sistema.
        \param value valor inicial do sistema.
    */
    System(string name, double value){
        setName(name);
        setValue(value);
    }

    /*!
        Esse é o destrutor padrão da classe System.
    */
    virtual ~System(){}

    /*!
        Seta o valor armazenado pelo sistema
        \param value - o valor a ser armazenado.
    */
    void setValue(double value)
    {
        this->value = value;
    }

    /*!
        Retornao valor armazenado pelo sistema
        \return double - o valor armazenado.
    */
    double getValue() const
    {
        return this->value;
    }

    /*!
        Retorna o nome do sistema.
        \return string - o nome do sistema.
    */
    string getName() const
    {
        return this->name;
    }

    /*!
        Seta o nome do sistema
        \param name - o nome do sistema.
    */
    void setName(string name)
    {
        this->name = name;
    }

    /*!
        Operador de atribuição (=) sobrecarregado para a classe System.
    */
    System* operator=(const System* system)
    {
        if (system == this)
            return this;

        this->name = system->name;
        this->value = system->value;

        return this;
    }
};

#endif
