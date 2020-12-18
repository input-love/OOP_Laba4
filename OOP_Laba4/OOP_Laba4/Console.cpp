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
	std::cout << "������� ������� ������: " << std::endl;
	std::cin >> surname;
	return surname;
}

int Console::dialog_get_date() const
{
	int date;
	std::cout << "������� ��� ������� �����: " << std::endl;
	std::cin >> date;
	return date;
}

void Console::print_create_arr() const
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - ������� vector" << std::endl;
	std::cout << "1 - ������� map" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu() const 
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - ����� ����� ������" << std::endl;
	std::cout << "1 - ��������� ������ ���������" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "��� �� ������ �������?: ";
}

void Console::print_book(const Book& book) const 
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "���: " << book._name << std::endl;
	std::cout << "�������: " << book._last_name << std::endl;
	std::cout << "�������� �����: " << book._book_name << std::endl;
	std::cout << "��� ��������� �����: " << book._the_year_of_publishing << std::endl;
	std::cout << "���������� ���� � ����������: " << book._count << std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::clear_console() const
{
	system("cls");
}