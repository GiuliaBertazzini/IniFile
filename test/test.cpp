//
// Created by giulia on 08/09/20.
//

#include "/home/giulia/CLionProjects/IniFile/IniFileManager.cpp"
#include "/home/giulia/CLionProjects/IniFile/IniFileManager.h"
#include "/home/giulia/CLionProjects/IniFile/test/lib/googletest-master/googletest/include/gtest/gtest.h"

//constructor tester
TEST(iniFileManagerTest, ConstructorTest) {
iniFileManager constructorTester("iniFile.ini");
ASSERT_EQ(constructorTester.getFileName(), "iniFile.ini");
}

//getters, setters tests
TEST(iniFileManagerTest, StringGetterSetterTest) {
iniFileManager file("Prova.ini");
file.setStringValue("Sezione 1", "Parametro 1", "valore 1");
ASSERT_EQ(file.getValue("Sezione 1", "Parametro 1"), "valore 1");
}

TEST(iniFileManagerTest, IntGetterSetterTest) {
iniFileManager file("Prova.ini");
file.setIntValue("Sezione 1", "Parametro 2", 5);
ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(iniFileManagerTest, FloatGetterSetterTest) {
iniFileManager file("Prova.ini");
file.setFloatValue("Sezione 2", "Parametro 1", 5.98);
ASSERT_TRUE(abs(stof(file.getValue("Sezione 2", "Parametro 1")) - 5.98) < 0.0001);
}


TEST(iniFileManagerTest, BoolGetterSetterTest) {
iniFileManager file("Prova.ini");
file.setBoolValue("Sezione 3", "Parametro 1", false);
ASSERT_EQ(file.getValue("Sezione 3", "Parametro 1"), "false");
}

TEST(iniFileManagerTest, PutToNullTest) {
iniFileManager file("Prova.ini");
file.putToNull("Sezione 4", "Parametro 6");
ASSERT_EQ(file.getValue("Sezione 4", "Parametro 6"), "null");
}

TEST(iniFileManagerTest, NumParametersTest) {
iniFileManager file("Prova.ini");
file.setStringValue("Sezione 4", "Parametro 6", "Valore stringa");
file.setIntValue("Sezione 4", "Parametro 8", 5);
ASSERT_EQ(file.numParameters("Sezione 4"), 2);
}

TEST(iniFileManagerTest, addCommentTest) {
iniFileManager file("Prova.ini");
file.addSection("Sezione 1");
file.addComment("Sezione 1", "commento nella sezione", true);
file.addComment("nessuna sezione", "commento fuori sezione", false);
ASSERT_EQ(file.getValue("Sezione 1", "1"), "; commento nella sezione");
}

TEST(iniFileManagerTest, SectionsTest) {
iniFileManager file("Prova.ini");
file.addSection("Sezione prova rimozione");
file.removeSection("Sezione prova rimozione");
ASSERT_EQ(file.findSection("Seconda prova rimozione"), false);
}

TEST(iniFileManagerTest, ParameterTest) {
iniFileManager file("Prova.ini");
file.addParameter("Sezione", "Parametro");
file.removeParameter("Sezione", "Parametro");
ASSERT_EQ(file.findParameter("Sezione", "Parametro"), false);
}

TEST(iniFileManagerException, ParameterTestFail) {
iniFileManager file("Prova.ini");
file.addParameter("Sezione", "Parametro");
EXPECT_THROW(file.removeParameter("Sezione", "Parametro 2"), std::runtime_error);
}

TEST(iniFileManagerException, SectionsTestFail) {
iniFileManager file("Prova.ini");
file.addSection("Sezione prova rimozione");
EXPECT_THROW(file.removeSection("Sezione prova rimozione 2"), std::runtime_error);
}


TEST(iniFileManagerException, IsOpenTest) {
iniFileManager file("Prova.ini");
file.end();
EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}