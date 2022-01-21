#ifndef MODEL_HPP
#define MODEL_HPP

#include "Flow.hpp"
#include <list>

using namespace std;

//! Class Model
/**
* Está classe representa o modelo geral da simulação, é nela que contém as estruturas necessárias para a simulação e sua execução.
*/
class Model {
private:
    double time; /*!< Esse atributo possui o tempo atual da simulação */
    list<Flow *> flows; /*!< Esse atributo possui os fluxos(flows) da simulação */
    list<System *> systems; /*!< Esse atributo possui os sistemas(system) da simulação */
protected:
public:
    /*!
        Esse é o construtor padrão da classe Model
    */
    Model() {
        setTime(0);
    }

    /*!
        Esse é o destrutor padrão da classe Model
    */
    virtual ~Model(){}

    /*!
        Adiciona um fluxo(flow) ao Model
        \param flow ponteiro para o fluxo(flow) adicionado ao modelo.
    */
    void add(Flow * flow = NULL) {
        this->flows.push_back(flow);
    }

    /*!
        Adiciona um sistema(system) ao Model
        \param system ponteiro para o sistema(system) adicionado ao modelo.
    */
    void add(System * system = NULL) {
        this->systems.push_back(system);
    }

    /*!
        Retorna a lista com os fluxos(flows) presentes no modelo
        \return list<Flow *> - lista dos fluxos(flows)
    */
    list<Flow *> getFlows() const
    {
        return this->flows;
    }

    /*!
        Retorna a lista com os sistema(system) presentes no modelo
        \return list<Flow *> - lista dos sistema(system)
    */
    list<System *> getSystems() const
    {
        return this->systems;
    }

    /*!
        Seta o valor do tempo inicial do range do modelo.
        \param initialTime - valor do tempo inicial.
    */
    void setTime(double time) {
        this->time = time;
    }

    /*!
        Retorna o valor do tempo atual da simulação no modelo.
        \return double - valor do tempo atual.
    */
    double getTime() const{
        return time;
    }

    /*!
        Seta o valor do tempo atual da simulação no modelo.
        \param increment - valor a ser incrementado no tempo atual.
    */
    void incrementTime(double increment = 1) {
        this->time += increment;
    }

    /*!
        Executa todos os fluxos no modelo.
        \param start o tempo inicial.
        \param end o tempo final.
        \param increment unidade em que o tempo será incrementado.
    */
    void run(double start = 0, double end = 0, double increment = 0)
    {
        for(double i = start; i < end; i+=increment) 
        {
            for(Flow *f: getFlows()) 
            {
                f->setCurrentValue(f->execute());
            }

            for(Flow *f: getFlows()) 
            {
                System *source = f->getSource();
                System *target = f->getTarget();
                if(source != NULL)
                {
                    source->setValue(source->getValue() - f->getCurrentValue());
                }

                if(target != NULL) 
                {
                    target->setValue(target->getValue() + f->getCurrentValue());
                }
            }
            
            incrementTime(increment);
        }
    }

    /*!
        Operador de atribuição (=) sobrecarregado para a classe Model.
    */
    Model* operator=(const Model* model)
    {
        if (model == this)
            return this;

        this->flows = model->flows;
        this->systems = model->systems;
        this->time = model->time;

        return this;
    }
};

#endif