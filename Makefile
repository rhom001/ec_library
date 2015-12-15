#Makefile
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJS = bin/Format.o bin/Date.o $(ADMIN)
ADMIN = bin/Role.o  

#Targets
all: src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o bin/ec_library src/main.cpp $(OBJS)

bin/Format.o: src/Format.cpp src/Format.h
	$(COMPILE) $(FLAGS) -c src/Format.cpp -o bin/Format.o

bin/Date.o: src/Date.cpp src/Date.h
	$(COMPILE) $(FLAGS) -c src/Date.cpp -o bin/Date.o

bin/Role.o: src/Role.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/Role.cpp -o bin/Role.o

clean:
	rm -i bin/*
	rmdir bin
