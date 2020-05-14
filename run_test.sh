#! /bin/bash
executable=$1
rm -rf *.o
gcc -c linkedlist.c test/*.c 
gcc -o $1 *.o
./$1
rm -rf $1
rm -rf *.o
