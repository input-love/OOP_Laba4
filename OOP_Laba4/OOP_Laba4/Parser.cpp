#include "Parser.h"

void Parser::parser(std::vector<std::string>& list_words, std::string& line) {
    std::istringstream stream_line(line);

    std::string word;
    while (stream_line >> word) {
        list_words.push_back(word);
    }
}