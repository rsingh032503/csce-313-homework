#include <iostream>
#include <cstring>
#include <unistd.h>

extern "C" int openr(const char *pathname);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const char *filename = argv[1];
    int fd = openr(filename);

    if (fd == -1) {
        perror("openr");
        return 1;
    }

    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    close(fd);

    return 0;
}
