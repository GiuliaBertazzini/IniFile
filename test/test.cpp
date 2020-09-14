//
// Created by giulia on 08/09/20.
//

#include "/home/giulia/CLionProjects/IniFile/IniFileManager.cpp"
#include "/home/giulia/CLionProjects/IniFile/IniFileManager.h"
#include "/home/giulia/CLionProjects/IniFile/test/lib/googletest/include/gtest/gtest.h"

//constructor tester
TEST(iniFileManagerTest, ConstructorTest){
IniFileManager constructorTester("iniFile.ini");
ASSERT_EQ(constructorTester.getFileName(), "iniFile.ini");
}

//getters, setters tests
TEST(iniFileManagerTest, StringGetterSetterTest) {
IniFileManager file("Prova.ini");
file.setStringValue("Sezione 1", "Parametro 1", "valore 1");
ASSERT_EQ(file.getValue("Sezione 1", "Parametro 1"), "valore 1");
}

TEST(iniFileManagerTest, IntGetterSetterTest) {
IniFileManager file("Prova.ini");
file.setValue("Sezione 1", "Parametro 2", 5);
ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(iniFileManagerTest, FloatGetterSetterTest) {
IniFileManager file("Prova.ini");
file.setValue("Sezione 2", "Parametro 1", 5.98);
ASSERT_TRUE(abs(stof(file.getValue("Sezione 2", "Parametro 1")) - 5.98) < 0.0001);
}


TEST(iniFileManagerTest, BoolGetterSetterTest) {
IniFileManager file("Prova.ini");
file.setValue("Sezione 3", "Parametro 1", false);
ASSERT_EQ(file.getValue("Sezione 3", "Parametro 1"), "false");
}

TEST(iniFileManagerTest, PutToNullTest) {
IniFileManager file("Prova.ini");
file.putToNull("Sezione 4", "Parametro 6");
ASSERT_EQ(file.getValue("Sezione 4", "Parametro 6"), "null");
}

TEST(iniFileManagerTest, NumParametersTest) {
IniFileManager file("Prova.ini");
file.setStringValue("Sezione 4", "Parametro 6", "Valore stringa");
file.setValue("Sezione 4", "Parametro 8", 3);
ASSERT_EQ(file.countParameters("Sezione 4"), 2);
}

TEST(iniFileManagerTest, addCommentTest) {
IniFileManager file("Prova.ini");
file.addSection("Sezione 1");
file.addComment("Sezione 1", "commento nella sezione", true);
file.addComment("nessuna sezione", "commento fuori sezione", false);
ASSERT_EQ(file.getValue("Sezione 1", "1"), ";commento nella sezione");
}

TEST(iniFileManagerTest, SectionsTest) {
IniFileManager file("Prova.ini");
file.addSection("Sezione prova rimozione");
file.removeSection("Sezione prova rimozione");
ASSERT_EQ(file.findSection("Seconda prova rimozione"), false);
}

TEST(iniFileManagerTest, ParameterTest) {
IniFileManager file("Prova.ini");
file.addParameter("Sezione", "Parametro");
file.removeParameter("Sezione", "Parametro");
ASSERT_EQ(file.findParameter("Sezione", "Parametro"), false);
}

TEST(iniFileManagerException, ParameterTestFail) {
IniFileManager file("Prova.ini");
file.addParameter("Sezione", "Parametro");
EXPECT_THROW(file.removeParameter("Sezione", "Parametro 2"), std::runtime_error);
}

TEST(iniFileManagerException, SectionsTestFail) {
IniFileManager file("Prova.ini");
file.addSection("Sezione prova rimozione");
EXPECT_THROW(file.removeSection("Sezione prova rimozione 2"), std::runtime_error);
}

TEST(iniFileManagerException, IsOpenTest) {
IniFileManager file("Prova.ini");
file.end();
EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}

TEST(iniFileManagerException, LoadTest) {
    IniFileManager file("Prova.ini");
    file.load("../IniFileManager.cpp");
    EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}

TEST(iniFileManagerException, SaveTest) {
    IniFileManager file("Prova.ini");
    file.save("../IniFileManager.cpp");
    EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}