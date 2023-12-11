CC = g++

parser: parser.cpp
	$(CC) -Wall -g -Werror -std=c++11 parser.cpp -o parser

.PHONY: clean check all

check: 
	./parser "bit_cell_64x64.sp" "WL<9>"

clean:
	rm -f *.o
	rm parser
