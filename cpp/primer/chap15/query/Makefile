CC = g++ -std=c++11

main: deps/*.o
	$(CC) main.cc deps/*.o -o main

deps/*.o:
	make -C deps deps

clean: clean/deps.o
	rm -rf *.o main

clean/deps.o:
	make -C deps clean
