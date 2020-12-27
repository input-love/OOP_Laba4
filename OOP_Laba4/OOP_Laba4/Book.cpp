#include "Book.h"

Book::Book(const std::string& name, const std::string& surname, const std::string& book_name, int date, int count):
	_name(name),
	_last_name(surname),
	_book_name(book_name),
	_the_year_of_publishing(date),
	_count(count)
{}

Book::Book(const Book& book)
{
	_name = book._name;
	_last_name = book._last_name;
	_book_name = book._name;
	_the_year_of_publishing = book._the_year_of_publishing;
	_count = book._count;
}