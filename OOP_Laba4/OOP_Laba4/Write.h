#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Formatting.h"

//template<class T>
class Write {
public:
	void write_to_vector(const std::vector<std::string>& arr_line, std::vector<Book>& arr_book);
	void write_to_vector(const std::vector<std::string>& arr_line, std::vector<std::vector<Book>>& arr_book);
};
