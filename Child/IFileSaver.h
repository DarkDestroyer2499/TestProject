#ifndef IFILE_SAVER_H_
#define IFILE_SAVER_H_

class IFileSaver
{
public:
    virtual void setData(unsigned long long *) = 0;
    virtual unsigned long long getData() = 0;
    virtual void saveData() = 0;
    virtual ~IFileSaver() {}
};

#endif //IFILE_SAVER_H_
