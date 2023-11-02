#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>

int your_function(int a, int b) {
    return a + b;
}

int main() {
    const int numInvocations = 1000000;
    struct timespec start, end;
    int result;

    // Measure the time for function calls
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < numInvocations; ++i) {
        result = your_function(rand(), rand()); // Sum of two random numbers
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double functionTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    result = 0;

    // Measure the time for the getpid system call
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < numInvocations; ++i) {
        getpid(); // getpid is a simple system call
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double getpidTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    std::cout << "Average time for function call: " << functionTime / numInvocations << " seconds" << std::endl;
    std::cout << "Average time for getpid system call: " << getpidTime / numInvocations << " seconds" << std::endl;

    return 0;
}
