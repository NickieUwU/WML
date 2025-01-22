#include "../headers/headers.h"
#include "compiler.h"
#include "../components/components.h"
#include "../attrs/attrs.h"

void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content)
{
    while(getline(WML_FILE, content))
    {
        string openingComponent = getOpeningComponent(content);
        string closingComponent = getClosingComponent(content);
        openingComponentHandler(HTML_FILE, content, openingComponent);
        closingComponentHandler(HTML_FILE, content, closingComponent);
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
            HTML_FILE << " "<<attr.substr(0, attr.size()-1)<<"=\"";
            size_t startingPos = content.find(attr);
            size_t endingPos = content.find(">>");
            HTML_FILE << "\"";
        }
        if(content.find(">>>")!=string::npos) HTML_FILE << ">";
        cout << content;
    }
}

void closingComponentHandler(ofstream &HTML_FILE, string &content, string &component)
{
    if(content.find(component)!=string::npos&&!emptyComponent(component))
    {
        HTML_FILE << "</"<<component.substr(2)<<">";
    }
}

bool emptyComponent(string &component)
{
    return component.empty();
}