CC = gcc
CFLAGS = -Wall
CNAME = exec

all: heap.o intercalacao2f.o analise.o geradorArq.o  quickSortExterno.o intercalacaofp1.o main.o
	$(CC) $(CFLAGS) -o $(CNAME) ./O/main.o ./O/heap.o ./O/intercalacao2f.o ./O/intercalacaofp1.o ./O/quickSortExterno.o ./O/analise.o ./O/geradorArq.o

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -o ./O/heap.o -c heap.c

intercalacao2f.o: intercalacao2f.c intercalacao2f.h
	$(CC) $(CFLAGS) -o ./O/intercalacao2f.o -c intercalacao2f.c

analise.o: analise.c analise.h
	$(CC) $(CFLAGS) -o ./O/analise.o -c analise.c

geradorArq.o: geradorArq.c geradorArq.h
	$(CC) $(CFLAGS) -o ./O/geradorArq.o -c geradorArq.c

intercalacaofp1.o: intercalacaofp1.c intercalacaofp1.h
	$(CC) $(CFLAGS) -o ./O/intercalacaofp1.o -c intercalacaofp1.c

quickSortExterno.o: quickSortExterno.c quickSortExterno.h
	$(CC) $(CFLAGS) -o ./O/quickSortExterno.o -c quickSortExterno.c

main.o: main.c
	$(CC) $(CFLAGS) -o ./O/main.o -c main.c

clean:
	rm -rf ./O/*.o $(CNAME)

run:
	./$(CNAME) "data/PROVAO.TXT" 3 100 1

run[-P]:
	./$(CNAME) "data/PROVAO_DESC.TXT" 1 1000 1 [-P]


	