#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Formatting.h"

class Write {
public:
	void write(const std::vector<std::string>& arr, Book& book);
};
