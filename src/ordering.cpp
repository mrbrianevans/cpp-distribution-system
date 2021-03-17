#include "ordering.h"
#define DEBUG 0
#define STARTING_INVOICE_NUMBER 1000

int main(int argc, char **argv)
{
   if ( argc != 2 )
   {
      cerr << "\x1b[31mYou need to provide a filename for the input\x1b[0m"
           << "\nTry ./ordering testInputFile.txt" << endl;
      return EXIT_FAILURE;
   }
   else
   {
      try
      {
         ordering::run(argv[1]);
         return EXIT_SUCCESS;
      } catch (string &e)
      {
         cerr << e << endl;
         return EXIT_FAILURE;
      }
   }
}

void ordering::run(const std::string &filename)
{
   if ( DEBUG ) cout << "Opening file: " << filename.c_str() << endl;
   ifstream input_file;
   input_file.open(filename);
   if ( !input_file.is_open())
   {
      throw string("Cannot read file: " + filename);
   }
   else if ( DEBUG )
      cout << "Successfully opened: " << filename.c_str() << endl;
   // the buffer is a temporary placeholder to read each line from the file into
   string                            buffer;
   unsigned short int                invoiceNumber = STARTING_INVOICE_NUMBER;
   unsigned short int                customerNumber; // temporary key for map
   unsigned int                      date;
   unsigned short int                lineNumber    = 0;
   // map to store customers with customer number as the key

   map<unsigned short int, Customer> customers;
   while ( getline(input_file, buffer))
   {
      try
      {
         if ( lineNumber < USHRT_MAX ) // never exceed max value (~65k)
            lineNumber++; // keeps track of line numbering for error messages
         if ( buffer.length() < 1 )
            throw string("Line not long enough (shorter than 1 character)");
         switch ( buffer[0] )
         {
            case 'C':
               if ( buffer.length() < 6 )
                  throw string(
                        "New customer record too short (less than the required 6 characters)");
               stringstream(buffer.substr(1, 4)) >> customerNumber;
               customers.emplace(customerNumber, buffer);
               break;
            case 'S':
               if ( buffer.length() != 17 )
                  throw string(
                        "Sale record too short (not the required 17 characters)");
               stringstream(buffer.substr(10, 4)) >> customerNumber;
               // checks that customer exists before placing order to avoid error
               // if customer doesn't exist, it prints an error, but doesn't exit
               if ( customers.find(customerNumber) == customers.end())
               {
                  stringstream errorMessage;
                  errorMessage
                        << "Order placed by non-existent customer. Customer number: "
                        << customerNumber;
                  throw errorMessage.str();
               }
               else
                  customers.at(customerNumber).processOrder(buffer,
                                                            &invoiceNumber);
               break;
            case 'E':
               if ( buffer.length() != 9 )
                  throw string(
                        "End of day record too short (not the required 9 characters)");
               stringstream(buffer.substr(1)) >> date;
               cout << "OP: end of day " << date << endl;
               //loop through customers calling sendShipment(date) on each one
               for (auto &customer : customers)
                  customer.second.sendShipment(date, &invoiceNumber);
               break;
            default:
               // prints error message, but does not stop processing
               throw string("First character must be 'C', 'S' or 'E'");
         }
      } catch (string &e)
      {
         // string errors have been thrown by syntax errors in the input line
         // prints error message, but does not stop processing
         cerr << "\n\x1b[31mWarning \x1b[0mLine " << lineNumber
              << " could not be processed: \n" << e << "\nLine contents: "
              << buffer << "\n" << endl;
      } catch (...)
      {
         cerr
               << "\n\x1b[31mWarning \x1b[0mAn unexpected error occurred on Line "
               << lineNumber << "\nLine contents: " << buffer << "\n" << endl;
         input_file.close(); // close the file before elevating error to main
         throw;
      }
   }
   if ( DEBUG ) cout << "Closing file" << filename.c_str() << endl;
   input_file.close();
}

