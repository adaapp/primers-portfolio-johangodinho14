#include <iostream>
#include <regex>
#include <vector>
#include <map>

//Checks if a given string contains numerical digits
bool containsDigit(std::string value){
  for(int i=0;i<value.length();i++){
    if((!!isdigit(value[i])==true)){
      return true;
    }
  }
  return false;
}

//Checks if a given string contains alphabetical characters
bool containsAlpha(std::string value){
  for(int i=0;i<value.length();i++){
    if(isalpha(value[i])){
      return true;
    }
  }
  return false;
}

//Checks if a given string contains special characters
bool containsSpecialCharacters(std::string value){
    std::regex validSpecialCharacters("[^a-zA-Z0-9]+");
    if(regex_search(value,validSpecialCharacters)){
      return true;  
    }else{
      return false;
    }
}

//Counts the total number of digits present in a given string
int countDigits(std::string value){
    int numberOfDigits = 0;
    
    for(int i=0;i<value.length();i++){
        if((!!isdigit(value[i])==true)){
            numberOfDigits +=1;
        }
    }
   return numberOfDigits;
}

//Counts the total number of alphabetical characters in a given string
int countAlpha(std:: string value){
  int numberOfAlphas = 0;
  
  for(int i=0;i<value.length();i++){
    if(isalpha(value[i])){
      numberOfAlphas +=1;
    }
  }
  return numberOfAlphas;
}

//Checks if a given string is a weak password
bool isWeak(std::string value){
  if(((containsDigit(value)==true) && (containsAlpha(value)==true)) || (containsSpecialCharacters(value)==true)){
    return false;
  }else{
    return true;
  }
}

//Checks if a given string is a strong password
bool isStrong(std:: string value){
    //>=8 chars
    // includes at least 2 numbers
    // includes at least 4 alphas
    if((value.length()>=8) && (countDigits(value)>=2) && (countAlpha(value)>=4) && (containsSpecialCharacters(value)==false)){
        return true;
    }
    return false;
}

//Checks if a given string is a very strong password
bool isVeryStrong(std:: string value){
    //>=8 chars
    //inlcudes at least  2 numbers
    //includes at least  4 alphas
    //includes at least  1 specialchar
    if((value.length()>=8) && (countDigits(value)>=2) && (countAlpha(value)>=4) && (containsSpecialCharacters(value)==true)){
        return true;
    };
    return false;
}

//Checks if a a given string is a moderate password 
bool isModerate(std:: string value){
    //>= 4 chars
    // not weak, strong or very strong
    if((value.length()>=4) && (isWeak(value)==false) && (isStrong(value)==false) && (isVeryStrong(value)==false)){
        return true;
    }
    return false;
}
 
//Returns the value that corresponds the strength of a password provided as the parameter.
int passwordComplexityCheckerMain(std:: string password){
    if(isWeak(password) == true){
        return 1;
    }
    if(isModerate(password) == true){
        return 2;
    }
    if(isStrong(password) == true){
        return 3;
    }
    if(isVeryStrong(password) == true){
        return 4;
    }
    return 0;
}

void passwordComplexityChecker(void) {
    int passwordComplexity;
    std::vector<std::string> testPasswords = {"12345678","AB235","Password2021","Password2021!"};
    
    //Creating a map for passwordComplexityCheckerMain function outputs
    std::map<int,std::string> map {{1,"Weak"},{2,"Moderate"},{3,"Strong"},{4,"Very Strong"}};
    
    //Finding the complexity of testPasswords
    for(int i=0;i<testPasswords.size();i++){
        passwordComplexity = passwordComplexityCheckerMain(testPasswords[i]);
        std::cout<<"The  password '"<<testPasswords[i]<<"'"<<" is "<<map[passwordComplexity]<<"\n";
    }
}

// --------------------------- Employee List Removal -------------------------

//Returns noOfEmployees of given array
int noOfEmployeesIn(std::string array[],int size){
    int noOfEmployees = 0;
    for(int i=0;i<size;i++){
        if(array[i]=="none"){
            continue;
        }
        noOfEmployees++;
    }
    return noOfEmployees;
}


//Prints given array
//Ignores string -> "none"
void printArray(std::string array[], int size,int noOfEmployees){
    std::cout<<"\nThere are "<<noOfEmployees<<" employees\n";
    for(int i=0;i<size;i++){
        if(array[i]=="none"){
            continue;
        }
        std::cout<<array[i]<<std::endl;
    }
}

//Finds index of given string, returns -1 if string was not found in array
int indexOf(std::string array[], int size, std::string searchValue){
    for(int i=0;i<size;i++){
        if(array[i]==searchValue){
            return i;
        }    
    }
    return -1;
}

//Replaces element at a given position (index) in the list with string "none"
//NOTE : The function replaces element in array inplace rather than returning it
void deleteElement(std::string array[],int targetIndex){
    if(array[targetIndex]!="none"){
        array[targetIndex] = "none";    
    }
}

//Get string input from user and return the result
std::string input(std::string message){
    std::string temp;
    std::cout<<message;
    std::getline(std::cin,temp);
    return temp;
}

void employeeListRemovalMain(){
    //Declaring array with employee names
    std::string names[] = {
        "John Smith",
        "Jaelynn Stuart",
        "Kaley Barajas",
        "Walter Collier",
        "Cale Myers"
    };
    std::string selectedName;
    int selectedNameIndex;
    int size;
    int noOfEmployees;
    
    do{
        //Calculating size of array
        size = (sizeof(names) / sizeof(names[0]));
        //Getting the lenght of the array (number of valid elements / employees)
        noOfEmployees = noOfEmployeesIn(names,size);
        //Getting user input if noOfEmployees is > 0
        if(noOfEmployees > 0){
            //Displaying list of Employees
            printArray(names,size,noOfEmployees);
            //Getting user input
            std::cout<<"\n";
            selectedName = input("Enter an employee name to remove:");
            std::cout<<"\n";
            //Finding index of selectedName in the array
            selectedNameIndex = indexOf(names,size,selectedName);
            //Checkinf if the selectedName exists in the array
            if(selectedNameIndex != -1){
               //Replacing selectedName value with "none" in the array;
               deleteElement(names,selectedNameIndex);
            }else{
               std::cout<<"Employee name entered does not exist in the list\n";   
            } 
        }else{
            std::cout<<selectedName<<" was removed from the list\n";
            std::cout<<"No more employees in list to show";
        }
       
    }
    while(noOfEmployees>0);
 
}


void employeeListRemoval(void) {
  employeeListRemovalMain();
}
