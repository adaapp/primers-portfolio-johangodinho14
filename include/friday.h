#include <iostream>
#include <stdexcept>


class Car{
    //private properties
    private:
        std:: string colour_;
        std:: string make_;
        std:: string engine_;
        std:: string lockStatus_;
        bool isLocked_;
        

    public:
        //Setters
        void set_colour(std::string colour){
            if(colour.length()<1){
                throw std::invalid_argument("Received empty string as colour");
            }
            colour_ = colour;
        }
        void set_make(std::string make){
            if(make.length()<1){
                throw std::invalid_argument("Received empty string as make");
            }
            make_ = make;
        }
        
         //Constructor
        Car(std::string colour="Blue",std::string make="Honda"){
          set_colour(colour);
          set_make(make);
          engine_     = "Off";
          lockStatus_ = "Unlocked";
          isLocked_   = false;
        }
        
        //Getters
        std::string get_colour(void){
            return colour_;
        }
        std::string get_make(void){
            return make_;
        }
        
        //Normal Methods
        void engine_on(void){
            if(engine_=="On"){
                std::cout<<"\nSorry, engine is already on";
            }else{
                engine_="On";   
            }
        }
        
        void engine_off(void){
            if(engine_=="Off"){
                std::cout<<"\nSorry, engine is already off";
            }else{
                engine_="Off";
            }
        }
        
        void locked(bool status){
            if(isLocked_ == status){
                std::cout<<"\nSorry, the car is already "<<lockStatus_;
            }else{
                isLocked_ = status;
                if(isLocked_){
                    lockStatus_ = "Locked";    
                }else{
                    lockStatus_ = "Unlocked";
                }
                
            }
        }
        
        void status(){
            std::cout<<"\n\nCar Status: colour: "<<colour_<<", "<<"make: "<<make_<<", "<<"engine:"<<engine_<<", "<<lockStatus_;
        }
        
};

void carMenu(void){
    std::cout<<"\n1. Turn Engine On";
    std::cout<<"\n2. Turn Engine Off";
    std::cout<<"\n3. Lock Car";
    std::cout<<"\n4. Unlock Car";
}

void carMain() {
    //Instantiating class
    Car testCar("Blue","BMW");
    
    std::string userInput;
    int userInputInt;

    while(userInput != "0"){
        testCar.status();
        carMenu();
        std::cout<<"\nPlease select an option(or 0 to finish):";
        getline(std::cin,userInput);
        userInputInt = stoi(userInput);

        switch(userInputInt){
            case 1:
                testCar.engine_on();
                break;
            case 2:
                testCar.engine_off(); 
                break;
            case 3:
                testCar.locked(true); 
                break;
            case 4:
                testCar.locked(false);
                break;
            case 0:
                break;
                
            default:
                std::cout<<"Invalid option selected";
        }
    }
 
}

void carClass(void) {
		carMain();
}


void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}