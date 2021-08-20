#include <iostream>
#include<thread>

//Sleep for a given amount of seconds
//Deaults to 10 seconds if no argument is provided
void sleep(int seconds = 10){
    //Calculating seconds in ms
    int ms = seconds * 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void sleepTimer(void) {
  std::cout<<"Sleeping for 5 seconds\n";
  sleep(5);
  std::cout<<"Finished sleeping for 5 seconds";
}


// ------------------  Join detach threads ------------------------------------
void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}