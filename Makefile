#
#   Copyright (c) 2023 Mihai Zegheru
#   All rights reserved.
#

CC=gcc
CFLAGS=-Wall -Wextra -pedantic
LIBS=-lm

EXE=BitsetLibrary.exe

SRC=src
OUT=build

SOURCES=$(SRC)/main.c\
		$(SRC)/bitset.c

.PHONY: build
build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)/$(EXE) $(LIBS)

clean:
	rm $(OUT)/$(EXE)
