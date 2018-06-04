#include "Iterators.h"
#include <iostream>
#include <list>
#include <deque>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

void Iterators::run()
{
	cout << "\n\n##### Iterators #####" << endl;

	inserts();
	copyMove();
}

void Iterators::inserts()
{
	cout << "Front and Back inserter" << endl;

	list<int> v{ 1, 2, 3, 4, 5 };
	deque<int> dq{ 1, 2, 3, 4, 5 };
	
	for (int i = 6; i <= 10; i++) {
		back_inserter(v) = i;
		back_inserter(dq) = i;
	}

	for (int i = 0; i >= -5; i--) {
		front_inserter(v) = i;
		front_inserter(dq) = i;
	}

	for (const auto i : v)
		cout << i << " ";
	cout << endl;
	for (const auto i : dq)
		cout << i << " ";
}

void Iterators::copyMove()
{
	cout << "\n\nCopy and move" << endl;

	vector<string> vec{ "one", "two", "three", "four", "five" };
	vector<string> vec2, vec3;

	copy(vec.begin(), vec.end(), back_inserter(vec2));

	cout << "vec2: ";
	for (string str : vec2)
		cout << str << ' ';

	vec3 = move(vec2);

	cout << endl;
	cout << "vec3: ";
	for (string str : vec3)
		cout << str << ' ';

	cout << endl;
	cout << "vec2: ";
	for (string str : vec2)
		cout << str << ' ';

	vector<string> vec4(make_move_iterator(vec3.begin()), make_move_iterator(vec3.end()) );
	cout << endl;
	cout << "vec4: ";
	for (string str : vec4)
		cout << str << ' ';

	cout << endl;
	cout << "vec3: ";
	for (string str : vec3)
		cout << str << ' ';
}