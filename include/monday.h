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

//Centigrade to Kelvin
float ctok(float c){
  return c + 273.15;
}


//Sub-menu
void subMenu(){
  //Displaying sub-menu options
  std::cout<<"Press 'C' to convert from Fahrenheit to Centigrade.";
  std::cout<<"\nPress 'F' to convert from Centigrade to Fahrenheit.";
  std::cout<<"\nPress 'K' to convert from Centigrade to Kelvin";
}

//Combines all helper functions to convert temperatures based on user input
void convertTemperature(void){
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
    else if(selectedOption == "K" or selectedOption == "k"){
      result = ctok(temperature);
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

//------------------------ Self Service Checkout ------------------------------

//Calculating Shopping Tax
float calculateShoppingTax(float shoppingTaxConstant, float subtotal){
  return (subtotal/100)*shoppingTaxConstant; 
}

//Calculate the overall total
float calculateTotal(float shoppingTax, float subtotal){
  return subtotal + shoppingTax;
}

//Update subtotal based on the quantity and cost
float addItems(float subtotal,int quantity,float cost){
  return subtotal + (quantity * cost);
}

//Display results 
void displayResults(float subtotal,float shoppingTax,float total){
  std::cout<<"Thank you.\n\n";
  std::cout<<"Subtotal:£"<<subtotal;
  std::cout<<"\nShopping Tax:£"<<shoppingTax;
  std::cout<<"\n\nTotal:"<<total;
}

//Find if a given string is a valid integer
bool isInteger(std:: string value){
    /*
      Input:
          * Value to be tested 
      Output:
          * true  (1) -> if value is a valid integer
          * false (0) -> if value isn't a valid integer 
    */
  
  //Regex to recognize valid integers
   std::regex validInteger("\\d+");
   
   if(regex_match(value,validInteger)){
     return true;
   }else{
     return false;
   }
}

//Find if a given string is a valid float
bool isFloat(std:: string value){
    /*
      Input:
          * Value to be tested 
      Output:
          * true  (1) -> if value is a valid float
          * false (0) -> if value isn't a valid float 
    */
   std::regex validFloat("[+-]?(?=[.]?[0-9])[0-9]*(?:[.][0-9]*)?(?:[Ee][+-]?[0-9]+)?");
   
   if(regex_match(value,validFloat)){
     return true;
   }else{
     return false;
   }
}

void selfServiceCheckoutMain(void) {
  //Declaring variables
  std::string stringQuantity;
  std::string stringCost;
  int   quantity            = 1;
  int   itemNumber          = 1;
  float shoppingTaxConstant = 5.5; //Represents percentage
  float shoppingTax         = 0.0;
  float subtotal            = 0.0;
  float cost;
  float total;

  do{
    //Getting input from the user about quantity and item price
    std::cout<<"\nPlease enter the quantity for item "<<itemNumber<<" (or 0 to finish):";
    getline(std::cin,stringQuantity);

    //Checking if quantity is a valid integer
    if(isInteger(stringQuantity)){
          //Converting quantity from str to integer
          quantity = stoi(stringQuantity);

          //Making sure the user has not quit the program by setting quantity to 0
          if(quantity > 0){
              std::cout<<"Please enter item "<<itemNumber<<"'s cost:";
              getline(std::cin,stringCost);
              //Checking if cost is a valid float
              if(isFloat(stringCost)){
                //Converting cost from str to float
                cost     = stof(stringCost);
                //Updating sub-total 
                subtotal = addItems(subtotal,quantity,cost);
                //Updating item number 
                itemNumber ++;
              }else{
                std::cout<<"\nInvalid cost entered";
              }
          }

    }else{
      std::cout<<"\nInvalid quantity entered";
    }
  }while(quantity>0);

  //Calculating shopping tax based on the shopping tax constant
  shoppingTax = calculateShoppingTax(shoppingTaxConstant,subtotal);
  total       = calculateTotal(shoppingTax,subtotal);
  //Displaying end results (subtotal, shopping tax, total)
  displayResults(subtotal,shoppingTax,total);
}

void selfServiceCheckout(void) {
  selfServiceCheckoutMain();
}

