#pragma once
#include <string>

class Book {
public:
	Book() = default;
	Book(const Book& book);
	Book(const std::string& name, const std::string& surname, const std::string& book_name, int date, int count);	

	std::string _name;
	std::string _last_name;
	std::string _book_name;
	int _the_year_of_publishing;
	int _count;
};