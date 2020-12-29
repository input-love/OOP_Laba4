#include "Write.h"

void Write::write(const std::vector<std::string>& arr, Book* book)
{
	book->_name = arr[0];
	book->_last_name = arr[1];

	std::string full_book_name = arr[2];
	for (int j = 3; j < arr.size() - 2; ++j) {
		full_book_name += (" " + arr[j]);
	}
	book->_book_name = full_book_name;

	book->_the_year_of_publishing = Formatting().formatting(arr[arr.size() - 2]);
	book->_count = Formatting().formatting(arr[arr.size() - 1]);
}