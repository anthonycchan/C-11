#include "Enumeration.h"
#include <iostream>

using namespace std;

void Enumeration::run()
{
	cout << "\n\n##### Enumeration #####" << endl;
	enumeration();
}

ostream& operator << (ostream& os, const Animals_t animal)
{
	if (animal == Animals_t::Cat)
		os << "Cat : ";

	os << static_cast< underlying_type<Animals_t>::type > (animal);
	return os;
}

void Enumeration::enumeration()
{
	Animals_t animal;

	animal = Animals_t::Cat;

	int animalIndx = static_cast<int>(animal);

	cout << static_cast<int>(animal) << " : " << animalIndx << endl;

	cout << animal << endl;
}