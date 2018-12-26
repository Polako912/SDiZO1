#include "List.h"
#include <iostream>
#include <fstream>

//konstruktor
List::List()
{
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}

//destruktor
List::~List()
{
	List *new_pointer = nullptr;

	if (head != nullptr)
	{
		while (new_pointer != nullptr)
		{
			new_pointer = new_pointer->next;
			delete new_pointer;
		}
	}
}

//dodanie elemntu na poacz¹tek listy
void List::push_begining(int value)
{
	List *new_elem = new List;

	new_elem->data = value;
	new_elem->prev = nullptr;
	new_elem->next = head;

	if (head != NULL)
	{
		head->prev = new_elem;
	}
	else
	{
		tail = new_elem;
	}
	head = new_elem;
	list_size++;
}

//dodanie elementu na koniec listy
void List::push_end(int value)
{
	List *new_elem = new List;

	new_elem->data = value;
	new_elem->next = nullptr;
	new_elem->prev = tail;

	if (new_elem->prev)
	{
		new_elem->prev->next = new_elem;
	}
	else
	{
		head = new_elem;
	}
	tail = new_elem;
	list_size++;
}

//dodanie elementu w dowolne miejsce
void List::push(int value, int position)
{
	List *new_elem = this->head;
	List *elem = new List;

	if (position <= list_size - 1 && position >= 0)
	{
		if (position == this->list_size - 1)
		{
			push_end(value);
			return;
		}
		if (position == 0)
		{
			push_begining(value);
			return;
		}
		else
		{
			for (int i = 0; i < position - 1; i++)
			{
				new_elem = new_elem->next;
			}
		}

		elem->data = value;
		elem->next = new_elem->next;
		elem->prev = new_elem;
		new_elem->next = elem;
		new_elem->next->prev = elem;
		list_size++;
	}
	else
		std::cout << "Zly zakres" << std::endl;
}

//usuniêcie pierwszego element listy
void List::pop_begining()
{
	List *new_elem = new List;
	if (head != NULL)
	{

		new_elem = head->next;
		delete head;

		if (list_size > 1)
		{
			new_elem->prev = nullptr;
			head = new_elem;
		}
		else
		{
			new_elem = nullptr;
			head = nullptr;
			tail = nullptr;
		}

		list_size--;
	}
}

//usuniêcie ostatniego elementu listy
void List::pop_end()
{
	List *new_elem = new List;
	if (head != NULL)
	{
		new_elem = tail->prev;
		delete tail;

		if (list_size > 1)
		{
			new_elem->next = nullptr;
			new_elem->prev->next = new_elem;
			tail = new_elem;
		}
		else
		{
			new_elem = nullptr;
			head = nullptr;
			tail = nullptr;
		}
		list_size--;
	}
}

//wypisanie listy
void List::show_list()
{
	List *new_elem = new List;
	new_elem = head;

	for (int i = 0; i < list_size; i++)
	{
		std::cout << " [" << i << "] " << new_elem->data << std::endl;
		
		new_elem = new_elem->next;
	}
	std::cout << std::endl;
}

//wyszukanie elementu w liœcie
void List::search(int number)
{
	if(head == nullptr)
	{
		std::cout << "Lista jest pusta" << std::endl;
	}

	List *new_elem = new List;
	new_elem = head;

	for (int i = 0; i < list_size; i++)
	{
		if (new_elem->data == number)
		{
			std::cout << "Szukana wartosc zajmuje w liscie [" << i << "] pozycje" << std::endl;
		}
		new_elem = new_elem->next;
	}
}

//odczyt z pliku
void List::read_from_file()
{
	std::fstream file;

	int data = 0;

	file.open("data.txt", std::ios::in);

	if (file.good() == true)
	{
		while (!file.eof())
		{
			file >> data;
			push_end(data);
		}
		file.close();
	}
}

//czyszczenie listy
void List::clearList()
{
	List *new_elem = head;

	while(new_elem)
	{
		List *next = new_elem->next;
		free(new_elem);
		new_elem = next;
	}
	list_size = 0;
	head = tail = NULL;
}

//usuniêcie dowolnego elementu
void List::pop(int position)
{
	List *p;
	if (this->head == nullptr)
	{
		std::cout << "Lista jest pusta. Nie ma co usuwac." << std::endl;
	}
	else {
		if (position == 0) pop_begining();
		else if (position == (this->list_size - 1)) pop_end();
		else if (position <= this->list_size / 2)
		{
			p = this->head;
			for (int i = 0; i < position; i++)
				p = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			this->list_size = this->list_size - 1;
		}
		else
		{
			p = this->tail;
			for (int i = (this->list_size - 1); i > position; i--)
				p = p->prev;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			this->list_size = this->list_size - 1;
		}
	}
}