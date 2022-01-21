#ifndef MODEL_CPP
#define MODEL_CPP

#include <list>
#include "Flow.hpp"

using namespace std;

//! Class Model
/**
* Está classe representa o modelo geral da simulação, é nela que contém as estruturas necessárias para a simulação e sua execução.
*/
class Model {
    private:
        //Atributos
        list<Flow *> flows; /*!< Esse atributo possui os fluxos(flows) da simulação */
        int initialTime; /*!< Esse atruibuto possui o tempo inicial do range da simulação */
        int finalTime; /*!< Esse atruibuto possui o tempo final do range da simulação */
    
        //Métodos
        /*!
            Retorna uma lista com os fluxos(flows) presentes no modelo
            \return list<Flow *> - lista dos fluxos(flows)
        */
        list<Flow *> getFlows();

    protected:
    public:
        /*!
            Esse é o construtor padrão da classe Model
        */
        Model();
        
        /*!
            Esse é um construtor que possui atributos iniciais para o model
            \param initialTime o tempo inicial do range da simulação.
            \param finalTime o tempo final do range da simulação.
        */
        Model(int initialTime, int finalTime);

        /*!
            Esse é o destrutor padrão da classe Model
        */
        virtual ~Model();

        /*!
            Adiciona um fluxo(flow) ao Model
            \param flow ponteiro para o fluxo(flow) adicionado ao modelo.
        */
        void add(Flow * flow);
    
        /*!
            Seta o valor do tempo inicial do range do modelo.
            \param initialTime - valor do tempo inicial.
        */
        void setInitialTime(int initialTime);

        /*!
            Retorna o valor do tempo inicial do range do modelo.
            \return int - valor do tempo inicial.
        */
        int getInitialTime() const;

        /*!
            Seta o valor do tempo final do range do modelo.
            \param finalTime - valor do tempo final.
        */
        void setFinalTime(int finalTime);

        /*!
           Retorna o valor do tempo final do range do modelo.
            \return int - valor do tempo final.
        */
        int getFinalTime() const;

        /*!
            Executa todos os processos presente no modelo.
        */
        void run();

        /*!
            Operador de atribuição (=) sobrecarregado para a classe Model.
        */
        Model& operator=(const Model& model);
};

#endif