#pragma once
#include "Library.h"

class Vector: public Library {
public:
	Vector();
	void create() override;
	void search(const std::string& name, int date) override;
	void sort_arr() override;
private:
	std::vector<std::vector<Book>> _arr;
};