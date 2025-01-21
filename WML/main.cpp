#include "components/components.h"

int main()
{
    string content;
    string fileName="main";
    ifstream WML_FILE("../"+fileName+".wml");
    ofstream HTML_FILE("./output/output.html");
    return 0;
}