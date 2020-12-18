#include "Vector.h"
#include <iostream> // Убрать потом ( как сделаю норм вывод )

Vector::Vector()
{
	create();
}

void Vector::create()
{
	try 
	{
		ScanFile().scan(_arr);
		sort_arr();
	} 
	catch (const std::exception& exept) 
	{
		throw exept;
	}
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