#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <regex>


//Used to write data to file either in write or append mode
void writeToFile(std::string filename,std::string value,std::string delimeter,bool append=true){
    std::ofstream fileObject;
    
    //Checking if we're using append mode for the file operation
    if(append){
        //Opening the file in append mode (writes to existing file)
        fileObject.open(filename,std::ios_base::app);
    }else{
        //Opening the file in write mode (creates a new file)
        fileObject.open(filename,std::ios_base::out);
    }
    
    //Writing value to the file 
    fileObject << value << delimeter;
    fileObject.close();
}

//Used to read data from file
//Returns vector with file data -> each line is a single element in the vector
std::vector<std::string> readFromFile(std::string filename){
    std::string line;
    std::ifstream fileObject;
    std::vector<std::string> result;
    
    //Opening file
    fileObject.open(filename);
    //Running the loop until we reach the end of the file
    while(!fileObject.eof()){
        getline(fileObject,line);
        result.push_back(line);
    }
    //Closing the file once we read all the data from it
    fileObject.close();
    return result;
}

//Used to split string individual elements of a vector based on delimeter
//Function returns string vector
std::vector<std::string> split(std::string value,char delimeter){
    std::vector<std::string> result;
    std::string currentString;
    
    //Iterating through the string value until we find the delimeter
    for(int i=0;i<value.length();i++){
        //When delimeter is found in the value we push currentString to the vector
        if(value[i]==delimeter){
            //Getting rid of uneeded whitespace
            currentString = std::regex_replace(currentString, std::regex("^ +| +$|( ) +"), "$1");
            result.push_back(currentString);
            currentString = "";
        }else{
            //Added each character of value to currentString
            currentString += value[i];
        }
        
        //When we reach the end of the string we push_back currentString to the vector.
        if(i==value.length()-1){
            //Getting rid of uneeded whitespace
            currentString = std::regex_replace(currentString, std::regex("^ +| +$|( ) +"), "$1");
            result.push_back(currentString);
        }
    }
    return result;
}

//Create a starter file with all data (.txt)
void createContactsFile(){
  writeToFile("contacts.txt","Rayyan,07393410574","\n",false);
  writeToFile("contacts.txt","JJ,07392220571","\n",true);
  writeToFile("contacts.txt","Mike,07456342570","\n",true);
  writeToFile("contacts.txt","JJ,07391110591","",true);
}

//NOTE: Definition for function-> input can be found in "tuesday.h"
// std::string input(std::string message){
//     std::string temp;
//     std::cout<<message;
//     std::getline(std::cin,temp);
//     return temp;
// }


void phoneDirectoryMain() {
  std::vector<std::string> splitResult;
  std::vector<std::string> lines;
  std::string currentName;
  std::string currentPhoneNo;
  std::string inputValue;
  bool resultFound = false;
    
  //Create .txt file which will include all contacts
  createContactsFile();
  
  //Getting data from contacts.txt as a vector. 
  //Each newline in the text file is treated as an individual element in the vector
  lines = readFromFile("contacts.txt");

  //Getting input from the user
  inputValue = input("Please enter a name or number to search:");

  //Displaying how many records will be searched
  std::cout<<"Searching "<<lines.size()<<" records ...";
  
  //Going through each element / item in vector->lines
  //Checking if any of the names / phone no's in the contacts.txt match the given input
  for(int i=0;i<lines.size();i++){
        splitResult    = split(lines[i],',');
        currentName    = splitResult[0];
        currentPhoneNo = splitResult[1];
        
        if(currentName == inputValue || currentPhoneNo == inputValue){
            std::cout<<"\n\nContact details:\n"<<currentName<<", "<<"T:"<<currentPhoneNo;
            resultFound = true;
        }
        
        //If we reach the end of the vector and no match was found, we notify the user.
        if((i==lines.size()-1) && (resultFound==false)){
            std::cout<<"\n\nSorry, no contact details found";
        }
  }

}


void phoneDirectory(void) {
	phoneDirectoryMain();
}


// ------------------------------- Data file parser --------------------------

//Used to read data from file
//Returns vector with file data -> each line is a single element in the vector
std::vector<std::string> readFromFileParser(std::string filename){
    std::string line;
    std::string initial;
    std::ifstream fileObject;
    std::vector<std::string> result;
    std::vector<std::string> splitResult;
    
    //Opening file
    fileObject.open(filename);
    //Running the loop until we reach the end of the file
    while(!fileObject.eof()){
        getline(fileObject,line);
        //Manipulating data
        splitResult = split(line,',');
        initial     = splitResult[0][0];
        splitResult[0] = initial +".,";
        splitResult[1] = splitResult[1] + ",";
        splitResult[2] = "£"+splitResult[2];
        line           = splitResult[0] + splitResult[1] + splitResult[2];

        result.push_back(line);
    }
    //Closing the file once we read all the data from it
    fileObject.close();
    return result;
}



//Create a starter file with all data (.txt)
void createRawFile(){
  writeToFile("rawData.txt","Noak, Jaylinn, 21500","\n",false);
  writeToFile("rawData.txt","Apollinaire, Venkata, 29250","\n",true);
  writeToFile("rawData.txt","Faith, Mara, 30000","\n",true);
  writeToFile("rawData.txt","Yasamin, Shukriyya, 44500","\n",true);
  writeToFile("rawData.txt","Zahir, Marcel, 31200","\n",true);
  writeToFile("rawData.txt","Maia, Ela, 45600","\n",true);
  writeToFile("rawData.txt","Liam, Oliver, 43300","\n",true);
  writeToFile("rawData.txt","Luka, Jones, 45600","\n",true);
  writeToFile("rawData.txt","Alexander, Smith, 20500","",true);
}

//Returns highest number of chars a string has
int findMaxChar(std::vector<std::string> lines,int colPosition){
    int max=0;
    std::string currentString;
    std::vector<std::string> resultsSplit ; 
    
    //Going through all the lines found as individual elements in the vector passed to the function
    for(int i=0;i<lines.size();i++){
        //Splitting each string to get the elements seperated into a vector e.g. ["Yasamin","Shukriyya","44500"]
        resultsSplit  = split(lines[i],',');
        currentString = resultsSplit[colPosition];
        //Finding max chars that a string may have
        if(currentString.length()>max){
            max = currentString.length();
        }
    }
    return max;
}

//Returns the max number between two given numbers
int max(int number1, int number2){
    if(number1 > number2){
        return number1;
    }else{
        return number2;
    }
}

//Displays Row headers
void displayHeaders(std::vector<std::string> lines,std::vector<std::string> headers){
    //Displaying headers
    for(int i=0;i<headers.size();i++){
        int spaceUnits;
        
        //Finding how many spaces to add between columns
        spaceUnits  = max(headers[i].length(),findMaxChar(lines,i))+1;
        spaceUnits  -= headers[i].length();
    
        std::cout<<headers[i]<<std::string(spaceUnits, ' ');
    }
    std::cout<<std::endl;
}

//Displays Header underlines
void displayHeaderUnderlines(std::vector<std::string> lines, std::vector<std::string> headers){
    for(int i=0;i<headers.size();i++){
        int spaceUnits;
        
        //Finding how many spaces to add between columns
        spaceUnits = max(headers[i].length(),findMaxChar(lines,i));
    
        std::cout<<std::string(spaceUnits,'-');
        std::cout<<' ';
    }
    
    std::cout<<std::endl;
}

//Displays row values in respective columns
void displayRows(std::vector<std::string> lines,std::vector<std::string>headers){
    //Displaying rows of data
    for(int i=0;i<lines.size();i++){
        int spaceUnits;
        std::vector<std::string> splitResults;
        
        //Getting each element from the splitResults vector
        splitResults = split(lines[i],',');
        for(int i=0;i<headers.size();i++){
            //Finding how many additional spaces to use 
            spaceUnits = max(headers[i].length(),findMaxChar(lines,i))+1;
            spaceUnits -= splitResults[i].length();
            
            std::cout<<splitResults[i]<<std::string(spaceUnits,' ');    
        }
        std::cout<<std::endl;
    }
}

//Displays and parses data read from file 
void displayTable(std::vector<std::string> lines ,std::vector<std::string> headers){
    //Displaying headers
    displayHeaders(lines,headers);
    
    //Displaying header underlines
    displayHeaderUnderlines(lines,headers);

    //Displaying rows 
    displayRows(lines,headers);
}

//Main function 
void dataFileParserMain(){
    std::vector<std::string> lines;
    std::vector<std::string> headers = {"Initial","Last","Salary"};
    
    //Creates file with raw data
    createRawFile();
    //Gets line from the raw data file in the form of a vector with strings
    lines = readFromFileParser("rawData.txt");
    //Displays table based on lines and headers // headers -> column heading names
    displayTable(lines,headers);
}

void dataFileParser(void) {
	dataFileParserMain();
}