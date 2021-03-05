#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <list>
#include "Order.h"
#include <iomanip>
using namespace std;

class Customer
{
   std::list<Order>   orders;
   char               name[41]; // 40 characters + end of line
   unsigned short int customerNumber;
   int getQuantityToShip();

 public:
   Customer(const std::string &);
   void processOrder(std::string, unsigned short int *);
   void sendShipment(std::string, unsigned short int *);
};

#endif //VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
