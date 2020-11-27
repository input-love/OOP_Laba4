#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Book.h"


class Parser {
public:
	static void parser(std::vector<std::string>& list_words, std::string& line);
};