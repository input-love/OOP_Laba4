#include "Console.h"

void Console::start() const {
	setlocale(LC_ALL, "Russian");

	Library library;

	int check = 1;
	while (check) {
		print_menu();

		std::cout << "Что вы хотите сделать?: ";
		std::cin >> check;

		switch (check) {
		case 1:
		{
			int type;
			std::cout << "1 - Создать vector" << std::endl;
			std::cout << "2 - Создать map" << std::endl;
			std::cin >> type;
			if (type == 1) {
				library.create_vector_book();
			} else if (type == 2) {
				library.create_map_book();
			}
			std::cout << "Успешно...продолжаем!" << std::endl;
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "Введите имя автора:" << std::endl;
			std::cin >> name;

			int the_year_of_publishing;
			std::cout << "Введите год издания книги:" << std::endl;
			std::cin >> the_year_of_publishing;

			std::vector<Book>& arr_book = library.get_vector();
			std::vector<Book>::iterator it = arr_book.begin();

			while (it != arr_book.end()) {
				it = std::find_if(it, arr_book.end(), fo_name(name));
				if (it != arr_book.end()) {
					if ((*it)._the_year_of_publishing >= the_year_of_publishing) {
						print_menu_book((*it));
					}
					it++;
				} else {
					break;
				}
			}

			break;
		}
		case 3:
		{
			const std::vector<Book>& vec = library.get_vector();
			for (int i = 0; i < vec.size(); ++i) {
				print_menu_book(vec[i]);
			}
			break;
		}
		}
	}
}

void Console::print_menu() const {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - Закончить работу программы" << std::endl;
	std::cout << "1 - Создать библиотеку" << std::endl;
	std::cout << "2 - Ввести критерии поиска и найти книги" << std::endl;
	std::cout << "3 - Вывести все книги в библиотеке" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu_book(const Book& book) const {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Имя: " << book._name << std::endl;
	std::cout << "Фамилия: " << book._last_name << std::endl;
	std::cout << "Название книги: " << book._book_name << std::endl;
	std::cout << "Год написания книги: " << book._the_year_of_publishing << std::endl;
	std::cout << "Количество книг в библиотеке: " << book._count << std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl;
}