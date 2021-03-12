#include <string>
#include "ordering.h"
#define DEBUG 0

int main(int argc, char **argv)
{
   if ( argc != 2 )
      cerr << "\x1b[31mYou need to provide a filename for the input\x1b[0m"
           << "\nTry ./ordering testInputFile.txt" << endl;
   else
   {
      ordering::run(argv[1]);
      return 0;
   }
   return 1;
}

void ordering::run(std::string filename)
{
   if ( DEBUG ) cout << "Opening file: " << filename.c_str() << endl;
   ifstream input_file;
   input_file.open(filename);
   if ( !input_file.is_open())
   {
      cerr << "\x1b[31mcannot read file: \x1b[0m" << filename.c_str() << endl;
      exit(EXIT_FAILURE);
   }
   string                            buffer;
   unsigned short int                invoiceNumber = 1000;
   unsigned short int                customerNumber;
   char                              date[9]; // 8 characters + end of line = 9
   map<unsigned short int, Customer> customers;
   while ( getline(input_file, buffer))
   {
      switch ( buffer[0] )
      {
         case 'C':
            stringstream(buffer.substr(1, 4)) >> customerNumber;
            customers.emplace(customerNumber, buffer);
            break;
         case 'S':
            stringstream(buffer.substr(10, 4)) >> customerNumber;
            if ( customers.find(customerNumber) == customers.end())
               cerr << "Order placed by non-existant customer: "
                    << customerNumber << endl;
            else
               customers.at(customerNumber).processOrder(buffer,
                                                         &invoiceNumber);
            break;
         case 'E':
            stringstream(buffer.substr(1, 8)) >> date;
            //todo: error handling for invalid date
            cout << "OP: end of day " << date << endl;
            //loop through customers calling sendShipment(date) on each one
            for (auto &customer : customers)
               customer.second.sendShipment(date, &invoiceNumber);
            break;
         default: //todo: error handling
            cerr << "\x1b[31mInvalid line: \x1b[0m" << buffer
                 << "\n(Hint: First character must be 'C', 'S' or 'E')" << endl;
            break;
      }
   }
   if ( DEBUG ) cout << "Closing file" << filename.c_str() << endl;
   input_file.close();
}

