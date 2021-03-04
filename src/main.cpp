#include "main.h"

int main(int argc, char **argv)
{
   main::run(argv[1]);
}


void main::run(std::string filename)
{
   // read file and process orders
   cout << "Reading file: " << filename.c_str() << endl;
   map<unsigned short int, Customer> customers;

   string testInputs[17];
   testInputs[0] = "C0001Royal Devon & Exeter Hospital";
   testInputs[1] = "C0002Derriford Hospital";
   testInputs[2] = "C0003Torbay Hospital";
   testInputs[3] = "S20210201N0001040";
   testInputs[4] = "S20210201N0001050";
   testInputs[5] = "E20210201";
   testInputs[6] = "S20210202N0001040";
   testInputs[7] = "S20210202N0001060";
   testInputs[8] = "S20210202N0002050";
   testInputs[9] = "S20210202N0002170";
   testInputs[10] = "E20210202";
   testInputs[11] = "S20210203N0001050";
   testInputs[12] = "S20210203N0002065";
   testInputs[13] = "S20210203N0003150";
   testInputs[14] = "S20210203X0001190";
   testInputs[15] = "S20210203N0002110";
   testInputs[16] = "E20210203";

   for(int i = 0; i < 17; i++)
   {
      cout << i + 1 << ": ";
      unsigned short int customerNumber;
      char date[9]; // 8 characters + end of line
      switch( testInputs[i].at(0))
      {
         case 'C':
            sscanf(testInputs[i].c_str(), "C%4hu", &customerNumber);
            customers.emplace(customerNumber, testInputs[i]);
            break;
         case 'S':
            sscanf(testInputs[i].c_str(), "S%*d%*c%4hu", &customerNumber);
            if( customers.end() == customers.find(customerNumber))
               cerr << "Order placed for non-existant customer" << endl;
            else
               customers.find(customerNumber)->second.processOrder(
                     testInputs[i]);
            break;
         case 'E':
            sscanf(testInputs[i].c_str(), "E%8s", date);
            cout << "OP: end of day " << date << endl;
            //loop through customers calling sendShipment(date) on each one
            for(auto customer = customers.begin();
                customer != customers.end(); ++customer)
               customer->second.sendShipment(date);
            break;
         default:
            cout << "Unknown: " << testInputs[i].c_str() << endl;
      }
   }
}

