#include "Search.h"

Fo_name::Fo_name(const std::string& value): _value(value) {}

bool Fo_name::operator() (std::vector<Book>& arr_book) const 
{
	std::vector<Book>::iterator it = arr_book.begin();

	it = std::find_if(arr_book.begin(), arr_book.end(), Fo_name(_value));

	return (it != arr_book.end());
}

bool Fo_name::operator() (const Book& book) const
{
	return (book._last_name == _value);
}