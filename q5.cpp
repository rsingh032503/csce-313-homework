#include <iostream>
#include <fcntl.h>
#include <cerrno>
#include <cstring>

int main() {
    int max_open_files = 0;
    while(true) {
        int fd = open("q5test.txt", O_CREAT | O_RDONLY, 0666);
        if (fd == -1) {
            if (errno == EMFILE) {
                printf("Maximum number of open files reached: %d\n", max_open_files);
                break;
            } else {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
        }
        max_open_files++;
    }
}

