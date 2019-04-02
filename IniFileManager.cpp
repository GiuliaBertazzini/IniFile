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
    auto it= file[section].find(parameter);
    if(it==file[section].end())
        file[section][parameter]=newValue;
    else
        modify(section,parameter,newValue);
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

void IniFileManager::printAll() {
    for(auto &it:file){
        if (it.first == "Comments")
            for(auto &secondIt: file["Comments"])
                std::cout << secondIt.second <<std::endl;
        else {
            std::cout<< "[" << it.first << "]" <<std::endl;
            for (auto &secondIt:file[it.first]){
                int numComment=0;
                bool commentFound=false;
                while(numComment<maxComment && !commentFound){
                    if(secondIt.first == to_string(numComment)){
                        commentFound=true;
                        std::cout<< secondIt.second << std::endl;
                    } else
                        numComment++;
                }
                if(!commentFound)
                    std::cout<< secondIt.first << "=" <<secondIt.second <<std::endl;
            }
        }
    }
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

void IniFileManager::checkIsOpen() {
    if(!newProject.is_open())
        std::cout<<""<<std::endl;

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
    std::cout<<"ATTENTION: parameter" <<parameter<< "has already a value; do you want to replace it? Press Y to continue" <<std::endl;
    string input;
    std::cin>> input;
    if(input=="Y")
        file[section][parameter]=newValue;
    else
        std::cout<<"Parameter is not been replaced"<<std::endl;
}

