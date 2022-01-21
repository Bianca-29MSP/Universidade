ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o
endif

api_lib = ./bin/ModelImplementation.dll ./bin/SystemImplementation.dll ./bin/FlowImplementation.dll

all-functional: ./test/functional/main.cpp FunctionalTests.dll SystemImplementation.dll FlowImplementation.dll ModelImplementation.dll
	g++ $(api_lib) ./test/functional/main.cpp -o ./bin/functional_tests ./bin/funcional_tests.dll

all-unit:
	g++ $(api_lib) test/unit/main.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp test/unit/unit_Model.cpp  -o bin/unit_tests

SystemInterface.dll: ./src/SystemInterface.hpp
	g++ -c ./src/SystemInterface.hpp -o ./bin/SystemInterface.dll -Wall

SystemImplementation.dll: ./src/SystemImplementation.cpp ./src/SystemImplementation.hpp SystemInterface.dll
	g++ -c ./src/SystemImplementation.cpp -o ./bin/SystemImplementation.dll -Wall

FlowInterface.dll: ./src/FlowInterface.hpp 
	g++ -c ./src/FlowInterface.hpp -o ./bin/FlowInterface.dll -Wall

FlowImplementation.dll: ./src/FlowImplementation.cpp ./src/FlowImplementation.hpp SystemInterface.dll
	g++ -c ./src/FlowImplementation.cpp -o ./bin/FlowImplementation.dll -Wall

ModelInterface.dll: ./src/ModelInterface.hpp SystemInterface.dll FlowInterface.dll
	g++ -c ./src/ModelInterface.hpp -o ./bin/ModelInterface.dll -Wall

ModelImplementation.dll: ./src/ModelImplementation.cpp ./src/ModelImplementation.hpp ModelInterface.dll SystemInterface.dll FlowInterface.dll
	g++ -c ./src/ModelImplementation.cpp -o ./bin/ModelImplementation.dll -Wall

FunctionalTests.dll: ./test/functional/functional_tests.cpp ModelInterface.dll FlowInterface.dll SystemInterface.dll
	g++ -c ./test/functional/functional_tests.cpp -o ./bin/funcional_tests.dll -Wall

UnitTests.dll: ModelInterface.dll FlowInterface.dll SystemInterface.dll
	g++ ./test/unit/unit_System.cpp ./test/unit/unit_Flow.cpp ./test/unit/unit_Model.cpp -o ./bin/unit_tests.dll -Wall


run-functional:
	./bin/functional_tests

run-unit:
	./bin/unit_tests

clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"
