#include "fileManager.h"

void resetHtml()
{
    if(filesystem::exists("./output/output.html")) filesystem::remove("./output/output.html");
}