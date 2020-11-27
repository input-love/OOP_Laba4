#pragma once
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Book.h"
#include "Parser.h"

class ScanFile {
public:
	static void scan(std::vector<std::vector<std::string>>& arr);
};