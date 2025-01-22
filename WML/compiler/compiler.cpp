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
        handleContent(HTML_FILE, content, openingComponent, closingComponent);
        closingComponentHandler(HTML_FILE, content, closingComponent);
    }
}

void openingComponentHandler(ofstream &HTML_FILE, string &content, string &component)
{
    if(content.find(component)!=string::npos&&!emptyComponent(component))
    {
        HTML_FILE << "<"+component.substr(0, component.size()-2);
        while (true)
        {
            string attr = getAttr(content);
            if (attr.empty())
                break;

            string attrContent = handleAttr(content, attr);
            if (!attrContent.empty())
            {
                HTML_FILE << " " << attr.substr(0, attr.size() - 1) << "=\"";
                HTML_FILE << attrContent.substr(attr.size());
                HTML_FILE << "\"";
            }

            size_t attrPos = content.find(attr);
            size_t endPos = content.find(">>", attrPos);
            if (attrPos != string::npos && endPos != string::npos)
                content = content.substr(endPos + 2);
            else
                break;
        }   
        HTML_FILE << ">";
    }
}

void handleContent(ofstream &HTML_FILE, string &content, string &openingComponent, string &closingComponent)
{
    size_t contentStart = content.find("'");
    size_t contentEnd = content.find("'", contentStart + 1);

    if (contentStart != string::npos && contentEnd != string::npos)
    {
        string extractedContent = content.substr(contentStart + 1, contentEnd - contentStart - 1);
        
        size_t pos = 0;
        while ((pos = extractedContent.find("\\n", pos)) != string::npos) {
            extractedContent.replace(pos, 2, "<br>");
            pos += 4;
        }

        // Print the modified content to the HTML file
        HTML_FILE << extractedContent;
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