#include "NewTypes.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

void NewTypes::run()
{
	cout << "\n\n##### NewTypes #####" << endl;

	unorderedMap();
	unorderedSet();
	bitFields();
	bitSet();
	pairTest();
	dequeTest();
	multimapTest();
	multisetTest();
	arrayTest();
	priorityQueue();
	stringStream();
	numericLiterals();
}

void NewTypes::unorderedMap()
{
	// Unordered Map
	cout << "Unordered Map" << endl;

	unordered_map<string, int> grades{
		{ "Anthony", 100 },
		{ "Anthony2", 101 },
		{ "Anthony3", 102 }
	};

	// Update
	grades["Anthony2"] = 201;

	// Remove
	grades.erase("Anthony");

	for (const auto &iter : grades)
		cout << iter.first << " : " << iter.second << endl;

	// Every element is stored in a bucket. A bucket can have multiple elements
	cout << grades.bucket_count() << endl;   // Get the number of buckets
	size_t bucket = grades.bucket("Anthony3");  // Get the bucket for a specific key
	cout << "bucket: " << bucket << " size: " << grades.bucket_size(bucket) << endl;  // Get the number of elements in a bucket

	// Maximum average number of elements per bucket
	cout << grades.load_factor() << endl;
	cout << grades.bucket_count() << endl;

	grades.max_load_factor(0.7);
	grades.reserve(1000);  // Reserve space for specified number of elements

	// After resize
	cout << grades.load_factor() << endl;
	cout << grades.bucket_count() << endl;
}

void NewTypes::unorderedSet()
{
	cout << "\n\nUnordered Set" << endl;
	// Same as std set but unordered
	unordered_set<string> animals{ "dog", "cat", "fish", "bird" };

	for (const auto& a : animals)
		cout << a << endl;

	cout << "bucket count before: " << animals.bucket_count() << endl;
	animals.max_load_factor(0.7);
	animals.reserve(10000);
	cout << "bucket count after: " << animals.bucket_count() << endl;

	// underlying hashing
	unordered_set<string>::hasher hash = animals.hash_function();
	cout << "hash: " << hex << hash("dog") << endl;
}

void NewTypes::bitFields()
{
	cout << "\n\nBitfields" << endl;
	Header h;
	h.version = 15;  // Max value of version is 15. 4 bits (1111) = 15
	cout << dec << h.version;
}

void NewTypes::bitSet()
{
	cout << "\n\nBitsets" << endl;

	const int n = 4;
	bitset<n> b1;  //0000
	bitset<8> b2(7); //00000111
	cout << b2 << endl;

	cout << "Character binary substitution" << endl;
	bitset<4> b3("TFTF", 4, 'F', 'T');  // F = 0, T = 1
	bitset<4> b4("TTTH", 4, 'T', 'H');  // T = 0, H = 1
	cout << b3 << endl;
	cout << b4 << endl;

	cout << "Bitwise operation" << endl;
	bitset<4> b5(1);
	cout << (b1 | b5) << endl; // 0000 OR 0001 = 0001
	cout << (b1 ^ b5) << endl; // 0000 XOR 0001 = 0001
	cout << (b5 &= 0xF) << endl; // 0001 AND 1111 = 0001

	cout << "shifting" << endl;
	cout << (b1 >> 1) << endl; // 0001 >> 1 = 0000
	b1 = 5;
	cout << (b1 << 1) << endl; // 0101 << 1 = 1010
}

void NewTypes::pairTest()
{
	cout << "\n\nPair" << endl;
	pair<int, string> grade{ 100, "anthony" };
	cout << grade.first << " : " << grade.second << endl;

	auto p = make_pair(99, "ton");
	cout << p.first << " : " << p.second << endl;
	p.first++;
	cout << p.first << " : " << p.second << endl;

	vector<int> vect{ 2, 3, 4, 2, 1, 4, 6, 7, 2 };
	sort(vect.begin(), vect.end());
	auto range_pair = equal_range(vect.begin(), vect.end(), 2);  // vect must be sorted to work
	for (auto i = range_pair.first; i != range_pair.second; i++)
		cout << *i << endl;  // All occurance of 2 in vect
}

void NewTypes::dequeTest()
{
	cout << "\n\nDeque" << endl;
	deque<int> dq;
	dq.push_back(3);
	dq.push_back(1);
	dq.push_back(4);
	dq.push_back(-10);

	for_each (dq.begin(), dq.end(), [](int i) { cout << i << " "; } );  // 3 1 4 -10
	cout << endl;
	for_each(dq.rbegin(), dq.rend(), [](int i) { cout << i << " "; });  // -10 4 1 3

	cout << "\nPop back and front" << endl;
	dq.pop_back();  // 3 1 4
	dq.pop_front();  // 1 4
	cout << dq.front() << endl;  // 1
	cout << dq[0] << endl;  // 1
	cout << dq.back() << endl; // 4

	auto itr = dq.begin() + 1;
	cout << *itr << endl;  // 4 

	cout << "Invalidated iterator" << endl;
	dq.insert(itr, 2);  // 1 2 4  - itr is invalidated after insert!! WARNING!
	//dq.insert(itr, 99); // UNSAFE
	//int i = *itr;  //UNSAFE

	for_each(dq.begin(), dq.end(), [](int i) { cout << i << " "; });   // 1 2 4
	cout << endl;

	itr = dq.begin() + 1;
	dq.erase(itr);  // 1 4  itr invalidated  
	cout << "size: " << dq.size() << endl;

	for_each(dq.begin(), dq.end(), [](int i) { cout << i << " "; });   // 1 4
	cout << endl;

	cout << "max size: " << dq.max_size() << endl;  // how big can dq be?
}

void NewTypes::multimapTest()
{
	cout << "\n\nMultimap" << endl;

	multimap<int, string> mm;

	mm.insert(make_pair(100, "cat"));
	mm.insert(make_pair(99, "dog"));
	mm.insert(make_pair(98, "fish"));
	mm.insert(make_pair(99, "cow"));

	cout << mm.size() << endl;

	for (auto itr = mm.begin(); itr != mm.end(); itr++)
		cout << itr->first << " : " << itr->second << endl;

	cout << "Find" << endl;
	multimap<int, string>::iterator itr2 = mm.find(99);  // iterator to the first occurance of 99
	for (auto itr3 = itr2; itr3 != mm.end() && itr3->first == 99; itr3++)
		cout << itr3->first << " : " << itr3->second << endl;

	cout << "remove" << endl;
	mm.erase(99);
	for (auto itr = mm.begin(); itr != mm.end(); itr++)
		cout << itr->first << " : " << itr->second << endl;

	cout << mm.max_size() << endl;
}

void NewTypes::multisetTest()
{
	cout << "\n\nMultiset" << endl;
	multiset<int> ms;
	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);

	for (auto i : ms)
		cout << i << endl;
}

void NewTypes::arrayTest()
{
	cout << "\n\nArray" << endl;
	array<int, 5> ar = { 1, 2, 3, 4, 5 };

	ar.front();
	ar.back();
	ar.size();
	ar[0];
	ar[ar.size() - 1];

	for_each(ar.begin(), ar.end(), [](int i) { cout << i << endl; });

	cout << "pointer arithmetic" << endl;
	auto itr = ar.data();
	cout << *(itr + 2) << endl;
}

void NewTypes::priorityQueue()
{
	cout << "\n\nPriority queue" << endl;

	priority_queue < int, deque<int>, greater<int>> pq;
	pq.push(1);
	pq.push(5);
	pq.push(100);
	pq.push(50);
	pq.push(25);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

void NewTypes::stringStream()
{
	cout << "\n\nStringStream" << endl;

	stringstream ss;

	ss << 3.14159 << ' ' << 360;

	double rad, deg;
	ss >> rad >> deg;

	string str = ss.str();
	cout << rad << " : " << deg << " : " << str << endl;

	cout << "update" << endl;
	stringstream ss2;
	ss2.write("The quick brown fox.", 20);
	long p = ss2.tellp();
	ss2.seekp(p - 4);
	ss2.write("catt", 4);

	cout << ss2.str() << endl;

	cout << "string buffer" << endl;
	stringstream ss3;
	stringbuf *pbuf = ss3.rdbuf();  // Get the underlying buffer behind stringstream
	pbuf->sputn("Example string\0", 15);

	char buffer[80];
	pbuf->sgetn(buffer, 15);
	cout << buffer << endl;
}

void NewTypes::numericLiterals()
{
	cout << "\n\nNumericLiterals" << endl;

	unsigned int v0 = 100u;
	unsigned long v1 = 100ul;
	unsigned long long v2 = 100ull;
	long long v3 = 100ll;

	float v4 = 1.0f;
	double v5 = 1e2;  // 1 x 10 ^2
	double v6 = 1e-2; // 1 x 10 ^-2
	long double v7 = 1.2e-200L;

	cout << v7 << endl;

	cout << "hexadecimal and octal" << endl;

	unsigned long long v8 = 0xFF;
	unsigned int v9 = 010;

	cout << "hex: " << hex << v8 << " dec: " << dec << v8 << endl;
	cout << "oct: " << oct << v9 << " dec: " << dec << v9 << endl;
}