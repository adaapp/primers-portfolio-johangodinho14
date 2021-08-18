#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>

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
            result.push_back(currentString);
            currentString = "";
        }else{
            //Added each character of value to currentString
            currentString += value[i];
        }
        
        //When we reach the end of the string we push_back currentString to the vector.
        if(i==value.length()-1){
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


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}