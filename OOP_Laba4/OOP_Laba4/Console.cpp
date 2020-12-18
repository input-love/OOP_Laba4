#include "Console.h"

Console::~Console()
{
	delete _library;
}

void Console::start()
{
	try
	{
		int type = dialog_type_arr();
		_library = ShapeFactory().createShape(type);
		_library->create();

		dialog_menu();
	}
	catch (const std::exception& exept)
	{
		std::cout << exept.what() << std::endl;
	}
}

int Console::dialog_type_arr()
{
	int type;
	do
	{
		print_create_arr();
		std::cin >> type;
	} while (type < 0 || type > 1);
	return type;
}

void Console::dialog_menu() const 
{
	int check;
	do
	{
		print_menu();

		std::cin >> check;
		if (!check)
		{
			dialog_search();
		}

		system("pause");
	} while (!check);
}

void Console::dialog_search() const
{
	std::string surname = dialog_get_surname();
	int date = dialog_get_date();
	
	std::vector<Book> arr;
	_library->search(arr, surname, date);

	int count = arr.size();
	for (int i = 0; i < count; ++i)
	{
		print_book(arr[i]);
	}
}

std::string Console::dialog_get_surname() const
{
	std::string surname;
	std::cout << "Введите фамилию автора: " << std::endl;
	std::cin >> surname;
	return surname;
}

int Console::dialog_get_date() const
{
	int date;
	std::cout << "Введите год издания книги: " << std::endl;
	std::cin >> date;
	return date;
}

void Console::print_create_arr() const
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - Создать vector" << std::endl;
	std::cout << "1 - Создать map" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu() const 
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - Найти книги автора" << std::endl;
	std::cout << "1 - Закончить работу программы" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Что вы хотите сделать?: ";
}

void Console::print_book(const Book& book) const 
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Имя: " << book._name << std::endl;
	std::cout << "Фамилия: " << book._last_name << std::endl;
	std::cout << "Название книги: " << book._book_name << std::endl;
	std::cout << "Год написания книги: " << book._the_year_of_publishing << std::endl;
	std::cout << "Количество книг в библиотеке: " << book._count << std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::clear_console() const
{
	system("cls");
}