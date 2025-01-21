#include "components/components.h"
#include "fileManager/fileManager.h"

int main()
{
    resetHtml();
    string content;
    string fileName="main";
    ifstream WML_FILE("../"+fileName+".wml");
    ofstream HTML_FILE("./output/output.html");
    return 0;
}