#include "../headers/headers.h"
#include "attrs.h"

string getAttr(string &content)
{
    vector<string> attrs = {
        "class:",
        "id:",
        "name:",
        "style:",
        "type:",
        "method:",
        "action:"
    };

    for(const string &attr: attrs)
    {
        if(content.find(attr)!=string::npos) return attr;
    }
    return "";
}

string handleAttr(string &content, string &attr)
{
    size_t contentStart = content.find(attr);
    size_t contentEnd = content.find(">>", contentStart);
    if(contentStart!=string::npos && contentEnd!=string::npos)
    {
        return content.substr(contentStart, contentEnd-contentStart);
    }
    return "";
}