#include <iostream>
#include "IniFileManager.h"
#include "Print.h"


int main (){
    IniFileManager file ("File.ini");
    std::cout<<"File Name: " << file.getFileName() << std::endl;

    Print p (&file);

    file.addSection("Prima Sezione");
    file.addSection("Seconda Sezione");
    file.addParameter("Prima sezione", "Parametro 1");
    file.addParameter("Prima Sezione", "Parametro 2");
    file.addParameter("Prima Sezione", "Parametro 3");
    file.addParameter("Seconda Sezione", "Parametro 1");

    file.setValue("Prima Sezione", "Parametro 1", 10);
    file.setValue("Prima Sezione", "Parametro 2", 9.8);
    file.setValue("Seconda Sezione", "Parametro 1", true);
    file.setStringValue("Prima Sezione", "Parametro 3", "valore");

    file.addSection("Terza Sezione");
    file.addParameter("Terza Sezione", "Parametro 1");
    file.addComment("Terza Sezione", "secondo commento", false);

    p.printSections();
    p.printParameters("Prima Sezione");
    p.printValue("Prima Sezione", "Parametro 1");
    p.printAll();

    int numberOfParameters = file.countParameters("Prima Sezione");
    std::cout<< "Numero parametri della prima sezione: " << numberOfParameters << std::endl;

    file.reset();

    file.end();
}
