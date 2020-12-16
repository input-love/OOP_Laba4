#pragma once
#include <string>
#include <vector>
#include "Book.h"

struct Fo_name { 
	Fo_name(const std::string& value);
	bool operator() (std::vector<Book>& book) const;
	bool operator() (const Book& book) const;
private:
	std::string _value;
};