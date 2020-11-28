#include "Search.h"

Fo_name::Fo_name(const std::string& value): _value(value) {}

bool Fo_name::operator () (const Book& book) const {
	return (book._name == _value);
}