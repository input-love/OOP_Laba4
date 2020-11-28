#include "Book.h"

bool Book::operator< (const Book& book) const {
	return _the_year_of_publishing < book._the_year_of_publishing;
}