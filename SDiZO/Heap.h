#pragma once

class Heap
{
private:
	int *array;
	unsigned int heap_size;
	std::string cr, cl, cp;

public:
	Heap();
	~Heap();

	void push(int value);
	void pop();

	void show_heap(std::string sp, std::string sn, int v);

	void read_from_file();

	void search(int number);

	void clearHeap();
};