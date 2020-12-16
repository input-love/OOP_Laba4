#pragma once
#include <string>

class Book {
public:
	bool operator < (const Book& book) const; // Проверить нужен ли он вообще

	std::string _name;
	std::string _last_name;
	std::string _book_name;
	int _the_year_of_publishing;
	int _count;
};