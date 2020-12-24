#pragma once
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Library.h"
#include "ShapeFactory.h"

class Console {
public:
	~Console();
	void start();
private:
	void dialog_menu() const;
	void dialog_search() const;
	void dialog_delete_book() const;
	void dialog_delete_book_by_writer() const;

	int dialog_type_arr();
	std::string dialog_get_surname() const;
	std::string dialog_get_name_book() const;
	int dialog_get_date() const;

	void print_create_arr() const;
	void print_menu() const;
	void print_book(const Book& book) const;
	void clear_console() const;

	Library* _library = nullptr;
};