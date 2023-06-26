.PHONY: all clean debug

CXXFLAGS := -Wall -Wextra -Iinclude -Wno-unused-parameter -Wpedantic -Werror -ldl -lgtest -lgtest_main -lpthread

ifeq ($(DEBUG),1)
	CXXFLAGS += -g -DDEBUG_MODE
endif

all: bin/Tensor.out

bin/Tensor.out: bin/Functions.o bin/NPConstructorDef.o bin/NPCreationRoutines.o bin/npFuncDef.o bin/Tests.o
	g++ bin/Functions.o bin/NPConstructorDef.o bin/NPCreationRoutines.o bin/npFuncDef.o bin/Tests.o -o bin/Tensor.out $(CXXFLAGS) -Bdynamic

bin/Functions.o: src/Functions.cpp
	g++ -c src/Functions.cpp -o bin/Functions.o -Iinclude

bin/NPConstructorDef.o: src/NPConstructorDef.cpp
	g++ -c src/NPConstructorDef.cpp -o bin/NPConstructorDef.o -Iinclude

bin/NPCreationRoutines.o: src/NPCreationRoutines.cpp
	g++ -c src/NPCreationRoutines.cpp -o bin/NPCreationRoutines.o -Iinclude

bin/npFuncDef.o: src/npFuncDef.cpp
	g++ -c src/npFuncDef.cpp -o bin/npFuncDef.o -Iinclude

bin/Tests.o: src/Tests.cpp
	g++ -c src/Tests.cpp -o bin/Tests.o -Iinclude -lgtest -lgtest_main -lpthread

clean:
	rm -f bin/*.o bin/Tensor.out

debug: clean
	make all DEBUG=1
