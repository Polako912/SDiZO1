#pragma once
#include <vector>

class TimeMeasure
{
private:
	double PCFreq;
	__int64 CounterStart;
public:
	TimeMeasure();
	~TimeMeasure();
	double getCounter() const;
	void startCounting();
	static void generateStructure(int A, int B, int count);
	static void saveToFile(std::vector<double> &czasy);
};