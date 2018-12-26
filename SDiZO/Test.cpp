#include "Test.h"
#include <iostream>
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include <fstream>
#include "Menu.h"
#include <ctime>

void Test::array()
{
	int choice = 99;
	int value;
	int position; 
	int number; 
	std::string file_name;

	Array array;
	Menu menu;

	array.read_from_file();

	std::cout << "Test Tablic, wybierz co chcesz zrobic" << std::endl << std::endl;

	//Pocz¹tkowe menu wyboru
	while (choice != 0)
	{
		std::cout << "Wybierz test:" << std::endl;
		std::cout << "    1. Dodaj element na poczatek tablicy" << std::endl;
		std::cout << "    2. Dodaj element na koniec tablicy" << std::endl;
		std::cout << "    3. Dodaj element w dowolne miejsce tablicy" << std::endl;
		std::cout << "    4. Usun pierwszy element tablicy" << std::endl;
		std::cout << "    5. Usun ostatni element tablicy" << std::endl;
		std::cout << "    6. Usun dowolny element tablicy" << std::endl;
		std::cout << "    7. Wyszukaj element tablicy" << std::endl;
		std::cout << "    8. Wyswietl tablice" << std::endl;
		std::cout << "    9. Powrot" << std::endl;
		std::cout << "    0. Wyjscie" << std::endl;
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
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			array.push_begining(value);
			array.show_array();
			break;

		case 2:
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			array.push_end(value);
			array.show_array();
			break;

		case 3:
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			std::cout << "Podaj pozycje: " << std::endl;
			std::cin >> position;
			array.push(value, position);
			array.show_array();
			break;

		case 4:
			array.pop_begining();
			array.show_array();
			break;

		case 5:
			array.pop_end();
			array.show_array();
			break;

		case 6:
			std::cout << "Podaj pozycje: " << std::endl;
			std::cin >> position;
			array.pop(position);
			array.show_array();
			break;

		case 7:
			std::cout << "Podaj liczbe ktora chcesz wyszukac: " << std::endl;
			std::cin >> number;
			array.search(number);
			break;

		case 8:
			array.show_array();
			break;

		case 9:
			menu.menu();
			break;
		}
	}
}

void Test::list()
{
	int choice = 99;
	int value;
	int position;
	int number;
	std::string file_name;

	List list;
	Menu menu;

	list.read_from_file();

	std::cout << "Test Listy, wybierz co chcesz zrobic" << std::endl << std::endl;

	//Pocz¹tkowe menu wyboru
	while (choice != 0)
	{
		std::cout << "Wybierz test:" << std::endl;
		std::cout << "    1. Dodaj element na poczatek listy" << std::endl;
		std::cout << "    2. Dodaj element na koniec listy" << std::endl;
		std::cout << "    3. Dodaj element w dowolne miejsce listy" << std::endl;
		std::cout << "    4. Usun pierwszy element listy" << std::endl;
		std::cout << "    5. Usun ostatni element listy" << std::endl;
		std::cout << "    6. Usun dowolny element listy" << std::endl;
		std::cout << "    7. Wyszukaj element listy" << std::endl;
		std::cout << "    8. Wyswietl liste" << std::endl;
		std::cout << "    9. Powrot" << std::endl;
		std::cout << "    0. Wyjscie" << std::endl;
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
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			list.push_begining(value);
			list.show_list();
			break;

		case 2:
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			list.push_end(value);
			list.show_list();
			break;

		case 3:
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			std::cout << "Podaj pozycje: " << std::endl;
			std::cin >> position;
			list.push(value, position);
			list.show_list();
			break;

		case 4:
			list.pop_begining();
			list.show_list();
			break;

		case 5:
			list.pop_end();
			list.show_list();
			break;

		case 6:
			std::cout << "Podaj pozycje: " << std::endl;
			std::cin >> position;
			list.pop(position);
			list.show_list();
			break;

		case 7:
			std::cout << "Podaj liczbe ktora chcesz wysukac: " << std::endl;
			std::cin >> number;
			list.search(number);
			break;

		case 8:
			list.show_list();
			break;

		case 9:
			menu.menu();
			break;
		}
	}
}

void Test::heap()
{
	int choice = 99;
	int value;
	int number;

	Heap heap;
	Menu menu;

	heap.read_from_file();

	std::cout << "Test Kopca, wybierz co chcesz zrobic" << std::endl << std::endl;

	//Pocz¹tkowe menu wyboru
	while (choice != 0)
	{
		std::cout << "Wybierz test:" << std::endl;
		std::cout << "    1. Dodaj element do kopca" << std::endl;
		std::cout << "    2. Usun korzen" << std::endl;
		std::cout << "    3. Wyszukaj element w kopcu" << std::endl;
		std::cout << "    4. Wyswietl kopiec" << std::endl;
		std::cout << "    5. Powrot" << std::endl;
		std::cout << "    0. Wyjscie" << std::endl;
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
			std::cout << "Podaj wartosc: " << std::endl;
			std::cin >> value;
			heap.push(value);
			heap.show_heap("", "", 0);
			break;

		case 2:
			heap.pop();
			heap.show_heap("", "", 0);
			break;

		case 3:
			std::cout << "Podaj liczbe ktora chcesz wyszukac: " << std::endl;
			std::cin >> number;
			heap.search(number);
			break;

		case 4:
			std::cout << "Kopiec: " << std::endl;
			heap.show_heap("", "", 0);
			break;

		case 5:
			menu.menu();
			break;
		}
	}
}