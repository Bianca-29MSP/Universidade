#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"
#include "string"

using namespace std;

//! Class Flow
/**
* Está classe representa o flixo da simulação.
*/
class Flow {
private:
string name; /*!< Esse atributo possui o nome do fluxo */
    double currentValue; /*!< Esse atributo possui o valor atual do fluxo em determinado tempo */
    System *source; /*!< Esse atributo possui um ponteiro para o sistema de entrada do fluxo */
    System *target; /*!< Esse atributo possui um ponteiro para o sistema de saída do fluxo */
public:
    /*!
        Esse é o construtor padrão da classe Flow
    */
    Flow();

    /*!
        Esse é o construtor copia da classe Flow.
        \param flow fluxo para ser copiado
    */
    Flow(const Flow* flow);
    
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
        Retorna o nome do fluxo.
        \return string - o nome do fluxo.
    */
    string getName();

    /*!
        Seta o nome do fluxo
        \param name - o nome do fluxo.
    */
    void setName(string name);

     /*!
        Retorna o valor atual do fluxo.
        \return double - valor atual.
    */
    double getCurrentValue() const;

    /*!
        Seta o valor atual do fluxo
        \param value - valor atual.
    */
    void setCurrentValue(double value);

    /*!
        Retorna o ponteiro do sistema de entrada do fluxo.
        \return System * - ponteiro para um sistema.
    */
    System * getSource(void) const;

    /*!
        Retorna o ponteiro do sistema de saída do fluxo.
        \return System * - ponteiro para um sistema.
    */
    System * getTarget(void) const;

    /*!
        Seta o ponteiro para o sistema de entrada do fluxo.
        \param source - ponteiro para um sistema.
    */
    void setSource(System * source);

    /*!
        Seta o ponteiro para o sistema de saída do fluxo.
        \param target - ponteiro um sistema.
    */
    void setTarget(System * target);

    /*!
        Connecta dois fluxo ao sistema (entrada e saída).
        \param source - ponteiro para um sistema de entrada.
        \param target - ponteiro para um sistema de saída.
    */
    void connect(System *source = NULL, System* target = NULL);

    /*!
        Método virtual puro que será herdado por subclasses criadas pelo usuário, essa conterá
        uma equação que será executada no fluxo pelo modelo.
    */
    virtual double execute() = 0;

    /*!
        Operador de atribuição (=) sobrecarregado para a classe Flow.
    */
    Flow* operator=(const Flow* flow);
};

#endif
