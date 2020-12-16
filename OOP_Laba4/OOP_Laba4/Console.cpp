#include "Console.h"

Console::~Console()
{
	delete _library;
}

void Console::start()
{
	setlocale(LC_ALL, "Russian");

	dialog_create_arr();
	dialog_menu();
}

void Console::dialog_create_arr()
{
	int type;
	do
	{
		print_create_arr();
		std::cin >> type;
	} while (type < 1 || type > 2);

	_library = ShapeFactory().createShape(type);
}

void Console::dialog_menu() const 
{
	int check;
	do
	{
		print_menu();

		std::cin >> check;

		switch (check) 
		{
		case 1:
		{
			dialog_search();
			break;
		}
		case 2:
		{
			dialog_print_all_book();
			break;
		}
		}
		system("pause");
	} while (check);
}

void Console::dialog_search() const
{
	std::string surname;
	std::cout << "Введите его фамилию автора: " << std::endl;
	std::cin >> surname;

	int date;
	std::cout << "Введите год издания книги: " << std::endl;
	std::cin >> date;

	_library->search(surname, date);
}

void Console::dialog_print_all_book() const
{
	//Что-то надо тут придумать!
}

void Console::print_create_arr() const
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1 - Создать vector" << std::endl;
	std::cout << "2 - Создать map" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu() const 
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - Закончить работу программы" << std::endl;
	std::cout << "1 - Ввести критерии поиска, найти книги" << std::endl;
	std::cout << "2 - Вывести все книги в библиотеке" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Что вы хотите сделать?: ";
}

void Console::print_all_book(const Book& book) const 
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