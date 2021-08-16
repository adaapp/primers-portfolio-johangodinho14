#include <iostream>//defines the standard devices cin, cout, clog, ceer; for more info see http://www.cplusplus.com/reference/iostream/
#include <string> //defines string types and conventions including begin & end iterator; for more info see http://www.cplusplus.com/reference/string/
#include <algorithm>//defines a collection of ranged functions; for more info see http://www.cplusplus.com/reference/algorithm/
#include <random>//defines random number generation facilities; for more info see http://wwww.cplusplus.com/reference/random/
#include <ctime>//declares a set of functions, macros and types to work with date and time information e.g. the time() function is used to get the current time

//include default source files for daily primer challenges
#include "include/monday.h"
#include "include/tuesday.h"
#include "include/wednesday.h"
#include "include/thursday.h"
#include "include/friday.h"

//function declarations:
//tell the compiler about the function; required if function isn't compiled prior to reference
void menu(void);

//this is the 
int main() {
	menu();
	return 0; //return value (0) typically used to indicate a 'no error' status
}

/** 
* Prompts the user to press 'Enter' before continuing. 
* Without this, the menu would be displayed immediately after an option is completed,
* thereby forcing the user to scroll up to see its resulting output.
*/
void prompt(void) {
  std::cout << "\nPress 'Enter' to continue...\n";
  std::cin.get(); //wait for a key press
}

void menu(void) {
  std::string choiceString;
	int choice = -1; //declare and initialise an integer type variable
	do { //set up a continuous loop
		std::cout << "\nAdvanced Programming - Primers Portfolio Menu:\n";
		std::cout << "Monday (Basic Programming Primers)\n";
		std::cout << "\t1. Fahrenheit / Centigrade conversion\n";
		std::cout << "\t2. Self-service checkout\n";

		std::cout << "\nTuesday (Data Types, Manipulation & Structures)\n";
		std::cout << "\t3. Password complexity checker\n";
		std::cout << "\t4. Employee list removal\n";

		std::cout << "\nWednesday (IO Streams, File & Error Handling)\n";
		std::cout << "\t5. Phone directory\n";
		std::cout << "\t6. Data file parser\n";

		std::cout << "\nThursday (Multi-Threading & Concurrency)\n";
		std::cout << "\t7. Sleep timer\n";
		std::cout << "\t8. Joining & Detaching threads\n";

		std::cout << "\nFriday (Classes and Objects)\n";
		std::cout << "\t9. Car class\n";
		std::cout << "\t10. Area of\n";

		std::cout << "\n\t0. Quit\n";

		std::cout << "\nPlease enter option to run primer (e.g. 1 for Fahrenheit / Centigrade conversion 01): ";
  	getline(std::cin, choiceString);
    // TODO: validate input string
    choice = stoi(choiceString);

		switch(choice) {
      // perform the task for the chosen option, then ask the user to press 'Enter' before 
      // returning to the main menu (thereby enabling them to more easily view the output)
			
			//monday
			case 1: fahrenheitCentigradeConversion(); break;
			case 2: selfServiceCheckout(); break;

			//tuesday
			case 3: passwordComplexityChecker(); break;
			case 4: employeeListRemoval(); break;

			//wednesday
			case 5: phoneDirectory(); break;
			case 6: dataFileParser(); break;

			//thursday
			case 7: sleepTimer(); break;
			case 8: joinDetachThreads(); break;

			//friday
			case 9: carClass(); break;
			case 10: areaOf(); break;
			
			
			case 0: std::cout << "Exiting"; break;
			default:
				std::cout << "\n'" << choice << "' is an invalid option  - please try again.";
				break;
		}
    // ask the user to press 'Enter' before returning to the main menu
    // (thereby enabling them to more easily view the output)
    prompt();
	} while(choice != 0);

	std::cout << " - Done\n\n";
}
