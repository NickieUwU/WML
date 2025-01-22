#include "fileManager.h"
#include <cstdlib> // For system()
#include <thread>  // For std::thread
#include <chrono>

void resetHtml()
{
    if(filesystem::exists("./output.html")) filesystem::remove("./output.html");
}

bool checkForWml(string &fileName)
{
    return !filesystem::exists("../"+fileName+".wml") ?true:false;
}