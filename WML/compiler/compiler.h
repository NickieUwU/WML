#include "../headers/headers.h"
#ifndef COMPILER_H
#define COMPILER_H
    void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content);
    void openingComponentHandler(ofstream &HTML_FILE, string &component);
    bool emptyComponent(string &component);
#endif