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

void Library::search_by_vector(std::vector<Book>& arr, std::string name, int date) {
	std::vector<Book>::iterator it = _arr_book.begin();
	while (it != _arr_book.end()) {
		it = std::find_if(it, _arr_book.end(), Fo_name(name));
		if (it != _arr_book.end()) {
			if ((*it)._the_year_of_publishing >= date) {
				arr.push_back(*it);
			}
			it++;
		} else {
			break;
		}
	}
}

void Library::search_by_map() const {
	//...
}

const std::vector<Book>& Library::get_vector() const {
	return _arr_book;
}