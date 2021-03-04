

#ifndef VACCINE_DISTRIBUTION_SYSTEM_ORDER_H
#define VACCINE_DISTRIBUTION_SYSTEM_ORDER_H

#include <iostream>
using namespace std;

class Order
{
   int quantity;
   bool express; // true for express orders, false for normal orders
   char date[8];
public:
   explicit Order(string);

   int getQuantity();

   string getOrderType();

   bool isExpress();

   string getDate();
};


#endif //VACCINE_DISTRIBUTION_SYSTEM_ORDER_H
