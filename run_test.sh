rm -rf *.o
gcc -c ./test/*.c linkedlist.c
if [ $? == 0 ]
then
  gcc -o a.out  *.o
  ./a.out
  rm -rf *.o
  rm -rf a.out
fi

