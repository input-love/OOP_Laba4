#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "ScanFile.h"
#include "Write.h"
#include "Search.h"

class Library {
public:
	void create_vector_book();
	void create_map_book();
	void search_by_vector(std::vector<Book>& arr, std::string name, int date);
	void search_by_map() const;
	const std::vector<Book>& get_vector() const;
private:
	std::vector<Book> _arr_book;
};