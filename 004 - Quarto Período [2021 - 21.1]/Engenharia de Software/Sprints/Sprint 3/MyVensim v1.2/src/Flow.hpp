#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"
#include "string"

using namespace std;

//! Struct System
/**
* Está estrutura representa a esquação armazenada e executada pelo fluxo(flow)
*/
class Flow {
private:
    string name; /*!< Esse atributo possui o nome do fluxo */
    double currentValue; /*!< Esse atributo possui o valor atual do fluxo em determinado tempo */
    System *source; /*!< Esse atributo possui um ponteiro para o sistema de entrada do fluxo */
    System *target; /*!< Esse atributo possui um ponteiro para o sistema de saída do fluxo */

    /*!
        Seta o ponteiro para o sistema de entrada do fluxo.
        \param source - ponteiro para um sistema.
    */
    void setSource(System * source)
    {
        this->source = source;
    }

    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro um sistema.
    */
    void setTarget(System * target)
    {
        this->target = target;
    }
protected:
public:
    /*!
        Esse é o construtor padrão da classe Flow
    */
    Flow(){
        this->source = NULL;
        this->target = NULL;
    }

    /*!
        Esse é um construtor que possui atributo inicial para o fluxo
        \param name o nome do fluxo.
    */
    Flow(string name){
        this->source = NULL;
        this->target = NULL;
        setName(name);
    }

    /*!
        Esse é o destrutor padrão da classe Flow
    */
    virtual ~Flow(){}

    /*!
        Retorna o nome do fluxo.
        \return string - o nome do fluxo.
    */
    string getName()
    {
        return this->name;
    }

    /*!
        Seta o nome do fluxo
        \param name - o nome do fluxo.
    */
    void setName(string name)
    {
        this->name = name;
    }

     /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual.
    */
    double getCurrentValue() const
    {
        return this->currentValue;
    }

    /*!
        Seta o valor atual do fluxo
        \param value - valor atual.
    */
    void setCurrentValue(double value)
    {
        this->currentValue = value;
    }

     /*!
        Retorna o ponteiro do sistema de entrada do fluxo.
        \return System * - ponteiro para um sistema.
    */
    System * getSource(void) const
    {
        return this->source;
    }

    /*!
        Retorna o ponteiro do sistema de saída do fluxo.
        \return System * - ponteiro para um sistema.
    */
    System * getTarget(void) const
    {
        return this->target;
    }

    /*!
        Connecta dois fluxo ao sistema (entrada e saída).
        \param source - ponteiro para um sistema de entrada.
        \param target - ponteiro para um sistema de saída.
    */
    void connect(System *source = NULL, System* target = NULL)
    {
        setSource(source);
        setTarget(target);
    }

    /*!
        Método virtual puro que será herdado por subclasses criadas pelo usuário, essa conterá
        uma equação que será executada no fluxo pelo modelo.
    */
    virtual double execute() = 0;

    /*!
        Operador de atribuição (=) sobrecarregado para a classe Flow.
    */
    Flow* operator=(const Flow* flow)
    {
        if (flow == this)
            return this;

        this->source = flow->source;
        this->target = flow->target;
        this->currentValue = flow->currentValue;

        return this;
    }
};

#endif
