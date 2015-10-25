#!/bin/sh
set -e

make clean
make ex17

./ex17 db.dat c 8 8
./ex17 db.dat s 1 Sam sam@example.org
./ex17 db.dat s 7 Joe joe@example.org
./ex17 db.dat l
./ex17 db.dat g 1
./ex17 db.dat d 1
./ex17 db.dat f email sam@example.org
