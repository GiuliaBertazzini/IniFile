//
// Created by giulia on 10/09/20.
//

#include <iostream>
#include "Print.h"
#include "IniFileManager.h"

Print::Print(IniFileManager* ini) {
    this->ini=ini;
}

void Print::printSections() {
    std::cout<<"File Sections: "<<std::endl;
    for (auto &it: ini->getFile())
        std::cout<<it.first <<std::endl;

}

void Print::printParameters(string section) {
    std::cout<<"Section Parameters: "<<std::endl;
    map<string, map<string,string>> file = ini->getFile();
    for (auto &it: file[section])
        std::cout<< it.first<<std::endl;


}

void Print::printValue(string section, string parameter) {
    std::cout<< parameter << "value: " <<ini->getFile()[section][parameter]<<std::endl;
}

void Print::printAll() {
    map<string, map<string,string>> file = ini->getFile();
    for (auto &it:file) {
        if (it.first == "commenti")
            for (auto &secondIterator : file["commenti"])
                std::cout << secondIterator.second << std::endl;
        else {
            std::cout << "[" << it.first << "]" << std::endl;
            for (auto &secondIterator : file[it.first]) {
                int value = 0;
                bool commentFound = false;
                while (value < ini->getMaxComment() && !commentFound) {
                    if (secondIterator.first == to_string(value)) {
                        commentFound = true;
                        std::cout << secondIterator.second << std::endl;
                    } else
                        value++;
                }
                if (!commentFound)
                    std::cout << secondIterator.first << " = " << secondIterator.second << std::endl;

            }
        }
    }
}
