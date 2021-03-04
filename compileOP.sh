#!/bin/bash

mkdir -p build

function compile() {
  g++ -std=c++11 -I./ -c src/$1.cpp -o build/$1.o
}

compile Customer
compile Order
compile main

g++ -I./build build/main.o build/Customer.o build/Order.o -o ordering
