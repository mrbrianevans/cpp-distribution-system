

#include "Order.h"

Order::Order(string orderDetails)
{
   char orderType;
   sscanf(orderDetails.c_str(), "S%8s%c%*4s%3d", this->date, &orderType,
          &this->quantity);
   this->express = orderType == 'X';
}

string Order::getDate()
{
   return this->date;
}

int Order::getQuantity()
{
   return this->quantity;
}

string Order::getOrderType()
{
   return this->express ? string("EXPRESS") : string("normal");
}

bool Order::isExpress()
{
   return this->express;
}
