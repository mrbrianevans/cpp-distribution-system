

#include <iostream>
#include "Customer.h"

Customer::Customer(std::string customerDetails)
{
   // print new customer added
   sscanf(customerDetails.c_str(), "C%4d%40[^\n]", &this->customerNumber,
          this->name);
   std::cout << "OP: Customer " << std::setfill('0') << std::setw(4)
             << this->customerNumber << " added" << std::endl;
}

void Customer::sendShipment(std::string date)
{
   // print invoice
   // print shipment
   std::cout << "OP: Shipment sent: (Shipment details) " << customerNumber
             << ", quantity" << std::endl;
   std::cout
         << "SC: Invoice sent: (invoice details) customer number, invoice number, "
         << date.c_str() << ", quantity" << std::endl;
}

void Customer::processOrder(std::string orderDetails)
{
   std::cout << "OP: Customer " << std::setfill('0') << std::setw(4)
             << this->customerNumber << ": order type, quantity" << std::endl;
}
