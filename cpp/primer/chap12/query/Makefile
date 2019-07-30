CC = g++ -std=c++11

main: text_query.o str_blob.o
	$(CC) main.cc text_query.o str_blob.o -o main.out

text_query.o: text_query.cc
	$(CC) -c text_query.cc

str_blob.o: str_blob.cc
	$(CC) -c str_blob.cc

clean:
	rm -rf *.o main.out
