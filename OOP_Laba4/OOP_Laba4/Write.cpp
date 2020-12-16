#include "Write.h"

//template<class T>
void Write::write_to_vector(const std::vector<std::string>& arr_line, std::vector<Book>& arr_book) {
	Book book;

	book._name = arr_line[0];
	book._last_name = arr_line[1];

	std::string full_book_name = arr_line[2];
	for (int j = 3; j < arr_line.size() - 2; ++j) {
		full_book_name += (" " + arr_line[j]);
	}
	book._book_name = full_book_name;

	book._the_year_of_publishing = Formatting().formatting(arr_line[arr_line.size() - 2]);
	book._count = Formatting().formatting(arr_line[arr_line.size() - 1]);

	arr_book.push_back(book);
}

void Write::write_to_vector(const std::vector<std::string>& arr_line, std::vector<std::vector<Book>>& arr_book) {
	Book book;

	book._name = arr_line[0];
	book._last_name = arr_line[1];

	std::string full_book_name = arr_line[2];
	for (int j = 3; j < arr_line.size() - 2; ++j) {
		full_book_name += (" " + arr_line[j]);
	}
	book._book_name = full_book_name;

	book._the_year_of_publishing = Formatting().formatting(arr_line[arr_line.size() - 2]);
	book._count = Formatting().formatting(arr_line[arr_line.size() - 1]);


	std::vector<Book> arr;
	arr.push_back(book);
	arr_book.push_back(arr);
}