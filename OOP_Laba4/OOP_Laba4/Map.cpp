#include "Map.h"

void Map::create()
{
	std::vector<std::string> arr_line;

	try
	{	
		ScanFile().scan(arr_line);
	}
	catch (const std::exception& exept)
	{
		throw exept;
	}

	int count = arr_line.size();
	for (int i = 0; i < count; ++i)
	{
		std::vector<std::string> arr_word;
		Parser().parser(arr_word, arr_line[i]);

		auto it = _arr.find(arr_word[1]);
		if (it != _arr.end())
		{
			Book book;
			Write().write(arr_word, book);

			it->second.push_back(book);
		}
		else
		{
			Book book;
			std::vector<Book> arr;

			Write().write(arr_word, book);
			arr.push_back(book);

			_arr.emplace(book._last_name, arr);
		}
	}

	sort_arr();
}

void Map::search(std::vector<Book>& arr, const std::string& surname, int date)
{
	auto it = _arr.find(surname);
	if (it != _arr.end())
	{
		int count = it->second.size();
		for (int i = 0; i < count; ++i)
		{
			if (it->second[i]._the_year_of_publishing > date)
			{
				for (int j = i; j < count; ++j)
				{
					arr.push_back(it->second[j]);
				}
				break;
			}
		}
	}
}

void Map::delete_book(const std::string& surname, const std::string& name_book)
{
	auto it_map = _arr.find(surname);
	if (it_map != _arr.end())
	{
		std::vector<Book>::iterator it_book = (*it_map).second.begin();
		it_book = std::find_if((*it_map).second.begin() , (*it_map).second.end(), SearchNameBook(name_book));

		if (it_book != (*it_map).second.end())
		{
			(*it_map).second.erase(it_book);
		}
	}
}

void Map::delete_book_by_writer(const std::string& surname)
{
	auto it = _arr.find(surname);
	if (it != _arr.end())
	{
		_arr.erase(it);
	}
}

void Map::sort_arr()
{
	std::map<std::string, std::vector<Book>>::iterator it;
	for (it = _arr.begin(); it != _arr.end(); it++)
	{
		std::sort(it->second.begin(), it->second.end());
	}
}