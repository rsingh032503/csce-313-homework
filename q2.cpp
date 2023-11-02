#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <chrono>

// function to call in order to measure performance
long long functionCall() {
    return static_cast<long long>(rand()) + static_cast<long long>(rand());
}

int main() {
    srand(time(NULL));
    const int numInvocations = 10000000;

    // Measure the time for function calls
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numInvocations; ++i) {
        functionCall(); // Sum of two random numbers
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> functionTime = end - start;

    // Measure the time for the getpid system call
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numInvocations; ++i) {
        getpid();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> getpidTime = end - start;

    // divide by the number of invocations to get the average times for function calls and system calls and display them
    std::cout << "Average time for function call: " << functionTime.count() / numInvocations << " seconds" << std::endl;
    std::cout << "Average time for getpid system call: " << getpidTime.count() / numInvocations << " seconds" << std::endl;

    return 0;
}

