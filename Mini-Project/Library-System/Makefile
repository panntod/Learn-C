program: main.o buku.o
	gcc main.o buku.o -o program

main.o: main.c buku.h
	gcc -c main.c

buku.o: buku.c buku.h
	gcc -c buku.c

clean:
	rm -f *.o program
