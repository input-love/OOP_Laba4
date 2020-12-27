#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>
#include "Book.h"

class Library {
public:
	void add_book(const Book& book);

	void search_by_name(std::vector<Book>& arr, const std::string& name);
	void search_by_surname(std::vector<Book>& arr, const std::string& surname);
	void search_by_book_name(std::vector<Book>& arr, const std::string& book_name);
	void search_by_date(std::vector<Book>& arr, const int date);

	int get_size_library() const;

	const Book& operator [] (int id) const;
private:
	int _last_id;
	std::map<int, Book> _books;
	std::map<std::string, std::set<int>> _index_by_name;
	std::map<std::string, std::set<int>> _index_by_surname;
	std::map<std::string, std::set<int>> _index_by_book_name;
	std::map<int, std::set<int>> _index_by_date;
};