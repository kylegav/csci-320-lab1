default: explode

explode: main.o
	gcc -o explode main.o lab1.c

main.o: main.c lab1.h
	gcc -c main.c

lab1.o: lab1.c lab1.h
	gcc -c lab1.c

clean:
	-rm -rf *.o explode testing