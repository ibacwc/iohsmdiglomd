#!/bin/bash

LIBS="-lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer"
COMPILER="gcc"
OPTS="-std=c99 -O2"
FILES="*.c"

$COMPILER $FILES $OPTS $LIBS -o $1
