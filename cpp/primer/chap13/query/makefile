CC = clang++ -std=c++11
build = -o main

main: main.cc strvec.o text_query.o
	$(CC) $(build) main.cc strvec.o text_query.o

strvec.o:
	$(CC) -c dep/strvec.cc

text_query.o:
	$(CC) -c text_query.cc

clean:
	rm -f main *.o

