#pragma once
#include <iostream>
#include <clocale>
#include <cstdlib>
#include "Library.h"
#include "ShapeFactory.h"

class Console {
public:
	~Console();
	void start();
private:
	void dialog_create_arr();
	void dialog_menu() const;
	void dialog_search() const;
	void dialog_print_all_book() const;
	std::string dialog_get_surname() const;
	int dialog_get_date() const;
	void print_create_arr() const;
	void print_menu() const;
	void print_all_book(const Book& book) const;
	void clear_console() const;

	Library* _library = nullptr;
};