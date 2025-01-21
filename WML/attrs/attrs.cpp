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