#include "compiler.h"
#include "../components/components.h"
void compile(ifstream &WML_FILE, ofstream &HTML_FILE, string &content)
{
    while(getline(WML_FILE, content))
    {
        string openingComponent = getOpeningComponent(content);
    }
}

void openingComponentHandler(ofstream &HTML_FILE, string &openingComponent)
{
    
}