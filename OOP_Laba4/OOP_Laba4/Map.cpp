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
			Write().write(arr_word, it->second);
		}
		else
		{
			Write().write_new_map(arr_word, _arr);
		}
	}

	sort_arr();
}

void Map::search(std::vector<Book>& arr, const std::string& name, int date)
{
	auto it = _arr.find(name);
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

void Map::sort_arr()
{
	std::map<std::string, std::vector<Book>>::iterator it;
	for (it = _arr.begin(); it != _arr.end(); it++)
	{
		std::sort(it->second.begin(), it->second.end());
	}
}