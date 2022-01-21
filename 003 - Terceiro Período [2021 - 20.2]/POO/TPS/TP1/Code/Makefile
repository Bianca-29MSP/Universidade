CC = g++
CFLAGS = -Wall
CNAME = exec

all: Usuario.o Administrador.o Vendedor.o Veterinario.o Venda.o Servico.o Produto.o OrdemServico.o DataHorario.o Conta.o Cliente.o main.o
	$(CC) $(CFLAGS) -o $(CNAME) ./O/main.o ./O/Usuario.o ./O/Administrador.o ./O/Vendedor.o ./O/Veterinario.o ./O/Venda.o ./O/Servico.o ./O/Produto.o ./O/OrdemServico.o ./O/DataHorario.o ./O/Conta.o ./O/Cliente.o

Usuario.o: Usuario.cpp Usuario.hpp
	$(CC) $(CFLAGS) -o ./O/Usuario.o -c Usuario.cpp

Administrador.o: Administrador.cpp Administrador.hpp
	$(CC) $(CFLAGS) -o ./O/Administrador.o -c Administrador.cpp

Vendedor.o: Vendedor.cpp Vendedor.hpp
	$(CC) $(CFLAGS) -o ./O/Vendedor.o -c Vendedor.cpp

Veterinario.o: Veterinario.cpp Veterinario.hpp
	$(CC) $(CFLAGS) -o ./O/Veterinario.o -c Veterinario.cpp

Venda.o: Venda.cpp Venda.hpp
	$(CC) $(CFLAGS) -o ./O/Venda.o -c Venda.cpp

Servico.o: Servico.cpp Servico.hpp
	$(CC) $(CFLAGS) -o ./O/Servico.o -c Servico.cpp

Produto.o: Produto.cpp Produto.hpp 
	$(CC) $(CFLAGS) -o ./O/Produto.o -c Produto.cpp

OrdemServico.o: OrdemServico.cpp OrdemServico.hpp
	$(CC) $(CFLAGS) -o ./O/OrdemServico.o -c OrdemServico.cpp

DataHorario.o: DataHorario.cpp DataHorario.hpp
	$(CC) $(CFLAGS) -o ./O/DataHorario.o -c DataHorario.cpp

Conta.o: Conta.cpp Conta.hpp
	$(CC) $(CFLAGS) -o ./O/Conta.o -c Conta.cpp

Cliente.o: Cliente.cpp Cliente.hpp
	$(CC) $(CFLAGS) -o ./O/Cliente.o -c Cliente.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -o ./O/main.o -c main.cpp

clean:
	rm -rf ./O/*.o $(CNAME)

run:
	./$(CNAME)