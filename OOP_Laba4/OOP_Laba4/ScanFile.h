#pragma once
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Book.h"
#include "Parser.h"
#include "Write.h"
#include "Search.h"

class ScanFile {
public:
	void scan(std::vector<std::vector<Book>>& arr_book);
};