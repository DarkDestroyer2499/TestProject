#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>

const char *CHILD_PATH = "../../Child/build/child";

pid_t createChild(const char* programName, char** arg_list)
{
    pid_t ch_pid = fork();

    if (ch_pid == -1) {
        
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (ch_pid > 0) {
        std::cout << "Child procces has been created with ID: " << ch_pid << std::endl;
        return ch_pid;
    } 
    else {
        execve(programName, arg_list, nullptr);
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    pid_t child_pid;

    child_pid = createChild(CHILD_PATH, argv);
    
    while (true)
    {
        if ((child_pid = wait(nullptr)) == -1)
        {
            std::cout << "Child has been terminated!" << std::endl;
            child_pid = createChild(CHILD_PATH, argv);
        }
    }

    return 0;
}
