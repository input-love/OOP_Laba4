#include "Console.h"

void Console::start() const {
	setlocale(LC_ALL, "Russian");

	Library library;

	int check = 1;
	while (check) {
		print_menu();

		std::cout << "��� �� ������ �������?: ";
		std::cin >> check;

		switch (check) {
		case 1:
		{
			int type;
			std::cout << "1 - ������� vector" << std::endl;
			std::cout << "2 - ������� map" << std::endl;
			std::cin >> type;
			if (type == 1) {
				library.create_vector_book();
			} else if (type == 2) {
				library.create_map_book();
			}
			std::cout << "�������...����������!" << std::endl;
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "������� ��� ������:" << std::endl;
			std::cin >> name;

			int the_year_of_publishing;
			std::cout << "������� ��� ������� �����:" << std::endl;
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
	std::cout << "0 - ��������� ������ ���������" << std::endl;
	std::cout << "1 - ������� ����������" << std::endl;
	std::cout << "2 - ������ �������� ������ � ����� �����" << std::endl;
	std::cout << "3 - ������� ��� ����� � ����������" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void Console::print_menu_book(const Book& book) const {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "���: " << book._name << std::endl;
	std::cout << "�������: " << book._last_name << std::endl;
	std::cout << "�������� �����: " << book._book_name << std::endl;
	std::cout << "��� ��������� �����: " << book._the_year_of_publishing << std::endl;
	std::cout << "���������� ���� � ����������: " << book._count << std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl;
}