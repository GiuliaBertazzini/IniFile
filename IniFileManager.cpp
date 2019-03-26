//
// Created by giuliaubuntumate on 13/03/19.
//

#include <iostream>
#include "IniFileManager.h"

IniFileManager::IniFileManager(string fileName, int maxComment) {
    this->fileName= fileName;
    this->newProject.open(fileName);
    this->maxComment=maxComment;
    currentComment=0;
}

IniFileManager::~IniFileManager(){
    this->newProject.close();
}

string IniFileManager::getFileName() {
    return fileName;
}

void IniFileManager::setFileName(string fileName) {
    this->fileName=fileName;
}

string IniFileManager::getValue(string section, string parameter) {
    return file[section][parameter];
}


void IniFileManager::setStringValue(string section, string parameter, string newValue) {
    file[section][parameter]=newValue;   //non sono sicura
}

void IniFileManager::setIntValue(string section, string parameter, int newValue) {
    string value= to_string(newValue);
    setStringValue(section,parameter,value);
}

void IniFileManager::setFloatValue(string section, string parameter, float newValue) {
    string value=to_string(newValue);
    setStringValue(section,parameter,value);
}

void IniFileManager::setBoolValue(string section, string parameter, bool newValue) {
    if(newValue)
        file[section][parameter]="true";
    else
        file[section][parameter]="false";
}

void IniFileManager::removeSection(string section) {
    auto it = file.find(section);
    if(it!=file.end())
        file.erase(section);
    else
        std::cout<<"Error: section not found";
}

void IniFileManager::addSection(string sectionName) {
    file[sectionName];
}

void IniFileManager::removeParameter(string section, string parameter) {
    auto it=file[section].find(parameter);
    if(it!=file[section].end())
        file[section].erase(parameter);
    else
        std::cout<<"Error: parameter not found";
}

void IniFileManager::addParameter(string section, string parameterName) {
    file[section][parameterName];
}

void IniFileManager::printSections() {
    std::cout<<"File Sections: "<<std::endl;
    for (auto &it: file)
        std::cout<<it.first <<std::endl;

}

void IniFileManager::printParameters(string section) {
    std::cout<<"Section Parameters: "<<std::endl;
    for(auto &it:file[section])
        std::cout<<it.first <<std::endl;

}

void IniFileManager::printValue(string section, string parameter) {
    std::cout<< parameter << "value: " <<file[section][parameter];
}

