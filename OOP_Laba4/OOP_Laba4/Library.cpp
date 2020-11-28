#include "Library.h"

void Library::create_vector_book() {
	try {
		std::vector<std::vector<std::string>> arr;
		ScanFile::scan(arr);
		Write::write_to_vector(arr, _arr_book);
	} catch (const std::exception& exept) {
		std::cout << exept.what() << std::endl;
	}
}

void Library::create_map_book() {
	//...
}

std::vector<Book>& Library::get_vector() {
	return _arr_book;
}