#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

int main() {
    std::string path;
    std::cout << "Enter a file path: ";
    std::cin >> path;

    struct stat path_stat;
    lstat(path.c_str(), &path_stat);

    std::cout << "\n\n";

    // Check if it's a regular file, pipe or symlink
    if (S_ISREG(path_stat.st_mode))
        std::cout << "This is a regular file.\n";
    else if (S_ISFIFO(path_stat.st_mode))
        std::cout << "This is a pipe.\n";
    else if (S_ISLNK(path_stat.st_mode))
        std::cout << "This is a symlink.\n";
    else
        std::cout << "This is neither a regular file, pipe, nor symlink.\n";

    // Display the permissions of the owner of the file
    std::cout << "Owner permissions: ";
    std::cout << ((path_stat.st_mode & S_IRUSR) ? "r" : "-");
    std::cout << ((path_stat.st_mode & S_IWUSR) ? "w" : "-");
    std::cout << ((path_stat.st_mode & S_IXUSR) ? "x" : "-");
    std::cout << "\n";

    return 0;
}