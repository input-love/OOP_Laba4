#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "Book.h"
#include "ScanFile.h"
#include "Parser.h"
#include "Write.h"
#include "SearchSurname.h"
#include "SearchNameBook.h"

class Library {
public:
	virtual ~Library() {}
	virtual void create() = 0;
	virtual void search(std::vector<Book>& arr, const std::string& surname, int date) = 0;
	virtual void delete_book(const std::string& surname, const std::string& name_book) = 0;
	virtual void delete_book_by_writer(const std::string& surname) = 0;
private:
	virtual void sort_arr() = 0;
};