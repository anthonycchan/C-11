#include "Basic.h"
#include <vector>

using namespace std;

void Basic::run()
{
	//
	// auto keyword
	//
	int i = 0;
	auto j = i;

	//
	// nullptr literal
	//
	int *ptri = nullptr;

	//
	// initializer list
	//
	vector<int> vecOfInts1{ 1 };
	vector<int> vecOfInts2 = { 1 };  // same as vector above
	vector<int> vecOfInts3(1); // one element vector with default 0

	cout << "size: " << vecOfInts1.size() << " value: " << vecOfInts1[0] << std::endl;
	cout << "size: " << vecOfInts2.size() << " value: " << vecOfInts2[0] << std::endl;
	cout << "size: " << vecOfInts3.size() << " value: " << vecOfInts3[0] << std::endl;

	sampleClass c1();
	sampleClass c2{ 1, 2 };
	initListSampleMethod({ 3, 2, 1 });

	//
	// suppress exceptions
	//
	int *newInt = new int;
	delete newInt;

	int *newNoThrowInt = new(nothrow) int();  // returns nullptr if allocation fails
	if (newNoThrowInt == nullptr)
	{
		cout << "allocation failed\n";
		return;
	}

	delete(nothrow, newNoThrowInt);

	char *c = new(nothrow) char[100];  // returns nullptr if allocation fails
	if (c == nullptr)
	{
		cout << "allocation failed\n";
		return;
	}
	delete[](nothrow, c);

	//
	// Return type using suffix notation
	//
	sampleClass c4;
	cout << "\nnegate: " << c4.neg(1);
	cout << "\ngetDouble: " << c4.neg(c4.getDouble());
}

void Basic::initListSampleMethod(initializer_list<int> list)
{
	for (auto i : list)
		cout << i << ", ";
}
