ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o
endif

api_lib = bin/Model.dll bin/System.dll bin/Flow.dll

lib: Model.dll System.dll Flow.dll
tests: tests-functional
all: lib tests

Model.dll:
	g++ -c src/Model.cpp -o bin/Model.dll -Wall

System.dll:
	g++ -c src/Flow.cpp -o bin/Flow.dll -Wall

Flow.dll:
	g++ -c src/System.cpp -o bin/System.dll -Wall

tests-functional:
	g++ test/functional/main.cpp test/functional/functional_tests.cpp $(api_lib) -o bin/functional_tests
	
clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"

run:
	./bin/functional_tests
