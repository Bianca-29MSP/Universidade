ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o
endif

api_lib = bin/Model.dll bin/System.dll bin/Flow.dll

lib: Model.dll System.dll Flow.dll
test-functional: tests-functional
test-unit: tests-unit
all-test-functional: lib test-functional
all-test-unit: lib test-unit

Model.dll:
	g++ -c src/Model.cpp -o bin/Model.dll -Wall

System.dll:
	g++ -c src/Flow.cpp -o bin/Flow.dll -Wall

Flow.dll:
	g++ -c src/System.cpp -o bin/System.dll -Wall

tests-functional:
	g++ test/functional/main.cpp test/functional/functional_tests.cpp $(api_lib) -o bin/functional_tests

tests-unit:
	g++ test/unit/main.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp test/unit/unit_Model.cpp $(api_lib) -o bin/unit_tests
	
clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"

run-functional:
	./bin/functional_tests

run-unit:
	./bin/unit_tests
