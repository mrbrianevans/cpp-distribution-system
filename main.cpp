#include <iostream>
#include "customer.h"
#include "order.h"

int main()
{
   std::cout << "Hello, World! from Brian" << std::endl;
   auto *c = new customer();
   c->customerId = 300;
   std::cout << c->customerId << std::endl;
   return 0;
}
