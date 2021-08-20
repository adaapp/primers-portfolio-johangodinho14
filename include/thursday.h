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

//Detaches threads and displays output
void detachThreads(void){
    std::cout<< "\nDetach Threads\n\n";
    
    std::cout << "Main Thread: "<<std::this_thread::get_id()<<" started\n";
    std::thread thread1(timer1); // Create a new thread that runs the timer1 function
    std::thread thread2(timer2); // Create thread 2 that runs the timer2 function
    
    //Detaching threads so that they can execute by themself / independently
    thread1.detach();
    thread2.detach();
    
    //Waiting for detached threads to finish execution
    sleep(timer1Duration + timer2Duration);
    
    std::cout<< "Main thread: "<<std::this_thread::get_id()<<" ended\n";
}

void joinDetachThreads(void) {
    //Summary - 8a
    //This primer uses threads to run multiple timers at the same time. In the output of the code we see that the main thread starts first after which thread 1 and thread thread2
    //run their respective timer functions and notify via a message once the timer finishes.
    //The join statements help us make sure that we wait until the execution of each thread is completed before moving onto the next line of code.
    
    joinThreads();
    detachThreads();
    //Summary - 8b
    //As an extension to primer 8a, I have added a detachThreads function that runs after the joinThreads function has finsihed executing. 
    //detachThreads creates two threads that are detached after creation instead of using 'join'. This means that the threads are allowed to run independently
    //hence the main thread will not wait for the completion of the threads, As a fix to this, I have added the sleep to wait for the 2 detached threads to complete. 
    //Once the 2 detached threads complete, the main thread also ends.
    //In primer 8-a, since we use thread.join(), we didn't need to use an additional sleep to wait for the threads to complete execution. On the other hand in primer 8-b we had to use an additional sleep statement to wait for both threads to finish execution.
}