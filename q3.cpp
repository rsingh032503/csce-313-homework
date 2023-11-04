#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    // Open an existing test file for reading
    int fd = open("q3test.txt", O_RDONLY);  
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("Failed to create pipe");
        return 1;
    }

    // Fork 
    pid_t pid = fork();  
    if (pid < 0) {
        perror("Failed to fork");
        return 1;
    }

    if (pid > 0) {  // In parent process
        close(fd);  // Close the file descriptor
        unlink("q3test.txt");  // Delete the file
        printf("File deleted in parent process. Check with 'ls'.\n\n");

        close(pipefd[0]);  // Close unused read end
        write(pipefd[1], "go", 2);  // Send synchronization message to child
        close(pipefd[1]);  // Close write end of pipe

        wait(NULL);  // Wait for child to finish
    } else {  // In child process
        char buf[3];
        close(pipefd[1]);  // Close unused write end
        read(pipefd[0], buf, 2);  // Read synchronization message from parent
        close(pipefd[0]);  // Close read end of pipe

        char filebuf[1024];
        ssize_t n = read(fd, filebuf, sizeof(filebuf) - 1);  // Read from the file
        if (n >= 0) {
            filebuf[n] = '\0';
            printf("Child read from file:\n %s\n", filebuf);
        } else {
            perror("Failed to read from file in child");
        }

        close(fd);  // Close the file descriptor
    }

    return 0;
}
