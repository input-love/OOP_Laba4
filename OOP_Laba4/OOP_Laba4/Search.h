#pragma once
#include <string>
#include "Book.h"

struct Fo_name { 
	Fo_name(const std::string& value);
	bool operator() (const Book& book) const;
	std::string _value;
};