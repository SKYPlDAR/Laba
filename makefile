 laba: main.o base.o
	gcc main.o base.o -o laba
main.o : main.c
	gcc -c main.c -o main.o
base.o : base.c
	gcc -c base.c -o base.o
clean:
    rm laba *.o