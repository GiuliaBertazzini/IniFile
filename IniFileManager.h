//
// Created by giuliaubuntumate on 13/03/19.
//

#ifndef LABORATORIOPROGRAMMAZIONE_INIFILEMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_INIFILEMANAGER_H

#include <string>
#include <fstream>
#include <map>

using namespace std;

class IniFileManager {
public:
    IniFileManager(string fileName, int maxComment=100);

    ~IniFileManager();

    void setFileName (string fileName);

    string getFileName();

    string getValue(string section, string parameter);

    void setStringValue(string section, string parameter, string newValue);

    void setIntValue(string section, string parameter, int newValue);

    void setFloatValue(string section, string parameter, float newValue);

    void setBoolValue (string section, string parameter, bool newValue);

    void removeSection(string section);

    void removeParameter(string section, string parameter);

    void addSection(string sectionName);

    void addParameter(string section, string parameterName);

    bool findSection(string section);

    bool findParameter(string section, string parameter);

    void printSections();

    void checkIsOpen() throw(std::runtime_error);

    void end();

    void printParameters(string section);

    void printValue(string section, string parameter);

    void printAll();

    void addComment(string section, string commentText, bool inSection);

    void reset();

    int countParameters(string section);

    void modify(string section, string parameter, string newValue);

private:
    string fileName;
    map<string, map<string,string>> file;
    int currentComment;
    int maxComment;
    fstream newProject;
};


#endif //LABORATORIOPROGRAMMAZIONE_INIFILEMANAGER_H
