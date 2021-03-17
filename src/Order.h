#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
using namespace std;

class Order
{
 public:
   Order(const string &);
   unsigned int       date;
   unsigned short int quantity; // max value = 999
   bool               express; // true for express orders, false for normal orders
   string getOrderType() const;
};

#endif //VACCINE_DISTRIBUTION_SYSTEM_ORDER_H
