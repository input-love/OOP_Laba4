#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "ScanFile.h"
#include "Write.h"

class Library {
public:
	void create_vector_book();
	void create_map_book();
	std::vector<Book>& get_vector();
private:
	std::vector<Book> _arr_book;
};