#ifndef FILE_SAVER_H_
#define FILE_SAVER_H_

#include"IFileSaver.h"
#include <fstream>

class FileSaver : IFileSaver
{
public:
    FileSaver(std::string);

    void setData(unsigned long long *) override;

    unsigned long long getData() override;

    void saveData() override;

    ~FileSaver();

private:
    std::string mFileName;
    unsigned long long mData;
};

#endif //FILE_SAVER_H_
