#################################
#
# Makefile for compiling the project on Linux/MSYS
#
# Author: Shikuzu
#
# Date: 26.10.21
#
#################################

CC := g++

SRC := /src

INCLUDE := /include

BIN := /bin

exe: mat
	$(CC) -o main $(BIN)/mat.o  

mat:
	$(CC) -o $(BIN)/mat  -I$(INCLUDE) $(SRC)/mat.cpp -c

clean: 
	rm $(BIN)/*.* 
