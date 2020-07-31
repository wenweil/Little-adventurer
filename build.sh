#!/bin/sh

rm bin-int/*
rm bin/*

CC="g++"
BINDIR="bin"
INTDIR="bin-int"
SRCDIR="src"

CFLAGS="-Idependencies/glfw/include -Isrc"
LFLAGS="-Ldependencies/glfw/lib-mingw-w64"

LIBS="-lglfw3 -lopengl32 -lgdi32"

FILE=`find $SRCDIR -type f -name "*.cpp"`

for i in $FILE
do
    OUTFILE=`basename ${i%.*}`
    OUTFILE="$INTDIR/$OUTFILE.o"
    echo $CC $CFLAGS -c $i -o $OUTFILE
    $CC $CFLAGS -c $i -o $OUTFILE
done
echo $CC $LFLAGS -g $INTDIR/* -o $BINDIR/game.exe $LIBS
$CC $LFLAGS -g $INTDIR/* -o $BINDIR/game.exe $LIBS
echo "done"
read a