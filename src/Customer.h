#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#define MAX_CUSTOMER_NAME_LENGTH 40
#include <iostream>
#include <list>
#include <iomanip>
#include <sstream>
#include <regex>
#include "Order.h"
using namespace std;

class Customer
{
   std::list<Order>   orders;
   string             name;
   unsigned short int customerNumber;
   int getQuantityToShip();
 public:
   Customer(const string &);
   void processOrder(string, unsigned short int *);
   void sendShipment(unsigned int, unsigned short int *);
};

#endif //VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
