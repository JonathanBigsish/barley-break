.PHONY: all clean

all: bin/barley-break

bin/barley-break: build/src/main.o build/src/graphics.o build/src/logic.o src/graphics.h src/logic.h
	mkdir bin -p
	gcc -Wall build/src/main.o build/src/graphics.o build/src/logic.o -o barley-break -lncurses

build/src/main.o: src/main.c src/graphics.h src/logic.h
	mkdir build/src -p
	gcc -std=c99 -I scr -Wall -c src/main.c -o build/src/main.o

build/src/graphics.o: src/graphics.c src/graphics.h
	mkdir build/src -p
	gcc -std=c99 -Wall -c src/graphics.c -o build/src/graphics.o

build/src/logic.o: src/logic.c src/logic.h
	mkdir build/src -p
	gcc -std=c99 -Wall -c src/logic.c -o build/src/logic.o

test: bin/barley-break-test

bin/barley-break-test: build/src/logic.o build/test/main.o build/test/combination_test.o build/test/out_edge_test.o
	mkdir bin -p
	gcc -std=c99 -I thirdparty -I src -Wall build/src/logic.o build/test/main.o build/test/combination_test.o build/test/out_edge_test.o -o bin/barley-break-test

build/test/main.o: test/main.c
	mkdir build/test -p
	gcc -std=c99 -I thirdparty -I src -Wall -c test/main.c -o build/test/main.o

build/test/combination_test.o: test/combination_test.c
	mkdir build/test -p
	gcc -std=c99 -I thirdparty -I src -Wall -c test/combination_test.c -o build/test/combination_test.o

build/test/out_edge_test.o: test/out_edge_test.c
	mkdir build/test -p
	gcc -std=c99 -I thirdparty -I src -Wall -c test/out_edge_test.c -o build/test/out_edge_test.o

clean:
	rm -rf build/* bin/*
