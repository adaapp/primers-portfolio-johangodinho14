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

//Global variables to tell the timer how long to sleep 
const int timer1Duration = 5;
const int timer2Duration = 10;

//Creates a timer that sleeps for a given amount of time based on -> timer1Duration
void timer1(){
    const int timerId = 1;
    std::cout<<"Timer "<<timerId<<" - Thread: "<<std::this_thread::get_id()<<" started\n";
    sleep(timer1Duration);
    std::cout<<"Timer "<<timerId<<" - Thread: "<<std::this_thread::get_id()<<" ended\n";
}


//Creates a timer that sleeps for a given amount of time based on -> timer2Duration
void timer2(){
    const int timerId = 2;
    std::cout<<"Timer "<<timerId<<" - Thread: "<<std::this_thread::get_id()<<" started\n";
    sleep(timer2Duration);
    std::cout<<"Timer "<<timerId<<" - Thread: "<<std::this_thread::get_id()<<" ended\n";
}

//Joins threads and displays output
void joinThreads(void){
    std::cout << "Main Thread: "<<std::this_thread::get_id()<<" started\n";
    std::thread thread1(timer1); // Create a new thread that runs the timer1 function
    std::thread thread2(timer2); // Create thread 2 that runs the timer2 function
    
    //Joining both threads inorder to wait for them to finish
    thread1.join();
    thread2.join();
    
    //Once both threads have finished executing main thread ends
    std::cout<< "Main thread: "<<std::this_thread::get_id()<<" ended\n";
}

void joinDetachThreads(void) {
	//Summary
    //This primer uses threads to run multiple timers at the same time. In the output of the code we see that the main thread starts first after which thread1 and thread2 begin excuting their assigned functions.
    //At the completion of each thread we are notified by a log in the console. Due to the sleep duration of timer1 being shorter we see that thread1 finsihes first followed by thread2, after which the main thread finally ends.
    //The join statements help us make sure that we wait until the execution of each thread is completed before moving onto the next line of code.
    
    joinThreads();
}