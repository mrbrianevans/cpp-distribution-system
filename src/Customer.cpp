

#include <iostream>
#include "Customer.h"

Customer::Customer(const string &customerDetails)
{
   // print new customer added
   sscanf(customerDetails.c_str(), "C%4hu%40[^\n]", &this->customerNumber,
          this->name);
   cout << "OP: Customer " << setfill('0') << setw(4) << this->customerNumber
        << " added" << endl;
}

void Customer::sendShipment(string date, unsigned short int *invoiceNumber)
{
   // print shipment
   int quantityToShip = getQuantityToShip();
   if ( quantityToShip == 0 ) return;
   cout << "OP: Customer " << setfill('0') << setw(4) << customerNumber
        << ": shipped quantity " << quantityToShip << endl;
   // print invoice
   //todo: keep track of invoice numbers! (maybe a global variable)
   cout << "SC" << ": customer " << setfill('0') << setw(4) << customerNumber
        << ": invoice " << *invoiceNumber << ": date " << date.c_str()
        << ": quantity: "
        << quantityToShip << endl;
   //remove orders which have been sent (reset orders to empty)
   orders.clear();
   *invoiceNumber = *invoiceNumber + 1;
}

void
Customer::processOrder(string orderDetails, unsigned short int *invoiceNumber)
{
   Order order = Order(orderDetails);
   orders.push_back(order);
   //todo: error handling for incorrect input string
   cout << "OP: Customer " << setfill('0') << setw(4) << this->customerNumber
        << ": " << order.getOrderType().c_str() << " order" << ": quantity "
        << order.getQuantity() << endl;

   if ( order.isExpress())
      sendShipment(order.getDate(), invoiceNumber);
}

int Customer::getQuantityToShip()
{
   int       runningTotal = 0;
   for (auto &order : orders)
   {
      runningTotal += order.getQuantity();
   }
   return runningTotal;
}
