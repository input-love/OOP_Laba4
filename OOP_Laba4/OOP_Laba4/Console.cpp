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
	std::cout << "������� ������� ������:" << std::endl;
	std::cin >> surname;
	return surname;
}

std::string Console::dialog_get_name_book() const
{
	std::string name_book;
	std::cout << "������� �������� �����:" << std::endl;
	std::cin >> name_book;
	return name_book;
}

int Console::dialog_get_date() const
{
	int date;
	std::cout << "������� ��� ������� �����:" << std::endl;
	std::cin >> date;
	return date;
}

void Console::print_create_arr() const
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1 - ������� vector" << std::endl;
	std::cout << "2 - ������� map" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu() const 
{
	clear_console();
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1 - ����� ����� | �� ������� ������" << std::endl;
	std::cout << "2 - ������� ����� | �� �������� ������������" << std::endl;
	std::cout << "3 - ������� ������� ���� | �� ������� ������" << std::endl;
	std::cout << "4 - ��������� ������ ���������" << std::endl;
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