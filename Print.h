//
// Created by giulia on 10/09/20.
//

#ifndef LABORATORIOPROGRAMMAZIONE_PRINT_H
#define LABORATORIOPROGRAMMAZIONE_PRINT_H

#include "IniFileManager.h"

class Print {

public:

    explicit Print(IniFileManager *ini);

    void printSections();

    void printParameters(string section);

    void printValue(string section, string parameter);

    void printAll();

private:
    IniFileManager* ini;
};



#endif //LABORATORIOPROGRAMMAZIONE_PRINT_H
