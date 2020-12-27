#include "Console.h"

Console::~Console()
{
	delete _library;
}

void Console::start()
{
	try
	{
		_library = new Library();

		std::vector<std::string> arr_line;
		ScanFile().scan(arr_line);

		for (int i = 0; i < arr_line.size(); ++i)
		{
			std::vector<std::string> arr_word;
			Parser().parser(arr_word, arr_line[i]);

			Book book;
			Write().write(arr_word, book);

			_library->add_book(book);
		}

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
		{
			dialog_add_book();
			break;
		}
		case 2:
		{
			dialog_search();
			break;
		}
		case 3:
		{
			dialog_print_all_book();
			break;
		}
		default:
			check = 0;
		}
		system("pause");
		system("cls");
	} while (check);
}

void Console::dialog_add_book() const
{
	std::string name = dialog_get_name();
	std::string surname = dialog_get_surname();
	std::string book_name = dialog_get_book_name();
	int date = dialog_get_date();
	int count = dialog_get_count();

	Book book(name, surname, book_name, date, count);
	_library->add_book(book);
}

void Console::dialog_search() const
{
	print_choice_search();

	int check;
	std::cin >> check;

	std::vector<Book> arr;
	switch (check)
	{
	case 1:
	{
		std::string name = dialog_get_name();
		_library->search_by_name(arr, name);
		break;
	}
	case 2:
	{
		std::string surname = dialog_get_surname();
		_library->search_by_surname(arr, surname);
		break;
	}
	case 3:
	{
		std::string book_name = dialog_get_book_name();
		_library->search_by_book_name(arr, book_name);
		break;
	}
	case 4:
	{
		int date = dialog_get_date();
		_library->search_by_date(arr, date);
		break;
	}
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		print_book(arr[i]);
	}
}

void Console::dialog_print_all_book() const
{
	int size = _library->get_size_library();
	for (int i = 0; i < size; ++i)
	{
		print_book(_library->operator[](i));
	}
}


std::string Console::dialog_get_name() const
{
	std::string name;
	std::cout << "Введите имя автора:" << std::endl;
	std::cin >> name;
	return name;
}

std::string Console::dialog_get_surname() const
{
	std::string surname;
	std::cout << "Введите фамилию автора:" << std::endl;
	std::cin >> surname;
	return surname;
}

std::string Console::dialog_get_book_name() const
{
	std::string book_name;
	std::cout << "Введите название книги:" << std::endl;
	getchar();
	std::getline(std::cin, book_name);
	return book_name;
}

int Console::dialog_get_date() const
{
	int date;
	std::cout << "Введите год издания книги:" << std::endl;
	std::cin >> date;
	return date;
}

int Console::dialog_get_count() const
{
	int count;
	std::cout << "Введите кол-во книг в библиотеке:" << std::endl;
	std::cin >> count;
	return count;
}


void Console::print_menu() const
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "1 - Добавить книгу" << std::endl;
	std::cout << "2 - Найти книгу" << std::endl;
	std::cout << "3 - Вывод полного списка книг" << std::endl;
	std::cout << "4 - Завершить работу программы" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Что вы хотите сделать?: ";
}

void Console::print_choice_search() const
{
	std::cout << "1. Найти по имени автора" << std::endl;
	std::cout << "2. Найти по фамилии" << std::endl;
	std::cout << "3. Найти по названию книги" << std::endl;
	std::cout << "4. Найти по дате её публикации" << std::endl;
}

void Console::print_book(const Book& book) const
{
	std::cout << "\n-----------------------------------" << std::endl;
	std::cout << "Имя: " << book._name << std::endl;
	std::cout << "Фамилия: " << book._last_name << std::endl;
	std::cout << "Название книги: " << book._book_name << std::endl;
	std::cout << "Год написания книги: " << book._the_year_of_publishing << std::endl;
	std::cout << "Количество книг в библиотеке: " << book._count << std::endl << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}