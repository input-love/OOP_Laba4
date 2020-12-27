#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Library.h"
#include "ScanFile.h"
#include "Parser.h"
#include "Write.h"

class Console {
public:
	~Console();
	void start();
private:
	void dialog_menu() const;
	void dialog_add_book() const;
	void dialog_search() const;
	void dialog_print_all_book() const;

	std::string dialog_get_name() const;
	std::string dialog_get_surname() const;
	std::string dialog_get_book_name() const;
	int dialog_get_date() const;
	int dialog_get_count() const;

	void print_menu() const;
	void print_choice_search() const;
	void print_book(const Book& book) const;

	Library* _library;
};