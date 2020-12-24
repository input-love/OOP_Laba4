#include "SearchNameBook.h"

SearchNameBook::SearchNameBook(const std::string& value) : _value(value) {}

bool SearchNameBook::operator() (const Book& book) const
{
	return (book._book_name == _value);
}