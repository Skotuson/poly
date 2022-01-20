#! /bin/bash
clear
g++ -Wall -pedantic poly.c -fsanitize=address -g
./a.out
rm a.out
