#include "ordering.h"

int main(int argc, char **argv)
{
   if ( argc != 2 )
      cerr << "You need to provide a filename for the input" << endl;
   else ordering::run(argv[1]);
}

void ordering::run(std::string filename)
{
   // read file and process orders
   cout << "Reading file: " << filename.c_str() << endl;
   //todo: actually read file
   map<unsigned short int, Customer> customers;
   string                            testInputs[17];

   testInputs[0]  = "C0001Royal Devon & Exeter Hospital";
   testInputs[1]  = "C0002Derriford Hospital";
   testInputs[2]  = "C0003Torbay Hospital";
   testInputs[3]  = "S20210201N0001040";
   testInputs[4]  = "S20210201N0001050";
   testInputs[5]  = "E20210201";
   testInputs[6]  = "S20210202N0001040";
   testInputs[7]  = "S20210202N0001060";
   testInputs[8]  = "S20210202N0002050";
   testInputs[9]  = "S20210202N0002170";
   testInputs[10] = "E20210202";
   testInputs[11] = "S20210203N0001050";
   testInputs[12] = "S20210203N0002065";
   testInputs[13] = "S20210203N0003150";
   testInputs[14] = "S20210203X0001190";
   testInputs[15] = "S20210203N0002110";
   testInputs[16] = "E20210203";

   unsigned short int invoiceNumber = 1000;
   //todo: loop through file rather than string array
   for (int i = 0; i < 17; i++)
   {
      //todo: this print out is for testing only, remove before submission
      cout << i + 1 << ": ";
      unsigned short int customerNumber;
      char               date[9]; // 8 characters + end of line = 9
      switch ( testInputs[i].at(0))
      {
         case 'C':
            sscanf(testInputs[i].c_str(), "C%4hu", &customerNumber);
            customers.emplace(customerNumber, testInputs[i]);
            break;
         case 'S':
            sscanf(testInputs[i].c_str(), "S%*d%*c%4hu", &customerNumber);
            if ( customers.end() == customers.find(customerNumber))
               cerr << "Order placed by non-existant customer: "
                    << customerNumber << endl;
            else
               customers.at(customerNumber).processOrder(testInputs[i],
                                                         &invoiceNumber);
            break;
         case 'E':
            sscanf(testInputs[i].c_str(), "E%8s", date);
            //todo: error handling for invalid date
            cout << "OP: end of day " << date << endl;
            //loop through customers calling sendShipment(date) on each one
            for (auto &customer : customers)
               customer.second.sendShipment(date, &invoiceNumber);
            break;
         default: //todo: error handling
            cerr << "Unknown input string: " << testInputs[i].c_str() << endl;
      }
   }
}

