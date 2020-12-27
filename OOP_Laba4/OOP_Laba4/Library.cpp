#include "Library.h"

void Library::add_book(const Book& book)
{
	_books.emplace(_last_id, book);
	_index_by_name[book._name].insert(_last_id);
	_index_by_surname[book._last_name].insert(_last_id);
	_index_by_book_name[book._book_name].insert(_last_id);
	_index_by_date[book._the_year_of_publishing].insert(_last_id);
	_last_id++;
}

void Library::search_by_name(std::vector<Book>& arr, const std::string& name)
{
	auto it = _index_by_name.find(name);
	if (it != _index_by_name.end())
	{
		for (auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet)
		{
			arr.push_back(_books[*itSet]);
		}
	}
}

void Library::search_by_surname(std::vector<Book>& arr, const std::string& surname)
{
	auto it = _index_by_surname.find(surname);
	if (it != _index_by_surname.end())
	{
		for (auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet)
		{
			arr.push_back(_books[*itSet]);
		}
	}
}

void Library::search_by_book_name(std::vector<Book>& arr, const std::string& book_name)
{
	auto it = _index_by_book_name.find(book_name);
	if (it != _index_by_book_name.end())
	{
		for (auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet)
		{
			arr.push_back(_books[*itSet]);
		}
	}
}

void Library::search_by_date(std::vector<Book>& arr, const int date)
{
	auto it = _index_by_date.find(date);
	if (it != _index_by_date.end())
	{
		for (auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet)
		{
			arr.push_back(_books[*itSet]);
		}
	}
}

int Library::get_size_library() const
{
	return _books.size();
}

const Book& Library::operator [] (int id) const
{
	auto it = _books.find(id);
	return (*it).second;
}