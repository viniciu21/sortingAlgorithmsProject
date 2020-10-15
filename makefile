all:
	mkdir -p bin
	g++ -Wall -c src/sortingAlgorithm.cpp -o bin/sort.o
	g++ -Wall src/main.cpp bin/sort.o -o bin/main

run:
	./bin/main
