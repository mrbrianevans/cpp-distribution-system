#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
using namespace std;

class Order
{
   int  quantity;
   bool express; // true for express orders, false for normal orders
   char date[8];
 public:
   Order(string);
   int getQuantity();
   string getOrderType();
   bool isExpress();
   string getDate();
};

#endif //VACCINE_DISTRIBUTION_SYSTEM_ORDER_H
