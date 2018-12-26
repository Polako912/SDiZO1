#include <iostream>
#include "Heap.h"
#include <fstream>
#include <string>

//konstruktor
Heap::Heap()
{
	this->array = nullptr;
	this->heap_size = 0;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

//destruktor
Heap::~Heap()
{
	if (this->heap_size > 0)
	{
		delete[] this->array;
	}
}

//dodanie elementu do kopca
void Heap::push(int value)
{
	int *pom = new int[this->heap_size + 1];

	for (int i = 0; i < this->heap_size; i++)
	{
		pom[i] = this->array[i];
	}

	if (this->heap_size == 0)
	{
		delete this->array;
	}
	else
		delete[] this->array;

	this->array = pom;

	int i = this->heap_size;
	int j = (i - 1) / 2;

	while (i > 0 && this->array[j] < value)
	{
		this->array[i] = this->array[j];
		i = j;
		j = (i - 1) / 2;
	}

	this->array[i] = value;
	this->heap_size++;
}

//usuwanie korzenia
void Heap::pop()
{
	if (heap_size > 0)
	{
		if (this->heap_size == 1)
		{
			int *temp = new int;
			delete[] this->array;
			this->array = temp;
			this->heap_size = 0;
		}
		else
		{
			this->array[0] = this->array[this->heap_size - 1];

			int *pom = new int[this->heap_size - 1];

			for (int i = 0; i < this->heap_size - 1; i++)
			{
				pom[i] = this->array[i];
			}

			delete[] this->array;
			this->array = pom;
			this->heap_size--;
		}

		if (this->heap_size - 1)
		{
			int v = this->array[0];
			int i = 0, j = 1;

			while (j < this->heap_size)
			{
				if (j + 1 < this->heap_size && this->array[j + 1] > this->array[j])
					j++;

				if (v >= this->array[j])
					break;

				this->array[i] = this->array[j];

				i = j;
				j = 2 * j + 1;
			}

			this->array[i] = v;
		}
	}
	else
		std::cout << "Kopiec jest pusty" << std::endl;
}

//wypisanie kopca w formie drzewa
void Heap::show_heap(std::string sp, std::string sn, int v)
{
	std::string s;

	if (v < heap_size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		show_heap(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << array[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		show_heap(s + cp, cl, 2 * v + 1);
	}
}

//odczyt z pliku
void Heap::read_from_file()
{
	std::fstream file;

	int data = 0;
	 
	file.open("data.txt", std::ios::in);

	if (file.good() == true)
	{
		while (!file.eof())
		{
			file >> data;
			push(data);
		}
		file.close();
	}
}

//wyszukanie elementu
void Heap::search(int number)
{
	if (array == nullptr)
	{
		std::cout << "Kopiec jest pusty" << std::endl;
	}

	for (int i = 0; i < heap_size; i++)
	{
		if (this->array[i] == number)
		{
			std::cout << "Szukana wartosc znajduje sie w kopcu" << std::endl;
		}
	}
}

//czyszczenie kopca
void Heap::clearHeap()
{
	for(int i = 0; i < heap_size; i++)
	{
		array[i] = NULL;
	}

	heap_size = 0;
}