#include <iostream>
#include <regex>


//Find if a given string is a valid number
bool isNumeric(std:: string value){
    /*
      Input:
          * Value to be tested 
      Output:
          * true  (1) -> if value is a valid number
          * false (0) -> if value isn't a valid number 
    */
  
  //Regex to recognize valid numerics
   std::regex validNumber("[+-]?(?=[.]?[0-9])[0-9]*(?:[.][0-9]*)?(?:[Ee][+-]?[0-9]+)?");
   
   if(regex_match(value,validNumber)){
     return true;
   }else{
     return false;
   }
}

//Round given float (2 decimals)
float round(float inputValue){
    float value = (int)(inputValue * 100 + .5);
    return (float)value / 100;
}

//Centigrade to Fahrenheit
float ctof(float c){
  return ((c * 9/5) + 32);
}

//Fahrenheit to Centigrade
float ftoc(float f){
  return ((f - 32) * 5/9);
}


//Sub-menu
void subMenu(){
  //Displaying sub-menu options
  std::cout<<"Press 'C' to convert from Fahrenheit to Centigrade.";
  std::cout<<"\nPress ‘F’ to convert from Centigrade to Fahrenheit.";
}

//Combines all helper functions to convert temperatures based on user input
void convertTemperature(){
  //Declaring variables
  std:: string strTemperature;
  std:: string selectedOption;
  std:: string label;
  float temperature;
  float result;

  //Getting the starting temperature as a string 
  std::cout<<"\nPlease enter the starting temperature:";
  getline(std::cin,strTemperature);
  
  //Checking if the starting temperature is a valid number 
  if(isNumeric(strTemperature)){
    //Converting strTemperature to type(float)
    temperature = stof(strTemperature);
    //Displaying the menu of options
    subMenu();
    //Grabbing input to find option selected
    std::cout<<"\n\nYour choice:";
    getline(std::cin,selectedOption);

    //Processing results based on selected option
    if(selectedOption == "C" or selectedOption == "c"){
      result = ftoc(temperature);
      label  = "Fahrenheit";
    }
    else if(selectedOption == "F" or selectedOption == "f"){
      result = ctof(temperature);   
      label  = "Centigrade"; 
    }
    else{
      std::cout<<"\nInvalid option selected."; 
      return;
    }

    //Displaying processed result and rounding result
    std::cout<<strTemperature<<" degrees "<<label<<" is "<<round(result);

  }
  else{
    std::cout<<"\nInvalid number entered as starting temperature.";
  }
}

 

void fahrenheitCentigradeConversion(void) {
	convertTemperature();
}


void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

