#include "Parser.h"

void Parser::parser(std::vector<std::string>& arr, const std::string& line)
{
    std::istringstream stream_line(line);

    std::string word;
    while (stream_line >> word) 
    {
        arr.push_back(word);
    }
}