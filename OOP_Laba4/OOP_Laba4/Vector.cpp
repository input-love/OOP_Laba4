#include "Vector.h"

void Vector::create()
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

		std::vector<std::vector<Book>>::iterator it = _arr.begin();

		it = std::find_if(_arr.begin(), _arr.end(), Fo_name(arr_word[1]));
		if (it != _arr.end())
		{
			Write().write(arr_word, (*it));
		}
		else
		{
			Write().write_new_vector(arr_word, _arr);
		}
	}

	sort_arr();
}

void Vector::search(std::vector<Book>& arr, const std::string& name, int date)
{
	std::vector<std::vector<Book>>::iterator it = _arr.begin();

	it = std::find_if(_arr.begin(), _arr.end(), Fo_name(name));
	if (it != _arr.end())
	{
		int count = (*it).size();
		for (int i = 0; i < count; ++i)
		{
			if ((*it)[i]._the_year_of_publishing > date)
			{
				for (int j = i; j < count; ++j)
				{
					arr.push_back((*it)[j]);
				}
				break;
			}
		}
	}
}

void Vector::sort_arr()
{
	int count = _arr.size();
	for (int i = 0; i < count; ++i)
	{
		std::sort(_arr[i].begin(), _arr[i].end());
	}
}