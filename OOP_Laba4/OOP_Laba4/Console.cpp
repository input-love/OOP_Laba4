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
	std::cout << "������� ��� ������� ������: " << std::endl;
	std::cin >> surname;

	int date;
	std::cout << "������� ��� ������� �����: " << std::endl;
	std::cin >> date;

	_library->search(surname, date);
}

void Console::dialog_print_all_book() const
{
	//���-�� ���� ��� ���������!
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
	std::cout << "0 - ��������� ������ ���������" << std::endl;
	std::cout << "1 - ������ �������� ������, ����� �����" << std::endl;
	std::cout << "2 - ������� ��� ����� � ����������" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "��� �� ������ �������?: ";
}

void Console::print_all_book(const Book& book) const 
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