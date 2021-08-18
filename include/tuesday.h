#include <iostream>
#include <regex>

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
    std::regex validSpecialCharacters("[@_!#$%^&*()<>?/|}{~:]");
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
 
//Returns the strength of a password provided as the parameter.
int passwordComplexityCheckerMain(std:: string password){
    if(isWeak(password) == true){
        return 1;
    }
    else if(isModerate(password) == true){
        return 2;
    }
    else if(isStrong(password) == true){
        return 3;
    }
    else if(isVeryStrong(password) == true){
        return 4;
    }
    else{
        return 0;
    }
}

void passwordComplexityChecker(void) {
	std::cout<<passwordComplexityCheckerMain("hellowrold12");
}

// --------------------------- Employee List Removal -------------------------
void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}
