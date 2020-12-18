#pragma once
#include "Library.h"

class Map: public Library {
public:
	void create() override;
	void search(std::vector<Book>& arr, const std::string& name, int date) override;
private:
	void sort_arr() override;

	std::map<std::string, std::vector<Book>> _arr;
};