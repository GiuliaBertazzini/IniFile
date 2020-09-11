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

map<string, map<string, string>> IniFileManager::getFile(){
    return file;
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
    auto it = file[section].find(parameter);
    if(it==file[section].end())
        file[section][parameter]=newValue;
    else
        modify(section,parameter,newValue);
}

void IniFileManager::setValue(string section, string parameter, int newValue) {
    string value = to_string(newValue);
    setStringValue(section,parameter,value);
}

void IniFileManager::setValue(string section, string parameter, double newValue) {
    string value=to_string(newValue);
    setStringValue(section,parameter,value);
}

void IniFileManager::setValue(string section, string parameter, bool newValue) {
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
        throw std::runtime_error("Section doesn't exist");
}

void IniFileManager::addSection(string sectionName) {
    file[sectionName];
}

void IniFileManager::removeParameter(string section, string parameter) {
    auto it=file[section].find(parameter);
    if(it!=file[section].end())
        file[section].erase(parameter);
    else
        throw std::runtime_error("Parameter doesn't exist");
}

void IniFileManager::addParameter(string section, string parameterName) {
    file[section][parameterName];
}




void IniFileManager::addComment(string section, string commentText, bool inSection) {
    string parameter;
    currentComment += 1;
    parameter= to_string(currentComment);
    if(inSection)
        file[section][parameter]= ";" + commentText;
    else
        file["Comments"][parameter]= ";" + commentText;
}

bool IniFileManager::findSection(string section) {
    bool found=false;
    auto it =file.find(section);
    if (it!=file.end())
        found=true;
    return found;
}

bool IniFileManager::findParameter(string section, string parameter) {
    bool found=false;
    auto it = file[section].find(parameter);
    if(it!=file[section].end())
        found=true;
    return found;

}

void IniFileManager::checkIsOpen() throw (std::runtime_error) {
    if(!newProject.is_open())
        throw std::runtime_error("file doesn't exist");

}

void IniFileManager::end() {
    this->newProject.close();
}

void IniFileManager::reset() {
    std::cout<<"Do you really want to delete everything? [Y/N]"<<std::endl;
    string input;
    std::cin >> input;
    if(input=="Y")
        file.clear();
}

int IniFileManager::countParameters(string section) {
    int count=0;
    for(auto &it:file[section])
        count++;
    return count;
}

void IniFileManager::modify(string section, string parameter, string newValue) {
    std::cout<<"ATTENTION: parameter " <<parameter<< " has already a value. Do you want to replace it? Press s if you want" <<std::endl;
    string input;
    std::cin>> input;
    if(input=="s")
        file[section][parameter] = newValue;
    else
        std::cout<<"Parameter is not been replaced"<<std::endl;
}

void IniFileManager::putToNull(string section, string parameter){
    file[section][parameter] = "null";
}

int IniFileManager::getMaxComment(){
    return maxComment;
}