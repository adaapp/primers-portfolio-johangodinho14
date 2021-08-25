# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge involved converting Fahrenheit to centigrade and vice versa. In order to complete the challenge, I had to break the problem down into the following steps:

* Getting an input from the user
* Checking which option, the user has selected (F-C or C-F)
* Creating separate functions to convert from (C-F and F-C)
* Running the relevant function based on the user input
* Outputting the result to the user.

#### Reflection (as well as issues, challenges & resolutions)
The main challenge that I faced was adding the Kelvin conversion which was an additional exercise. Due to the well-structured code, I was able to add an additional function that calculates temperatures from Centigrade to Kelvin. I then linked the function with the conditional statements so that the user would be able to select the Centigrade to Kelvin temperature conversion. 

Lastly to make sure that the code had validation, I added a conditional statement which would prompt the user if he/she were to enter an invalid option.

### Primer 2 - Self-service Checkout
This challenge involved creating a self-service checkout program that had the ability to get user input related to the quantity and price of items. The program was required to apply a constant shopping tax to the sub-total and display the total amount (subtotal + shopping-tax) that has to be paid at the end. To create the program, I decided to split the problem into steps which have been stated below:

* Getting input from the user regarding the price and quantity of items
* Creating a loop that will keep asking for user input until the quantity entered is 0
*	Keep track of the subtotal based on the quantity and price of the items 
*	Calculate the shopping tax once the user has pressed 0
*	Calculate the total based on the subtotal and shopping tax once the user has pressed 0
*	Display the subtotal, total and shopping tax breakdown to the user at the end of the loop.

#### Reflection (as well as issues, challenges & resolutions)
The main challenge I faced during the whole primer was getting used to the syntax in C++. I constantly ran into syntax errors due to the fact that I usually program in either JavaScript or python which are both high level languages. Once I got used to the syntax of C++, I was able to implement the primer without too many hurdles. Another issue I faced was constantly forgetting to change the user input from string to the right data type e.g., quantity has to be changed from string to int, this would cause bugs / errors, resulting in more time being spent debugging.

### Primer 3 - Password complexity checker
This primer involved using a lot of logic and inbuilt functions. In order to keep the code, clean I decided to create helper functions that solely had a single purpose. I then used these functions to check the characteristics of a given password (string), e.g., does the password have digits? how many digits does the password have? etc. Shown below is the breakdown I used to split the problem into functions:

*	Check if a string contains digits 
*	Check if a string contains alphabets
*	Check if a string contains special characters (used regex)
*	Return a count of the number of digits in a string
*	Return a count of the number of alphabets in a string

#### Reflection (as well as issues, challenges & resolutions)
Once these helper functions were ready, I decided to further breakdown the problem by creating functions that would use the helper functions to determine whether a given password (string) was a weak, moderate, strong, or very strong password, based on the criteria provided in the assignment. Lastly the isWeak(), isModerate(), isStrong and isVeryStrong(), functions were used in combination with conditional statements to check the complexity of a given password (string).
Breaking down the problem into the chunks (functions), allowed me to have pure functions with no side effects. Debugging in this manner was a lot simpler, as I could pinpoint errors and fix them easily.

### Primer 4 - Employee list removal
This primer was challenging as it involved making the decision of what data type was to be used to keep track of the employees. I decided to use an array of strings to create the program. Due to the fact that an array is static, and things cannot be deleted once it has been declared, I had to replace any deleted names (strings) from the list with a placeholder string. The loop that displayed the employee names from the array, recognised the placeholder string and knew not to display it to the user as it was programmed into it using a conditional statement. The breakdown of the program has been displayed below:

*	Creating a function that can display employee names from the array to the user
*	Implementing the conditional in the display function so that the loop doesn’t show the placeholder string used in place of deleted employees.
*	Getting an input from the user (name of employee to be deleted – string)
*	Creating a function to get the index of the deleted employee name in the array
*	Creating a function to delete employee from the array based on given index. 

#### Reflection (as well as issues, challenges & resolutions)
Once the program was finished, I tested it to make sure that there were no bugs / errors. One of the issues I found was that the program wouldn’t tell the user if an inputted employee name wasn’t in the list. I realised this and added an output to let the user know if a given employee name didn’t exist in the array.
 
### Primer 5 - Phone directory

This challenge involved creating a phone directory where the program was able to read data from a file and output contact details based on whether the user typed in a phone number or contact name. To solve this challenge, I broke down the problem into the following steps:

*	Create a function that can read data from the file
*	Create a function that can write data to a file which will include the dummy contact data
*	Get an input from the user, asking for either the contact number or the contact’s name
*	Create a split function that can split a given string into a vector based on a delimiter
*	Create a loop that will go through the records in the file and match it to the user’s input 
*	If the user’s input matches either the contact number or contact name, display their contact details.
*	Get a count of how many records are being searched and display it to the user.

#### Reflection (as well as issues, challenges & resolutions)
Once the functions above were programmed, I tested the primer and found that the program wasn’t able to display 2 contact details if two contacts had the same name. This was due to the way the program was structured, as it was instructed to break out of the loop as soon as a match for the user input is found. This problem was resolved by getting rid of the break statement and re-structuring the code. I also added an extra piece of code that would tell the user if no matching records were found for the user input provided.

### Primer 6 - Data file parser
This challenge involved creating an advanced program that is able to read the data form a file, manipulate it, and present it in an organised manner separated by equal spaces. Due to some aspects of the challenge being similar to primer-5, I was able to re-use some of the functionality from primer-5, such as the read-file function and the split function. I decided to break the overall problem into the following steps:

*	Create a function that can create the raw file that has to be parsed and displayed
*	Create a function that can return length of string with max characters 




## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
