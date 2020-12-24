#pragma once
#include <string>
#include "Book.h"

struct SearchNameBook {
	SearchNameBook(const std::string& value);
	bool operator() (const Book& book) const;
private:
	std::string _value;
};