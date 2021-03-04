!/bin/bash


function compile() {
  g++ -std=c++11 -I./ -c $1.cpp -o $1.o
}

compile customer
compile order

g++ -I./ customer.o order.o -o $1