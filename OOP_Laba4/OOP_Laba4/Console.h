#pragma once
#include <clocale>
#include "Library.h"
#include "Search.h"

class Console {
public:
	void start() const;
private:
	void print_menu() const;
	void print_menu_book(const Book& book) const;
};