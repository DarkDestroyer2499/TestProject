#include "FileSaver.h"

FileSaver::FileSaver(std::string dataFileName):
        mFileName(dataFileName), mData(0)
{
    std::ifstream mFin(mFileName);
    if(mFin.is_open())
    {
        mFin >> mData;
    }
    mFin.close();
}

void FileSaver::setData(unsigned long long *newData)
{
    mData = *newData;
    saveData();
}

unsigned long long FileSaver::getData()
{
    return mData;
}

void FileSaver::saveData()
{
    std::ofstream fout(mFileName);
    fout << mData;
    fout.close();
}

FileSaver::~FileSaver()
{
    saveData();
}
