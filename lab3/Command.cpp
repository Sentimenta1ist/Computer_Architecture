#include "Command.h"

Command::Command(string name, string bytes, vector<string> operands) {
    this->name = name;
    this->bytes = bytes;
    this->operands = operands;
}

void Command::print_command() {
    if(!error_command.empty()){
        cout << error_command;
        return;
    }
    cout << bytes << endl;

    if(!error.empty()){
        cout << error << endl;
    }

    cout << name << ' ';

    for(auto it = operands.begin(); it != operands.end(); ++it){
        if(std::next(it) == operands.end()){
            cout << *it;
        }
        else{
            cout << *it << ", ";
        }
    }
    cout << endl << endl;
}

Command::Command(string error) {
    this->error_command = error;
}

void Command::setError(string error) {
    this->error = error;
}
