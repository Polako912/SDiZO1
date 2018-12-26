#pragma once

class List
{
private:
	List *head, *tail, *prev, *next;
	int list_size, data;

public:
	List();
	~List();

	void push_begining(int value);
	void push_end(int value);
	void push(int value, int position);

	void pop_begining();
	void pop_end();
	void pop(int position);

	void show_list();

	void search(int number);

	void read_from_file();

	void clearList();
};
