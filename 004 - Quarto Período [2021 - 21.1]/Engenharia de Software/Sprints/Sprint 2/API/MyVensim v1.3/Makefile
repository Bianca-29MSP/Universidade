ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o
endif

api_lib = ./bin/Model.dll ./bin/System.dll ./bin/Flow.dll

lib: Model.dll System.dll Flow.dll
all-functional: ./test/functional/main.cpp FunctionalTets.dll Model.dll Flow.dll System.dll
	g++ $(api_lib) ./test/functional/main.cpp -o ./bin/functional_tests ./bin/funcional_tests.dll

System.dll: ./src/System.cpp
	g++ -c ./src/System.cpp -o ./bin/System.dll -Wall

Flow.dll: ./src/Flow.cpp System.dll 
	g++ -c ./src/Flow.cpp -o ./bin/Flow.dll -Wall

Model.dll: ./src/Model.cpp Flow.dll
	g++ -c ./src/Model.cpp -o ./bin/Model.dll -Wall

FunctionalTets.dll: ./test/functional/functional_tests.cpp Model.dll Flow.dll
	g++ -c ./test/functional/functional_tests.cpp -o ./bin/funcional_tests.dll -Wall

run-functional:
	./bin/functional_tests

clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"
