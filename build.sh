#!/bin/sh

rm bin-int/*
rm bin/*

CC="g++"
BINDIR="bin"
INTDIR="bin-int"
SRCDIR="src"

CFLAGS="-Idependencies/glfw/include -Idependencies/glad/include -Isrc"
LFLAGS="-Ldependencies/glfw/lib-mingw-w64"

GLAD="dependencies/glad/src/glad.c"

LIBS="-lglfw3 -lopengl32 -lgdi32 -pthread"

FILE=`find $SRCDIR -type f -name "*.cpp"`



for i in $FILE

do
    OUTFILE=`basename ${i%.*}`
    OUTFILE="$INTDIR/$OUTFILE.o"
    echo $CC $CFLAGS -g -c $i -o $OUTFILE
    $CC $CFLAGS -g -c $i -o $OUTFILE
done

echo $CC $LFLAGS $CFLAGS -g $INTDIR/* $GLAD -o $BINDIR/game.exe $LIBS
$CC $LFLAGS $CFLAGS -g $INTDIR/* $GLAD -o $BINDIR/game.exe $LIBS
echo "done"
read a