#include "../headers/headers.h"
#ifndef COMPILER_H
#define COMPILER_H
    void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content);
    void openingComponentHandler(ofstream &HTML_FILE, string &content, string &component);
    void handleContent(ofstream &HTML_FILE, string &content, string &openingComponent, string &closingComponent);
    void closingComponentHandler(ofstream &HTML_FILE, string &content, string &component);
    bool emptyComponent(string &component);
#endif