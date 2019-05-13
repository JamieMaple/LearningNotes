CC=clang++ -std=c++11

main: message.o folder.o
	$(CC) -o main main.cc message.o folder.o

message.o:
	$(CC) -c message.cc

folder.o:
	$(CC) -c folder.cc

clean:
	rm -f *.o main

