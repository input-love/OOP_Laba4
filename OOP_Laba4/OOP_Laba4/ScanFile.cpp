#include "ScanFile.h"

void ScanFile::scan(std::vector<std::vector<Book>>& arr_book) {
	std::ifstream fin("Library.txt");
	if (!fin.is_open()) {
		throw std::exception("Файл не открылся...");
	} else {
		while (!fin.eof()) {
			std::string line;
			std::getline(fin, line);
			
			std::vector<std::string> arr_line;
			Parser().parser(arr_line, line);

			std::vector<std::vector<Book>>::iterator it = arr_book.begin();

			it = std::find_if(arr_book.begin(), arr_book.end(), Fo_name(arr_line[1]));
			if (it != arr_book.end())
			{
				Write().write_to_vector(arr_line, (*it));
			}
			else
			{
				Write().write_to_vector(arr_line, arr_book);
			}
		}
	}
	fin.close();
}