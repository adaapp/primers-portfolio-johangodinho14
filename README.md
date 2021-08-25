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
*	Create a function that can return the max between two given numbers
*	Create a function that can display the headings of the table
*	Create a function that can display the rows of the table
*	Create a function that can display the underlines of the headers
* Create a function that can read and manipulate the data file that is being read

#### Reflection (as well as issues, challenges & resolutions)
The overall challenge didn’t feel too difficult as some code snippets were obtained from the previous primer (primer 5). There was a lot of testing that was carried out to make sure that the table was well formatted once the data was parsed and displayed. 
Since most of the functionality of the program had been divided into separate helper functions, debugging was very easy. The main hurdle that I faced was being able to understand, how far to automate the parser. In the end I decided to stick to the requirements and create a parser that can take data from a file and display it in a properly formatted table.

### Primer 7 - Sleep timer
This challenge involved creating a sleep timer function that was able to block the execution of the thread it’s being called by for a given number of seconds. The function had a default parameter of 10 seconds if the seconds parameter was not provided. To overcome the challenge, I was able to use the threading functionality from the standard library to allow the current thread to be halted (sleep_for) for a given number of seconds.

#### Reflection (as well as issues, challenges & resolutions)
The program was overall very straight forward to implement. Although I discovered a minor bug which was that the `sleep_for` function being used to halt the thread required the sleep time parameter to be in milliseconds. In order to avoid this logical error, I simply had to convert the seconds into milliseconds before passing it to the `sleep_for` function in the standard library.

### Primer 8 - Joining & Detaching threads
This challenge involved creating two helper functions that would mainly be used for the joining and detaching of the threads. The main purpose of the challenge was to experiment with threads and understand their purpose. I broke down the program into multiple functions so that it was easy to understand. The function breakdown has been explained below:
* 2 Timer functions, each timer functions sleeps for a specific amount of time. Each function is to be used by the threads that are created. E.g., Timer 1 is to be used by thread 1 and timer 2 is to be used by Thread 2. In this manner it was easy to keep track of when the threads start and end.
* Join function: This function was created to create two different threads and assigned timer 1 and timer 2 to them. Once the threads were created and assigned to the functions, I used the `.join` function to make sure that the main thread waits for the two threads to complete without carrying on with further instructions.
*	Detach function: This function was the opposite of the join function as it allowed all the main thread to run at the same time as the other two threads. This meant that the main thread didn’t wait for the 2 threads to complete their execution and would finish the program beforehand.

#### Reflection (as well as issues, challenges & resolutions)
The detach function was a challenge as the main thread would complete without waiting for the 2 threads that were assigned to timers to be completed. To solve this challenge, I utilised the sleep function that was created in primer-7 to allow the program to sleep for 15 seconds, which is the amount of time it takes for both threads detached to complete.

### Primer 9 - Car Class 
This challenge involved creating a class (Car), that had several public methods that could be used by the user. The class also involved private members / properties to which only methods of the class had access to. Methods that were created in the class have been stated below:
*	Set make – set the colour of the car 
*	Set color – set the make of the car
*	Get color – get the color of the car
*	Get make – get the make of the car

The methods explained above are mainly getters and setters and are used by the methods in the class to assign properties to the class while adding additional validation. The main methods available to the user via the menu have been stated below:
* Engine on – Changes the status of the engine to on
*	Engine off – Changes the status of the engine to off 
*	Locked – Allows the car to be either locked or unlocked.
*	Status - Displays all the properties of the car e.g., make, color, engine status, lock status.

#### Reflection (as well as issues, challenges & resolutions)
Overall, I enjoyed this challenge as the syntax of creating classes and the logic behind it was very similar to python. The challenging part of the primer was finding out how to instantiate the class with properties, rather than always using the default make and colour. Once that was sorted, the rest of the program worked well.

### Primer 10 - Area of
This challenge involved creating a general Areaof class that was able to workout the area of several shapes using a single method. The assignment specified making the use of private properties, function overload and a destructor as well. 

#### Reflection (as well as issues, challenges & resolutions)
Since I was new to the concept of function destructors, I had to carry out a bit of research based on how I could use a single method to find the area of several shapes solely based on the number parameters that are provided to the method. Once I wrapped my head around overloading functions, I was able to select three shapes that required different number of parameters to calculate area and then was able to use a single overloaded method in the class to workout the area of three given shapes.



## Section 2 - Programming Paradigms
### Programming Paradigms
In this section of the README, I will be discussing 5 paradigms of programming along with their differences and benefits of using them.
### Functional programming 
Functional programming is a programming paradigm where programs are created by creating a composition of various pure functions. Pure functions are functions that are solely designed to serve one purpose and the outcome of them always remains the same. Functional programming avoids creating functions that depend on state or have other side effects.
Using function programming could help make sure that you write pure functions which are easy to debug. It also helps ensure other functions aren’t affected if one of the functions breaks down since they don’t rely on state and always produce the same outcome. This helps ease the process of debugging and would also help improve reliability.
### Structured 
Structured programming is a program that is solely written with the constructions such as:
•	Sequence – Sequence defines the order in which the instructions of a program are executed. 
•	Repetition – Iteration or repetition is making the use of loops to execute a line or block of code several forever or until a given requirement is met.
•	Selection – conditional statements, allow blocks of code to be executed only if a specific condition is met.
Structured programming is used in almost all programs as it enables programmers with some of the fundamental functionalities such as loops, and conditional statements, which are a must while creating normal programs or algorithms. 
Using structured programming allows for programs to be easier to read, while also allowing errors to be found easily, hence reducing the time spent debugging. This paradigm also helps define what the logical flow of the program should be 
### Declarative
Declarative programming is a programming paradigm which allows for the structure and elements of computer programs to express the logic of a function or computation without describing the actual instructions.
The use of declarative programming can be very useful as it allows for higher order functions to be used and makes sure that the code is abstract and easy to understand. This helps ensure reduction in the overall amount of time that is taken to understand and debug code.
### Event Driven
Event driven programming is a programming paradigm in which the flow of the program is not defined and is determined by events that are triggered based on user actions or the code itself.
Event driven programming can be very beneficial as it allows for code to be abstract while also allowing code to run in non-blocking fashion. This type of programming paradigm simplifies the creation of GUI’s and can be easy to understand. Using it could overall increase readability and help reduce the amount of time spent on debugging.
### Object oriented
Object oriented programming is a programming paradigm based on the concept of objects. These objects contain data and code, data is stored in the form of properties / members. The objects can also have behaviours which are known as methods.
This method of programming allows for code to be as detailed or abstract as needed. It also allows code to be clean as it supports features such as inheritance which allows for methods and members of other classes to be shared.
The concept of Object Oriented Programming allows for classes to instantiated into as many objects as required. Each object can be instantiated with different properties, which means that they could behave different if needed. The use of Object-Oriented Programming improves readability in code, while also making code abstract and allowing for a problem to be broken down into several classes. 

## Section 3 - Continued Professional Development
Continued Professional Development is one of the key factors that define a great programmer. It is very important to keep updated with the latest programming languages and frameworks in order for a programmer to be as efficient as possible and create programs that are robust. A programmer that follows CPD will benefit highly as it increases productivity and employability too.

### Benefits of becoming a Polyglot Programmer
A polyglot programmer is a programmer / developer that knows multiple programming languages and is aware of their limitations and benefits. Such programmers are highly valued due to their extensive knowledge of programming languages and paradigms. 

Polyglot programmers most likely have extensive knowledge of low-level programming giving them a solid understanding of how things work under the hood. They are able to differentiate between different data types and use the ones that are most efficient.

Such programmers also have the ability to bridge multiple languages together if needed for the right reasons. Due to all the positive points discussed, polyglot programmers could find it fairly easy to find new jobs and are more employable, due to the diverse knowledge they have.

Knowing more than one programming language will also make sure that programmers can keep their jobs while progressing with their goals and achieving higher standards. Due to many reasons companies may seek to use more than one language in this case, knowing multiple programming languages comes as a plus.
Being polyglot means that the programmer is prepared in case a programming language dies away or a new language takes over. This helps avoid additional time being spent on learning a language due to the preparation done in advance.

Many jobs now days are web related and require full stack programmers, meaning that programmers are required to know all the languages that form a stack in order to build completely robust and reliable websites or web applications. In such cases polyglot programmers have a great advantage as they don’t have to spend too much time upskilling.

Apart from having benefits on the front of employability and finance, being a polyglot programmer allows programmers to be mentally sharp as, learning new languages introduces new features or insights that a programmer previously wasn’t aware of. This exercise helps the programmer keep his problem-solving ability constantly in use. Lastly to conclude, being a polyglot programmer is overall beneficial to both the programmer and the workplace he works in, as it will allow for personal growth as well as high performance at work.

