#pragma once
#include "Library.h"

class Map: public Library {
public:
	Map();
	void create() override;
	void search(std::vector<Book>& arr, const std::string& name, int date) override;
	void sort_arr() override;
private:
	std::map<std::string, std::map<std::string, Book>> _arr;
};