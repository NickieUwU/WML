#include "compiler.h"
#include "../components/components.h"

void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content)
{
    while(getline(WML_FILE, content))
    {
        string openingComponent = getOpeningComponent(content);
        openingComponentHandler(HTML_FILE, content, openingComponent);
    }
}

void openingComponentHandler(ofstream &HTML_FILE, string &content, string &component)
{
    if(content.find(component)!=string::npos&&!emptyComponent(component))
    {
        HTML_FILE << "<"+component.substr(0, component.size()-2);
    }
}

bool emptyComponent(string &component)
{
    return component.empty();
}