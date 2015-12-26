#Makefile
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJS = bin/Format.o bin/Date.o $(ADMIN)
ADMIN = bin/User.o bin/Role.o bin/Series.o bin/Album.o bin/Song.o

#Targets
all: src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o bin/ec_library src/main.cpp $(OBJS)

test: src/test.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o bin/test src/test.cpp $(OBJS)

bin/Format.o: src/Format.cpp src/Format.h
	$(COMPILE) $(FLAGS) -c src/Format.cpp -o bin/Format.o

bin/Date.o: src/Date.cpp src/Date.h
	$(COMPILE) $(FLAGS) -c src/Date.cpp -o bin/Date.o

bin/User.o: src/User.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/User.cpp -o bin/User.o

bin/Role.o: src/Role.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/Role.cpp -o bin/Role.o

bin/Series.o: src/Series.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/Series.cpp -o bin/Series.o

bin/Album.o: src/Album.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/Album.cpp -o bin/Album.o

bin/Song.o: src/Song.cpp src/Admin.h
	$(COMPILE) $(FLAGS) -c src/Song.cpp -o bin/Song.o

clean:
	rm -i bin/*
	rmdir bin
