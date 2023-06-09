#include "logic.h"

AllInformationsAboutError JsonChecker::fullChecker()
{
    AllInformationsAboutError result;
    result = ParenthesisError();
    return result;
}

AllInformationsAboutError JsonChecker::ParenthesisError() {
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

string WorkWithFile::getTextFile()
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
