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
#include "Search.h"

class Library {
public:
	virtual ~Library() {}
	virtual void create() = 0;
	virtual void search(std::vector<Book>& arr, const std::string& name, int date) = 0;
private:
	virtual void sort_arr() = 0;
};