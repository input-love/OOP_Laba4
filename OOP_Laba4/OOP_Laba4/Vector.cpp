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
		it = std::find_if(_arr.begin(), _arr.end(), SearchSurname(arr_word[1]));

		if (it != _arr.end())
		{
			Book book;
			Write().write(arr_word, book);

			(*it).push_back(book);
		}
		else
		{
			Book book;
			std::vector<Book> arr;

			Write().write(arr_word, book);
			arr.push_back(book);

			_arr.push_back(arr);
		}
	}

	sort_arr();
}

void Vector::search(std::vector<Book>& arr, const std::string& surname, int date)
{
	std::vector<std::vector<Book>>::iterator it = _arr.begin();

	it = std::find_if(_arr.begin(), _arr.end(), SearchSurname(surname));
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

void Vector::delete_book(const std::string& surname, const std::string& name_book)
{
	std::vector<std::vector<Book>>::iterator it_vector = _arr.begin();
	it_vector = std::find_if(_arr.begin(), _arr.end(), SearchSurname(surname));

	if (it_vector != _arr.end())
	{
		std::vector<Book>::iterator it_book = (*it_vector).begin();
		it_book = std::find_if((*it_vector).begin(), (*it_vector).end(), SearchNameBook(name_book));

		if (it_book != (*it_vector).end())
		{
			(*it_vector).erase(it_book);
		}
	}
}

void Vector::delete_book_by_writer(const std::string& surname)
{
	std::vector<std::vector<Book>>::iterator it = _arr.begin();
	it = std::find_if(_arr.begin(), _arr.end(), SearchSurname(surname));
	
	if (it != _arr.end())
	{
		_arr.erase(it);
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