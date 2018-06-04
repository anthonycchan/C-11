class NewTypes
{
	// Bitfields
	struct Header
	{
		unsigned int version : 4;
		int protocol : 4;
		int flags : 4;
		bool isValid : 1;
		bool isGlobal : 1;
		int : 8;  // reserve for future use
	};

public:
	NewTypes() {}
	void run();

	void unorderedMap();
	void unorderedSet();
	void bitFields();
	void bitSet();
	void pairTest();
	void dequeTest();
	void multimapTest();
	void multisetTest();
	void arrayTest();
	void priorityQueue();
	void stringStream();
	void numericLiterals();
};