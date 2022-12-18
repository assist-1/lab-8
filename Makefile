PROJECT = main
CC = g++


$(PROJECT): main.o functions.o
	$(CC) main.o functions.o -o $(PROJECT)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

class.o: functions.cpp
	$(CC) -c functions.cpp -o functions.o

clean:
	rm $(PROJECT) *.o

distclean: clean
	rm -f make