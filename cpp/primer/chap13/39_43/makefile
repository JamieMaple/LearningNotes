CC = clang++ -std=c++11
build = -o main

main: main.cc strvec.o
	$(CC) $(build) main.cc strvec.o

strvec.o:
	$(CC) -c strvec.cc

clean:
	rm -f *.o main
