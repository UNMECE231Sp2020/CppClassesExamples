#include <iostream>

class IntList {
	private:
		struct _list {
			int value;
			struct _list *next;
		};
		typedef struct _list List;

		List *_front;
		List *_back;
		size_t _size;

		void reccopy(const List *ptr);

	public:
		//Constructors and destructors
		IntList();
		IntList(const IntList &List);
		~IntList();

		//Functions
		int front() const;
		int back() const;
		size_t size() const;
		void print();

		void add_frontnode(int data);
		void add_backnode(int data);

		void rm_frontnode();
		void rm_backnode();

		bool empty();
};

