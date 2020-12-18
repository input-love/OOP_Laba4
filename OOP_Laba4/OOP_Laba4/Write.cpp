#include "Write.h"

void Write::write(const std::vector<std::string>& arr_word, std::vector<Book>& arr_book) 
{
	Book book;
	create_book(arr_word, book);

	arr_book.push_back(book);
}

void Write::write_new_vector(const std::vector<std::string>& arr_word, std::vector<std::vector<Book>>& arr_book) 
{
	Book book;
	create_book(arr_word, book);

	std::vector<Book> arr;
	arr.push_back(book);
	arr_book.push_back(arr);
}

void Write::write_new_map(const std::vector<std::string>& arr_word, std::map<std::string, std::vector<Book>>& arr_book)
{
	Book book;
	create_book(arr_word, book);

	std::vector<Book> arr;
	arr.push_back(book);
	arr_book.emplace(book._last_name, arr);
}

void Write::create_book(const std::vector<std::string>& arr_word, Book& book)
{
	book._name = arr_word[0];
	book._last_name = arr_word[1];

	std::string full_book_name = arr_word[2];
	for (int j = 3; j < arr_word.size() - 2; ++j) {
		full_book_name += (" " + arr_word[j]);
	}
	book._book_name = full_book_name;

	book._the_year_of_publishing = Formatting().formatting(arr_word[arr_word.size() - 2]);
	book._count = Formatting().formatting(arr_word[arr_word.size() - 1]);
}