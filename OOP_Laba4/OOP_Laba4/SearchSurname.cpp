#include "SearchSurname.h"

SearchSurname::SearchSurname(const std::string& value): _value(value) {}

bool SearchSurname::operator() (const std::vector<Book>& arr_book) const
{
	return (arr_book.at(0)._last_name == _value);
}