#include "fileManager.h"

void resetHtml()
{
    if(filesystem::exists("./output/output.html")) filesystem::remove("./output/output.html");
}

bool checkForWml(string &fileName)
{
    return !filesystem::exists("../"+fileName+".wml") ?true:false;
}