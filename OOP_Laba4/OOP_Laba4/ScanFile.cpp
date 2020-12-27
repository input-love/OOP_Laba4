#include "ScanFile.h"

void ScanFile::scan(std::vector<std::string>& arr) {
	std::ifstream fin("Library.txt");
	if (!fin.is_open()) {
		throw std::exception("Файл не открылся...");
	} else {
		while (!fin.eof()) {
			std::string line;

			std::getline(fin, line);

			arr.push_back(line);	
		}
	}
	fin.close();
}