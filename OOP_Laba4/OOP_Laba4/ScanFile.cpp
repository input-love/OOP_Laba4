#include "ScanFile.h"

void ScanFile::scan(std::vector<std::vector<std::string>>& arr) {
	std::ifstream fin("Library.txt");
	if (!fin.is_open()) {
		throw std::exception("Файл не открылся...");
	} else {
		int count = 0;
		while (!fin.eof()) {
			std::string line;
			std::getline(fin, line);
			
			std::vector<std::string> list_words;
			Parser::parser(list_words, line);
			arr.push_back(list_words);

			count++;
		}
	}
	fin.close();
}