#include "main.h"
using namespace std;

int main()
{
   cout << "Hello World!" << endl;
   main::run("inputfile");
}

void main::endOfDay()
{
}

void main::run(std::string filename)
{
   // read file and process orders
   cout << "Reading file: " << filename.c_str() << endl;
   map<int, Customer> customers;

   string testInputs[11];
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

   for(int i = 0; i < 11; i++)
   {
      cout << i << ": ";
      int customerNumber; //customer number is always 4 characters
      //date is causing an error of some kind??
      char date[8];
      switch( testInputs[i].at(0))
      {
         case 'C':
//            cout << "New customer: " << testInputs[i].c_str() << endl;
            sscanf(testInputs[i].c_str(), "C%4d", &customerNumber);
            customers.emplace(customerNumber, testInputs[i]);
            break;
         case 'S':
//            cout << "Sale: " << testInputs[i].c_str() << endl;
            sscanf(testInputs[i].c_str(), "S%*d%*c%4d", &customerNumber);
//            cout << "Customer number: " << customerNumber << endl;
            if( customers.end() == customers.find(customerNumber))
               cout << "Error caught and handled" << endl; // this must be done
            else
               customers.find(customerNumber)->second.processOrder(
                     testInputs[i]);
            break;
         case 'E':
            sscanf(testInputs[i].c_str(), "E%s", date);
            cout << "OP: End of day " << date << endl;
            //loop through customers calling end of day
            break;
         default:
            cout << "Unknown: " << testInputs[i].c_str() << endl;
      }
//      delete &customerNumber;
//      delete[] &date;
   }
}

