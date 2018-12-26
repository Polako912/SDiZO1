#pragma once

class Array
{
private:
	int *head;
	int array_size;

public:

	Array();
	~Array();

	void push_begining(int value);
	void push_end(int value);
	void push(int value, int position);

	void pop_begining();
	void pop_end();
	void pop(int position);

	void show_array();

	void search(int number); 

	void read_from_file();

	void clearArray();
};
