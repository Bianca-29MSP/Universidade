#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"

using namespace std;

struct Equation {
    double constante;
    int PMax;
    int type;
};

class Flow {
    private:
        System *input;
        System *output;
        Equation equation;

        double exponential(System * sys);
        double logistical(System * sys);

    protected:
    public:
        Flow();
        virtual ~Flow();

        void setInput(System * input);
        System * getInput(void);

        void setOutput(System * output);
        System * getOutput(void);

        void setEquation(double equation, int type);

        void setEquation(double equation, int type, int Pmax);

        double getConstante();

        int getConnection();

        int getPMax();

        double run();

        Flow& operator=(const Flow& flow);
};

#endif
