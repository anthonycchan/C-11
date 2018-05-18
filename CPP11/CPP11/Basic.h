#include <iostream>
#include <initializer_list>

class Basic
{
public:
	Basic() {}
	void run();
	void initListSampleMethod(std::initializer_list<int> list);
};

class sampleClass
{
public:
	sampleClass() { }

	// Initializer list constructor
	sampleClass(std::initializer_list<int> list)
	{
		for (auto i : list)
			std:: cout << i << std::endl;
	}

	auto getDouble() -> double
	{
		return 3.14;
	}

	template<class T>
	auto neg(T &&t) ->decltype(t)
	{
		return -t;
	}
};

