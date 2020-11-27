#include "Console.h"

void Console::start() const {
	setlocale(LC_ALL, "Russian");

	Library library;
	library.create_arr_book();

	bool check = 1;
	while (check) {
		print_menu();

		std::cout << "��� �� ������ �������?: ";
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
	std::cout << "0 - ��������� ������ ���������" << std::endl;
	std::cout << "1 - ������� ��� ����� � ����������" << std::endl;
	std::cout << "2 - ������ �������� ������ � ����� �����" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}