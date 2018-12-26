#include "Array.h""
#include <iostream>
#include <fstream>

//konstruktor
Array::Array()
{
	head = nullptr;
	array_size = 0;
}

//destruktor
Array::~Array()
{
	if(head != nullptr)
	{
		delete[] head;
	}
}

//dodanie elementu na pocz¹tek tablicy
void Array::push_begining(int value)
{
	int *new_head = new int[array_size + 1];
	new_head[0] = value;

	for (int i=0; i<array_size; i++)
	{
		new_head[i + 1] = head[i];
	}

	delete head;
	head = new_head;

	array_size++;
}

//dodanie elementu na koniec tablicy
void Array::push_end(int value)
{
	int *new_head = new int[array_size + 1];
	new_head[array_size] = value;

	for (int i = 0; i<array_size; i++)
	{
		new_head[i] = head[i];
	}
	
	delete head;
	head = new_head;

	array_size++;
}

//dodanie elementu w dowolne miejsce
void Array::push(int value, int position)
{
	if (position < 0 || position > array_size)
	{
		std::cout << "Podana pozycja [" << position << "] nie istnieje w tablicy" << std::endl;
	}

	else
	{
		int *new_head = new int[array_size + 1];
		new_head[position] = value;

		for (int i = 0; i < position; i++)
		{
			new_head[i] = head[i];
		}

		for (int i = position; i < array_size; i++)
		{
			new_head[i + 1] = head[i];
		}

		delete head;
		head = new_head;

		array_size++;
	}
}

//usuwanie pierwszego elementu tablicy
void Array::pop_begining()
{
	if (array_size > 0)
	{
		int *new_head = new int[array_size - 1];

		for (int i = 0; i < array_size - 1; i++)
		{
			new_head[i] = head[i + 1];
		}

		delete head;
		head = new_head;

		array_size--;
	}
	else
	{
		std::cout << "Tablica jest pusta" << std::endl;
	}
}

//usuwanie ostatniego elementu tablicy
void Array::pop_end()
{
	if (array_size > 0)
	{
		int *new_head = new int[array_size - 1];

		for (int i = 0; i < this->array_size-1; i++)
		{
			new_head[i] = head[i];
		}

		delete head;
		head = new_head;

		array_size--;
	}
	else
	{
		std::cout << "Tablica jest pusta" << std::endl;
	}
}

//usuwanie dowolnego elementu
void Array::pop(int position)
{
	if (array_size > 0 && position >=0  && position < array_size)
	{
		int *new_head = new int[array_size - 1];

		if(position == 0)
		{
			pop_begining();
			return;
		}

		if(position == this->array_size -1)
		{
			pop_end();
			return;
		}

		for (int i = 0; i < position; i++)
		{
			new_head[i] = head[i];
		}

		for (int i = position; i < this->array_size - 1; i++)
		{
			new_head[i] = head[i + 1];
		}

		delete[] head;
		head = new_head;

		array_size--;
	}

	else
	{
		std::cout << "W tablicy nie ma podanej pozycji" << std::endl;
	}
}

//wypisanie tablicy
void Array::show_array()
{
	if (head != nullptr)
	{
		for (int i = 0; i < array_size; i++)
		{
			std::cout << "    [" << i << "] " << head[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Tablica jest pusta" << std::endl;
	}
	std::cout << std::endl;
}

//wyszukanie elementu
void Array::search(int number)
{
	if(head == nullptr)
	{
		std::cout << "Tablica jest pusta" << std::endl;
	}

	for(int i = 0; i < array_size; i++)
	{
		if (number == head[i])
		{
			std::cout << "Szukana wartosc zajmuje [" << i << "] pozycje" << std::endl;
		}
	}
}

//odczyt z pliku
void Array::read_from_file()
{
	std::fstream file;

	int data = 0;

	file.open("data.txt", std::ios::in);

	if(file.good() == true)
	{
		while(!file.eof())
		{
			file >> data;
			push_end(data);
		}
		file.close();
	}
}

//czyszczenie tablicy
void Array::clearArray()
{
	for(int i = 0; i< array_size; i++)
	{
		head[i] = NULL;
	}
	array_size = 0;
}
