#include "Library.h"

void Library::create_arr_book() {
	try {
		std::vector<std::vector<std::string>> arr;
		ScanFile::scan(arr);
		Write::write_to_vector(arr, _arr_book);
	} catch (const std::exception& exept) {
		std::cout << exept.what() << std::endl;
	}
}

void Library::print_all_book() const {
	for (int i = 0; i < _arr_book.size(); ++i) {
		std::cout << "Name: " << _arr_book[i]._name << std::endl;
		std::cout << "Last Name: " << _arr_book[i]._last_name << std::endl;
		std::cout << "Book Name: " << _arr_book[i]._book_name << std::endl;
		std::cout << "Year: " << _arr_book[i]._the_year_of_publishing << std::endl;
		std::cout << "Count Book: " << _arr_book[i]._count << std::endl << std::endl;
	}
}