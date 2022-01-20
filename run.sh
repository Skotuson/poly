#! /bin/bash
clear
g++ -Wall -pedantic poly.c -fsanitize=address
./a.out
rm a.out
