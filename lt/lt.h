#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class EnterExit{
    public:
        EnterExit(string functionName):_functionName(functionName){cout << "Enter " << _functionName << endl;}
        ~EnterExit(){cout << "Exit " << _functionName << endl;}
    private:
        string _functionName;
};

#define ENTER() EnterExit _enter(__FUNCTION__);

void ltMain();