a.out: GameLogic.o PrintLogic.o main.o
	gcc GameLogic.o PrintLogic.o main.o
	rm *.o
main.o: main.c
	gcc -c main.c
GameLogic.o: GameLogic.c GameLogic.h
	gcc -c GameLogic.c
PrintLogic.o: PrintLogic.c PrintLogic.h
	gcc -c PrintLogic.c
clean:
	rm a.out
run:
	./a.out
