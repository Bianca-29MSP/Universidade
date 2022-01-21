#ifndef  MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONA_TESTS

#include "functional_tests.hpp"
#include "../../src/Model.hpp"
#include "../../src/System.hpp"
#include "../../src/Flow.hpp"

int main(){
    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    return true;
}

#endif