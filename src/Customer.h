#ifndef VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
#define VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H

#include <list>
#include "Order.h"
#include <iomanip>

class Customer
{
   std::list<Order> orders;
   char name[40];
   int customerNumber;
public:
   explicit Customer(std::string);

   void processOrder(std::string);

   void sendShipment(std::string);
};


#endif //VACCINE_DISTRIBUTION_SYSTEM_CUSTOMER_H
