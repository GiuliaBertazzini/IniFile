#include <iostream>
#include "IniFileManager.h"


int main (){
    IniFileManager file ("FirstProgram.ini");
    std::cout<<"File Name: " << file.getFileName() << std::endl;

    file.addSection("Prima Sezione");
    file.addSection("Seconda Sezione");
    file.addParameter("Prima sezione", "Parametro 1");
    file.addParameter("Prima Sezione", "Parametro 2");
    file.addParameter("Seconda Sezione", "Parametro 1");

    file.setIntValue("Prima Sezione", "Parametro 1", 10);
    file.setFloatValue("Prima Sezione", "Parametro 2", 9.81);
    file.setBoolValue("Seconda Sezione", "Parametro 1", true);
    file.setStringValue("Prima Sezione", "Parametro 3", "valore");

    file.checkIsOpen();

    file.addSection("Terza Sezione");
    file.addParameter("Terza", "Parametro 1");
    file.removeParameter("Prima Sezione","Parametro 2");
    file.removeSection("Quarta Sezione");
    file.addComment("primo commento", "secondo commento", false);


    file.printAll();

    int numberOfParameters = file.countParameters("Prima Sezione");
    std::cout<< "Numero parametri della prima sezione: " << numberOfParameters << std::endl;

    file.reset();

    file.end();
}
