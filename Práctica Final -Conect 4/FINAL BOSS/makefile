# El ejecutable se crea dentro del bin
# ***** Variables *****
LIBNAME   = Conecta4
H_FILES   = $(wildcard $(INCLUDE)/*.h)
# ****** Directorios ********
INCLUDE   = inc
LIB       = lib
OBJ       = obj
SRC       = src
BIN       = bin

# ****** Opciones de compilación ********
AR        = ar
CXX       = g++
CXXFLAGS  = -c -g -I./$(INCLUDE)
LDFLAGS   = -L./$(LIB)
LDLIBS    = -l$(LIBNAME)
RM        = rm -f


# ****** Compilación de módulos **********
.PHONY: all limpiar mrproper

all: $(BIN)/conecta4

# —- Ejecutables —-
$(BIN)/% : $(OBJ)/%.o $(LIB)/lib$(LIBNAME).a
	$(CXX) $(LDFLAGS) -o $@ $< $(LDLIBS)

$(OBJ)/conecta4.o : $(SRC)/conecta4.cpp $(H_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $<

# —- Librería —-
$(LIB)/lib$(LIBNAME).a : $(OBJ)/mando.o $(OBJ)/tablero.o $(OBJ)/treeko3.o
	ar rvs $@ $?

$(OBJ)/mando.o : $(SRC)/mando.cpp $(INCLUDE)/mando.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/tablero.o : $(SRC)/tablero.cpp $(INCLUDE)/tablero.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/treeko3.o : $(SRC)/treeko3.cpp $(INCLUDE)/ArbolGeneral.h
	$(CXX) $(CXXFLAGS) -o $@ $<

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	-@rm -f $(OBJ)/*o $(SRC)/*~ $(INC)/*~ ./*~
	-@rm -f $(BIN)/conecta4 $(LIB)/*.a
	@echo "Limpieza completada."
