#ifndef MODEL_CPP
#define MODEL_CPP

#include <list>
#include "Flow.hpp"

using namespace std;

class Model {
    private:
        list<Flow *> flows;
        int initialTime;
        int finalTime;
    protected:
    public:
        Model();
        Model(int initialTime, int finalTime);
        virtual ~Model();

        void add(Flow *);
        list<Flow *> getFlows();

        void setInitialTime(int initialTime);
        int getInitialTime() const;
        void setFinalTime(int finalTime);
        int getFinalTime() const;

        double run();

        Model& operator=(const Model& model);
};

#endif