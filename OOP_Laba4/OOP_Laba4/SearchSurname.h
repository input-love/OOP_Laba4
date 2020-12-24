#pragma once
#include <string>
#include <vector>
#include "Book.h"

struct SearchSurname { 
	SearchSurname(const std::string& value);
	bool operator() (const std::vector<Book>& book) const;
private:
	std::string _value;
};