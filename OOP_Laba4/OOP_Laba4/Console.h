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
	int dialog_type_arr();
	void dialog_menu() const;
	void dialog_search() const;
	std::string dialog_get_surname() const;
	int dialog_get_date() const;
	void print_create_arr() const;
	void print_menu() const;
	void print_book(const Book& book) const;
	void clear_console() const;

	Library* _library = nullptr;
};