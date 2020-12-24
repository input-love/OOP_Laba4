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
			dialog_search();
			break;
		case 2:
			dialog_delete_book();
			break;
		case 3:
			dialog_delete_book_by_writer();
			break;
		default:
			check = 0;
		}
		system("pause");
	} while (check);
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

void Console::dialog_delete_book() const
{
	std::string surname = dialog_get_surname();
	std::string name_book = dialog_get_name_book();

	_library->delete_book(surname, name_book);
}

void Console::dialog_delete_book_by_writer() const
{
	std::string surname = dialog_get_surname();

	_library->delete_book_by_writer(surname);
}

int Console::dialog_type_arr()
{
	int type;
	do
	{
		print_create_arr();
		std::cin >> type;
	} while (type < 1 || type > 2);
	return type;
}

std::string Console::dialog_get_surname() const
{
	std::string surname;
	std::cout << "Введите фамилию автора:" << std::endl;
	std::cin >> surname;
	return surname;
}

std::string Console::dialog_get_name_book() const
{
	std::string name_book;
	std::cout << "Введите название книги:" << std::endl;
	std::cin >> name_book;
	return name_book;
}

int Console::dialog_get_date() const
{
	int date;
	std::cout << "Введите год издания книги:" << std::endl;
	std::cin >> date;
	return date;
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
	std::cout << "1 - Найти книги | По фамилии автора" << std::endl;
	std::cout << "2 - Удалить книгу | По названию произведения" << std::endl;
	std::cout << "3 - Удалить каталог книг | По фамилии автора" << std::endl;
	std::cout << "4 - Завершить работу программы" << std::endl;
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