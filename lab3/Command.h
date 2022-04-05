#ifndef LAB3_COMMAND_H
#define LAB3_COMMAND_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Command {

    string name;
    string bytes;
    string error_command;
    string error;
    vector<string> operands;
public:
    Command(string name, string bytes, vector<string> operands);
    Command(string name, string bytes, vector<string> operands, string error);
    Command(string error);
    void setError(string error);
    void print_command();
};


#endif
