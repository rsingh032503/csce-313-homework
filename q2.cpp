#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>

// function to call in order measure performance
long long functionCall() {
    return static_cast<long long>(rand()) + static_cast<long long>(rand());
}

int main() {
    srand(time(NULL));
    const int numInvocations = 1000000;
    struct timespec start, end;

    // Measure the time for function calls
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < numInvocations; ++i) {
        functionCall(); // Sum of two random numbers
    }
    clock_gettime(CLOCK_REALTIME, &end); 
    // convert the nanoseconds from the end time stamp of tv_nsec to seconds and add them to the seconds from tv_sec
    // this will give the complete time in seconds
    double functionTime = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec) / 1e9); 


    // Measure the time for the getpid system call
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < numInvocations; ++i) {
        getpid();
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double getpidTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // divide by the number of invocations to get the average times for function calls and system calls and display them
    std::cout << "Average time for function call: " << functionTime / numInvocations << " seconds" << std::endl;
    std::cout << "Average time for getpid system call: " << getpidTime / numInvocations << " seconds" << std::endl;

    return 0;
}
