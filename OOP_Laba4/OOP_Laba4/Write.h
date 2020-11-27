#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Formatting.h"

class Write {
public:
	static void write_to_vector(const std::vector<std::vector<std::string>>& arr, std::vector<Book>& arr_book);
};
