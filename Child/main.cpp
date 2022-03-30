#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include "FileSaver.h"
#include <memory>



std::unique_ptr<FileSaver>  fileSaver(new FileSaver("ChildData.txt"));



volatile sig_atomic_t flag = true;

void terminationHandler(int s)
{
    flag = false;
    fileSaver->saveData();
}

unsigned long getTimePeriod(const char *argument)
{
    unsigned long tmp;
    try
    {
        tmp = std::stoi(argument);
    }
    catch(const std::exception& e)
    {
        tmp = 1000;
        std::cerr << e.what() << '\n';
    }
    
    return tmp;
}

int main(int argc, char *argv[])
{

    std::cout << "----- This is CHILD hello message! -----" << std::endl;

    signal(SIGTERM, terminationHandler);
    signal(SIGINT, terminationHandler);

    unsigned long delay;

    if (argv[1] == nullptr) 
    {
        delay = 1000000;
    }
    else
    {
        delay = getTimePeriod(argv[1]) * 1000ul; // getting period in ms
    }

    unsigned long long counter = fileSaver->getData();

    while(flag)
    {
        ++counter;
        fileSaver->setData(&counter);
        std::cout << "Counter: " << counter << std::endl;
        usleep(delay);
    }

    return 0;
}
