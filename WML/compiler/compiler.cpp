#include "compiler.h"
#include "../components/components.h"

void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content)
{
    while(getline(WML_FILE, content))
    {
        string openingComponent = getOpeningComponent(content);
        if(emptyComponent(openingComponent)) continue;
        openingComponentHandler(HTML_FILE, openingComponent);
    }
}

void openingComponentHandler(ofstream &HTML_FILE, string &component)
{
    HTML_FILE << "<"<<component.substr(0, component.size()-2);
}

bool emptyComponent(string &component)
{
    return component.empty() ?true:false;
}