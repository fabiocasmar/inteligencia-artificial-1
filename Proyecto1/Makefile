CC = clang++ -c -Wc++11-extensions
CXX = clang++
OPT = -g -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --state_map --no_backwards_moves --history_len=0
PSVNOPT2 = #--fwd_history_len=3 --bwd_history_len=0  --backwards_moves --state_map

psvn2c: ./psvn/psvn2c.cpp ./psvn/psvn2c.hpp ./psvn/psvn.cpp ./psvn/psvn.hpp
	$(CXX) $(OPT) ./psvn/psvn2c.cpp ./psvn/psvn.cpp -o ./psvn/$@

psvn2c_core.c:
	cp ./psvn/psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ./psvn/psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ./psvn/psvn2c_abstraction.c ./psvn2c_abstraction.c

%.c: ./problemas/%.psvn  psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	./psvn/psvn2c  $(PSVNOPT2) --name=$(*F)  < $< > ./$@
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

.PRECIOUS: %.c

%.nodo: %.c ./src/extras/nodo.hpp ./src/extras/nodo.cpp 
		$(CC) $(OPT) ./src/extras/nodo.cpp -include ./$<

%.heucs: %.c ./src/ucsDDD.cpp 
	$(CC) $(OPT) ./src/ucsDDD.cpp -include $<
	rm $<

%.hebfs: %.c ./src/bfsDDD.cpp 
	$(CC) $(OPT) ./src/bfsDDD.cpp -include $<
	rm $<

%.heaestrella: %.c ./src/aestrella.cpp
	$(CC) $(OPT) ./src/aestrella.cpp -include $<
	rm $<

%.hidaestrella: %.c ./src/idaestrella.cpp
	$(CC) $(OPT) ./src/idaestrella.cpp -include $< 
	rm $<

%.DFID: %.c ./src/DFID.cpp
	$(CXX) $(OPT) ./src/DFID.cpp -include $< -o $@
	rm $<

%.bfsDDD: %.c %.nodo %.hebfs
	$(CXX) $(OPT) nodo.o bfsDDD.o -include $< -o $@
	rm nodo.o bfsDDD.o 

%.ucsDDD: %.c %.nodo %.heucs
	$(CXX) $(OPT) nodo.o ucsDDD.o -include $< -o $@
	rm nodo.o ucsDDD.o

%.aestrella: %.c %.nodo %.heaestrella
	$(CXX) $(OPT) nodo.o aestrella.o -include $< -o $@
	rm nodo.o aestrella.o

%.idaestrella: %.c %.nodo %.hidaestrella
	$(CXX) $(OPT) nodo.o idaestrella.o -include $< -o $@
	rm nodo.o idaestrella.o

%.manhattan: %.c ./src/heuristicas/manhattan.cpp
	$(CC) $(OPT) ./src/heuristicas/manhattan.cpp -include $< -o $@

%.topspin: %.c2 ./src/heuristicas/heuristicatopspin.cpp
	$(CC) $(OPT) ./src/heuristicas/heuristicatopspin.cpp -include $< -o $@

%.heuristicahanoi: %.c ./src/heuristicas/heuristicahanoi.cpp
	$(CC) $(OPT) ./src/heuristicas/heuristicahanoi.cpp -include $< -o $@

%.24puzzle1addPDB: %.c ./src/heuristicas/24puzzle1addPDB.cpp
	$(CC) $(OPT) ./src/heuristicas/24puzzle1addPDB.cpp -include $< -o $@

%.15puzzle1addPDB: %.c ./src/heuristicas/15puzzle1addPDB.cpp
	$(CC) $(OPT) ./src/heuristicas/15puzzle1addPDB.cpp -include $< -o $@

%.arbolbusqueda: %.c ./src/arbolbusqueda.cpp
	$(CXX) $(OPT) ./src/arbolbusqueda.cpp -include $< -o $@
	rm $<

%.arbolpodado: %.c ./src/arbolpodado.cpp
	$(CXX) $(OPT) ./src/arbolpodado.cpp -include $< -o $@
	rm $<

.PHONY : clean
clean:
	rm -f *.o psvn2c_core.c *~ ./psvn/*.o ./psvn/psvn2c
