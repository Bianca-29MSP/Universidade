ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o
endif

api_lib = ./bin/Model.dll ./bin/System.dll ./bin/Flow.dll

all-functional: ./test/functional/main.cpp FunctionalTests.dll System.dll Flow.dll Model.dll
	g++ $(api_lib) ./test/functional/main.cpp -o ./bin/functional_tests ./bin/funcional_tests.dll

all-unit:  test/unit/main.cpp FunctionalTests.dll System.dll Flow.dll Model.dll
	g++ $(api_lib) test/unit/main.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp test/unit/unit_Model.cpp  test/unit/utils/mem_usage.cpp -o bin/unit_tests

ISystem.dll: ./src/ISystem.hpp
	g++ -c ./src/ISystem.hpp -o ./bin/ISystem.dll -Wall

System.dll: ./src/System.cpp ./src/System.hpp ISystem.dll
	g++ -c ./src/System.cpp -o ./bin/System.dll -Wall

IFlow.dll: ./src/IFlow.hpp 
	g++ -c ./src/IFlow.hpp -o ./bin/IFlow.dll -Wall

Flow.dll: ./src/Flow.cpp ./src/Flow.hpp IFlow.dll ISystem.dll
	g++ -c ./src/Flow.cpp -o ./bin/Flow.dll -Wall

IModel.dll: ./src/IModel.hpp ISystem.dll IFlow.dll
	g++ -c ./src/IModel.hpp -o ./bin/IModel.dll -Wall

Model.dll: ./src/Model.cpp ./src/Model.hpp IModel.dll ISystem.dll IFlow.dll
	g++ -c ./src/Model.cpp -o ./bin/Model.dll -Wall

FunctionalTests.dll: ./test/functional/functional_tests.cpp IModel.dll IFlow.dll ISystem.dll
	g++ -c ./test/functional/functional_tests.cpp -o ./bin/funcional_tests.dll -Wall

UnitTests.dll: IModel.dll IFlow.dll ISystem.dll
	g++ ./test/unit/unit_System.cpp ./test/unit/unit_Flow.cpp ./test/unit/unit_Model.cpp -o ./bin/unit_tests.dll -Wall

run-functional:
	./bin/functional_tests

run-unit:
	./bin/unit_tests

clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"
