#include "Write.h"

void Write::write_to_vector(const std::vector<std::vector<std::string>>& arr, std::vector<Book>& arr_book) {
	for (int i = 0; i < arr.size(); ++i) {
		Book book;
		arr_book.push_back(book);

		arr_book[i]._name = arr[i][0];
		arr_book[i]._last_name = arr[i][1];

		std::string full_book_name = arr[i][2];
		for (int j = 3; j < arr[i].size() - 2; ++j) {
				full_book_name += (" " + arr[i][j]);
		}
		arr_book[i]._book_name = full_book_name;

		arr_book[i]._the_year_of_publishing = Formatting::formatting(arr[i][arr[i].size() - 2]);
		arr_book[i]._count = Formatting::formatting(arr[i][arr[i].size() - 1]);
	}
}