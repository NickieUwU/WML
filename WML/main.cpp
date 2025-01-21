#include "fileManager/fileManager.h"
#include "compiler/compiler.h"

int main()
{
    string content;
    string fileName="main";
    if(checkForWml(fileName))
    {
        cout << fileName<<" was not found\n";
        return 1;
    }
    resetHtml();
    ifstream WML_FILE("../"+fileName+".wml");
    ofstream HTML_FILE("./output/output.html");
    compile(WML_FILE, HTML_FILE, content);
    return 0;
}