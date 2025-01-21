#include "../headers/headers.h"
#include "compiler.h"
#include "../components/components.h"
#include "../attrs/attrs.h"

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
        string attr = getAttr(content);
        if(!attr.empty())
        {
            HTML_FILE << " "<<attr.substr(0, attr.size()-1)<<"=\"\"";
        }
        if(content.find(">>>")!=string::npos) HTML_FILE << ">";
        cout << content;
    }
}

bool emptyComponent(string &component)
{
    return component.empty();
}