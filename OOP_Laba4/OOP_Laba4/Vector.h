#pragma once
#include "Library.h"

class Vector: public Library {
public:
	void create() override;
	void search(std::vector<Book>& arr, const std::string& surname, int date) override;
	void delete_book(const std::string& surname, const std::string& name_book) override;
	void delete_book_by_writer(const std::string& surname) override;
private:
	void sort_arr() override;

	std::vector<std::vector<Book>> _arr;
};