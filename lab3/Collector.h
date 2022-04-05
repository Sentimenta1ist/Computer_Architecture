#ifndef LAB3_COLLECTOR_H
#define LAB3_COLLECTOR_H

#include "System.h"

class Collector {

public:
    Collector(const string&);
    void get_program();

private:
    bool error_indicator = false;
    vector<int> bytes;
    vector<Command> commands;
    void collect_commands();
    Command define_command(int byte);
};


#endif //LAB3_COLLECTOR_H
