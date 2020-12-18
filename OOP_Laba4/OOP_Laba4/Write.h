#pragma once
#include <vector>
#include <map>
#include <string>
#include "Book.h"
#include "Formatting.h"

class Write {
public:
	void write(const std::vector<std::string>& arr_word, std::vector<Book>& arr_book);
	void write_new_vector(const std::vector<std::string>& arr_word, std::vector<std::vector<Book>>& arr_book);
	void write_new_map(const std::vector<std::string>& arr_word, std::map<std::string, std::vector<Book>>& arr_book);
private:
	void create_book(const std::vector<std::string>& arr_word, Book& book);
};
