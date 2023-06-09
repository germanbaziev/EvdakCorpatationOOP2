#ifndef LOGIC_H
#define LOGIC_H
#include "iostream"
#include "fstream"
#include "stack"
using namespace std;

typedef struct error
{
    string errorType;
    int cols;
    int rows;
    bool containError = false;

}AllInformationsAboutError;

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

class JsonChecker
{
public:
    JsonChecker(string ft):fileText(ft){}

    AllInformationsAboutError fullChecker()
    {
        AllInformationsAboutError result;
        result = balanced();
        return result;
    }

private:
    string fileText;

    AllInformationsAboutError balanced() {
        std::stack<char> stack;
        AllInformationsAboutError error;
        error.errorType = "parenthesis error";
        for (char c : fileText) {
            if(c == '\n')
            {
                error.cols = 0;
                error.rows++;
            }
            switch (c) {

            case '(': stack.push(')'); break;
            case '[': stack.push(']'); break;
            case '{': stack.push('}'); break;
            case '<': stack.push('>'); break;

            case ')':
            case ']':
            case '}':
            case '>':
                if (stack.empty() || stack.top() != c) {
                    error.containError = 1;
                    return error;
                }
                stack.pop();
                break;
            default:
                break;
            }
            error.cols++;
        }
        if(!stack.empty())
            error.containError = 1;
        return error;
    }
};



#endif // LOGIC_H
