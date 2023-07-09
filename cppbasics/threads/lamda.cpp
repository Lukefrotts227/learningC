#include <iostream>
#include <thread>
using namespace std; 

int main(void) {
    // Create a lambda function to be executed in a separate thread
    auto lambda = []() {
        // Code to be executed in the thread
        for (int i = 0; i < 5; ++i) {
            cout << "Thread ID: " << this_thread::get_id()
                      << ", Value: " << i << '\n';
        }
    };

    // Create a thread and pass the lambda function as a task
    thread thread1(lambda);

    // Start the thread execution
    thread1.join();

    return 0;
}
