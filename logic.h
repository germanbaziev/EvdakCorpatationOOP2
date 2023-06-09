#ifndef LOGIC_H
#define LOGIC_H
#include "iostream"
#include "fstream"
using namespace std;

class WorkWithFile
{
public:
    WorkWithFile(string fp):filePath(fp){};
    string filePath;
    std::string getTextFile()
    {
        fstream file;
        string tmp;
        string tmp1;
        file.open(filePath);
        while(getline(file, tmp))
        {
            tmp1 += tmp + "\n";
        }
        return tmp1;
    }

};



#endif // LOGIC_H
