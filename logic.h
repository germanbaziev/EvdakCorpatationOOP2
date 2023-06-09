#ifndef LOGIC_H
#define LOGIC_H
#include "iostream"
#include "fstream"
#include "stack"
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

class JsonChecker
{
public:
    JsonChecker(string ft):fileText(ft){}

    bool fullChecker()
    {
        int result = true;
        result = balanced(fileText);
        return result;
    }

private:
    string fileText;

    bool balanced(const std::string &s) {
        std::stack<char> stack;
        for (char c : s) {
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
                    return false;
                }
                stack.pop();
                break;
            default:
                break;
            }
        }
        return stack.empty();
    }
};



#endif // LOGIC_H
