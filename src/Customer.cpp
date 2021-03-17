#include "Customer.h"

Customer::Customer(const string &customerDetails)
{
   stringstream(customerDetails.substr(1, 4)) >> this->customerNumber;
   this->name = stringstream(
         customerDetails.substr(5, MAX_CUSTOMER_NAME_LENGTH)).str();
   cout << "OP: Customer " << setfill('0') << setw(4) << this->customerNumber
        << " added" << endl;
}

void
Customer::sendShipment(unsigned int date, unsigned short int *invoiceNumber)
{
   // print shipment
   int quantityToShip = getQuantityToShip();
   if ( quantityToShip == 0 ) return;
   cout << "OP: Customer " << setfill('0') << setw(4) << customerNumber
        << ": shipped quantity " << quantityToShip << endl;
   // print invoice
   cout << "SC" << ": customer " << setfill('0') << setw(4) << customerNumber
        << ": invoice " << *invoiceNumber << ": date " << date << ": quantity: "
        << quantityToShip << endl;
   //remove orders which have been sent (reset orders to empty)
   orders.clear();
   *invoiceNumber = *invoiceNumber + 1;
}

void
Customer::processOrder(string orderDetails, unsigned short int *invoiceNumber)
{
   Order order = Order(orderDetails); // can throw exceptions
   orders.push_back(order);
   cout << "OP: Customer " << setfill('0') << setw(4) << this->customerNumber
        << ": " << order.getOrderType().c_str() << " order" << ": quantity "
        << order.quantity << endl;

   if ( order.express )
      sendShipment(order.date, invoiceNumber);
}

int Customer::getQuantityToShip()
{
   int       runningTotal = 0;
   for (auto &order : orders)
   {
      // loop through all a customers orders, keeping a running total
      runningTotal += order.quantity;
   }
   return runningTotal;
}
