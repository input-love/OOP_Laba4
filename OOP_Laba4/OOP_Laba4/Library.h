#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "ScanFile.h"
#include "Write.h"

class Library {
public:
	void create_arr_book();
	void print_all_book() const;
private:
	std::vector<Book> _arr_book;
};