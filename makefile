all:derle birlestir calistir



derle:
	gcc -c -I "./include" ./src/flea.c -o ./lib/flea.o
	gcc -c -I "./include" ./src/habitat.c -o ./lib/habitat.o
	gcc -c -I "./include" ./src/herb.c -o ./lib/herb.o
	gcc -c -I "./include" ./src/housefly.c -o ./lib/housefly.o
	gcc -c -I "./include" ./src/insect.c -o ./lib/insect.o
	gcc -c -I "./include" ./src/live.c -o ./lib/live.o
	gcc -c -I "./include" ./src/numberOfElements.c -o ./lib/numberOfElements.o
	gcc -c -I "./include" ./src/numberOfElementsInRow.c -o ./lib/numberOfElementsInRow.o
	gcc -c -I "./include" ./src/main.c -o ./lib/main.o


birlestir:
	g++ ./lib/flea.o ./lib/habitat.o ./lib/herb.o ./lib/housefly.o ./lib/insect.o ./lib/live.o ./lib/numberOfElements.o ./lib/numberOfElementsInRow.o ./lib/main.o -o ./bin/program

calistir:
	./bin/program