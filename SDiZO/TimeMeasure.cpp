#include "TimeMeasure.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TimeMeasure::TimeMeasure()
{
	PCFreq = 0.0;
	CounterStart = 0;
}


TimeMeasure::~TimeMeasure()
{
}

double TimeMeasure::getCounter() const
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void TimeMeasure::startCounting()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

void TimeMeasure::generateStructure(int A, int B, int count)
{
	ofstream file;
	const string filename = "struct.txt";
	file.open(filename, ios::out);

	if (file.good())
	{
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				int liczba = rand() % (B - A + 1) + A;
				file << liczba;
			}
			else
			{
				int liczba = rand() % (B - A + 1) + A;
				file << liczba << endl;
			}
		}
	}

	file.close();
}

void TimeMeasure::saveToFile(vector<double> &czasy)
{
	ofstream file;
	const std::string filename = "time.txt";
	file.open(filename, std::ios::out);

	if (file.good())
	{
		for (int i = 0; i < czasy.size(); i++)
		{
			file << czasy[i] << endl;
		}
	}

	file.close();
}