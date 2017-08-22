SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o $(OBJ)/EventoHistorico.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o $(OBJ)/EventoHistorico.o

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp -I$(INC)

$(OBJ)/EventoHistorico.o: $(SRC)/EventoHistorico.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/EventoHistorico.o $(SRC)/EventoHistorico.cpp -I$(INC)

$(OBJ)/Cronologia.o: $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp -I$(INC)


# ******$(OBJ)****** Limpieza ************
clean :
	-rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm -f $(BIN)/* doc/html/*
