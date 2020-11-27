#include "Console.h"

void Console::start() const {
	setlocale(LC_ALL, "Russian");

	Library library;
	library.create_arr_book();

	bool check = 1;
	while (check) {
		print_menu();

		std::cout << "Что вы хотите сделать?: ";
		std::cin >> check;

		switch (check) {
		case 1:
			library.print_all_book();
		case 2:
			//....
			break;
		}
	}
}

void Console::print_menu() const {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "0 - Закончить работу программы" << std::endl;
	std::cout << "1 - Вывести все книги в библиотеке" << std::endl;
	std::cout << "2 - Ввести критерии поиска и найти книги" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}