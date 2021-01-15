CXX?=g++

my_main: ./bin/main

./bin/main: ./main.cc
	mkdir -p bin
	${CXX} main.cc -o ./bin/main
