#include "Order.h"

Order::Order(const string &orderDetails)
{
   char orderType;
   // sscanf is used here to reduce the number of lines of code vs stringstream
   int  qtyFound = sscanf(orderDetails.c_str(), "S%8u%c%*4s%3hu", &this->date,
                          &orderType, &this->quantity);
   if ( qtyFound != 3 ) throw string("Incorrect parameters for new order");
   if ( !(orderType == 'X' ||
          orderType == 'N')) // checks that orderType is valid
      throw string(
            "Invalid order type. Must be either 'X' (for express) or 'N' (for normal)");
   else
      this->express = orderType ==
                      'X'; // if orderType==X then express=true, else express = false
}

string Order::getOrderType() const
{
   // returns the string representation of order type
   return this->express ? string("EXPRESS") : string("normal");
}
