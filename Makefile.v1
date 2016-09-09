main: main.o cweb.o
	g++ -std=c++11 ./obj/main.o ./obj/cweb.o -o ./bin/main
main.o: ./src/main.cpp ./src/cweb.h
	g++ -std=c++11 -Ithirdparty/boost_1_61_0 -Isrc -c ./src/main.cpp -o ./obj/main.o
cweb.o: ./src/cweb.cpp ./src/cweb.h
	g++ -W -Wall -std=c++11 -lpthread -Ithirdparty/boost_1_61_0 -Isrc -c ./src/cweb.cpp -g -o ./obj/cweb.o
clean:
	rm -rf ./obj/*.o ./bin/main
