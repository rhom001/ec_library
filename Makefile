#Makefile
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJS = bin/Format.o bin/Date.o $(ADMIN)
ADMIN = bin/User.o bin/Role.o 

#Targets
all: main
	mkdir -p ./bin
main:	src/main.cpp $(OBJS)
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -o bin/ec_library src/main.cpp $(OBJS)
	./bin/ec_library
bin/Format.o: src/Format.cpp src/Format.h src/Admin.h
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -c src/Format.cpp -o bin/Format.o

bin/User.o: src/User.cpp src/Admin.h
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -c src/User.cpp -o bin/User.o
	
bin/Date.o: src/Date.cpp src/Date.h
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -c src/Date.cpp -o bin/Date.o
	
bin/Role.o: src/Role.cpp src/Admin.h
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -c src/Role.cpp -o bin/Role.o

clean:
	rm -i bin/*
	rmdir bin
