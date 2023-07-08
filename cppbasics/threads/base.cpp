#include <iostream>
#include <thread>

int main() {
    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads > 1) {
        std::cout << "Multiple threads are supported. Number of threads available: " << numThreads << std::endl;
    } else {
        std::cout << "Multiple threads are not supported or the value is unknown." << std::endl;
    }

    return 0;
}