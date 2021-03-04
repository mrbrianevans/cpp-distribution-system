#ifndef VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
#define VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H

#include <list>
#include "Order.h"
#include <iomanip>
using namespace std;

class Customer
{
   std::list<Order> orders;
   char name[41]; // 40 characters + end of line
   unsigned short int customerNumber;

   int getQuantityToShip();

public:
   explicit Customer(std::string);

   void processOrder(std::string);

   void sendShipment(std::string);
};


#endif //VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
