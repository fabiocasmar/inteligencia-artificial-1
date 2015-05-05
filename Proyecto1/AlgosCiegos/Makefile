CC = clang++ -c 
CXX = clang++
OPT = -g -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --state_map --no_abstraction --no_backwards_moves --history_len=0

psvn2c_core.c:
	cp ../psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ../psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ../psvn2c_abstraction.c ./psvn2c_abstraction.c

%.c: %.psvn  psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn2c  $(PSVNOPT) --name=$(*F)  < $< > $@
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

.PRECIOUS: %.c

%.nodo: %.c nodo.hpp nodo.cpp 
	$(CC) $(OPT) nodo.cpp -include $< 

%.heucs: %.c ucsDDD.cpp 
	$(CC) $(OPT) ucsDDD.cpp -include $< 

%.DFID: %.c DFID.cpp
	$(CXX) $(OPT) DFID.cpp -include $< -o $@

%.bfsDDD: %.c bfsDDD.cpp
	$(CXX) $(OPT) bfsDDD.cpp -include $< -o $@

%.ucsDDD: %.c %.nodo %.heucs
	$(CXX) $(OPT) nodo.o ucsDDD.o -include $< -o $@

.PHONY : clean
clean:
	rm -f *.succ *.o 8puzzle.c 15puzzle1.c psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c *~
