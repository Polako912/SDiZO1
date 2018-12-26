#include <iostream>
#include "Test.h"
#include "Menu.h"

void Menu::menu()
{
	int choice = 99;
	Test test;

	std::cout << "SDiZO, Projekt 1, Michal Polak, 235046" << std::endl << std::endl;

	//Pocz¹tkowe menu wyboru
	while (choice != 0)
	{
		std::cout << "Wybierz test:" << std::endl;
		std::cout << "    1. Tablica Dynamiczna" << std::endl;
		std::cout << "    2. Lista" << std::endl;
		std::cout << "    3. Kopiec Binarny" << std::endl;
		std::cout << "    0. Wyjscie" << std::endl << std::endl;
		std::cout << "Wybor: ";
		std::cin >> choice;
		std::cout << std::endl;

		//Zamknij, je¿eli wybrano 0
		if (choice == 0) exit(EXIT_SUCCESS);

		switch (choice)
		{
		default:
			std::cout << "Bledny wybor!" << std::endl;
			break;

		case 0:
			break;

		case 1:
			std::cout << "Rozpoczynam test tablicy dynamicznej..." << std::endl;
			test.array();
			break;

		case 2:
			std::cout << "Rozpoczynam test listy..." << std::endl;
			test.list();
			break;

		case 3:
			std::cout << "Rozpoczynam test kopca binarnego..." << std::endl;
			test.heap();
			break;
		}
	}
}