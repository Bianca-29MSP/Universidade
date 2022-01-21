#ifndef SYSTEM_CPP
#define SYSTEM_CPP

#include <vector>

using namespace std;

class System {
    private:
        double value;
    protected:
    public:
        System();
        virtual ~System();

        void setValue(double value);
        double getValue();
        System& operator=(const System&);
};

#endif
