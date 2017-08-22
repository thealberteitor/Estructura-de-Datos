# VARIABLES
BIN = bin
SRC = src
OBJ = obj
LIB = lib
DOC = doc
INCLUDE = include
CXX = g++ -Ofast
CC = gcc -Ofast

OS := $(shell uname)
ifeq ($(OS),Darwin) #flags para MAC OS X
LDFLAGS =
CPPFLAGS = -dynamiclib
else  #flags para linux
LDFLAGS =
CPPFLAGS = -Wall -g -c
endif

all: clean  $(BIN)/usopilas_max

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o
$(OBJ)/usopilas_max.o: $(INCLUDE)/pila_max.h $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp  -o $(OBJ)/usopilas_max.o -I$(INCLUDE) -I$(SRC)

# DOCUMENTACION
.PHONY: doc
doc:
	doxygen doc/doxys/Doxyfile
# LIMPEZA
.PHONY: clean
clean:
	@echo "Limpiando archivos..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
        $(DOC)/html/*\
