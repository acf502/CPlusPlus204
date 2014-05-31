/*
Name: Aaron Colin Foote
Date: 24th May 2013
User: acf502 / 4258770
File.: MyList.h for Assignment 3 of CSCI204
*/

#ifndef __MYLIST_H_
#define __MYLIST_H_

#include <iostream>
#include <cstdlib>

using namespace std;

void ListOneTwo();	//int lists
void ListThree();	//double list

template<class T>
void numCheck(T &value)
{
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input, please enter again" << endl;
		cin >> value;
	}
}

template<class T>
void numRepeat(T &val)
{
	cout << "List size too small! Must be 2 values or more!" << endl;
	cin >> val;
	numCheck<T>(val);
}

//Node class

template<class T>
class Node
{
	friend ostream& operator<<(ostream &out, const Node &n)
	{
		out << n.data;
		return out;
	}
	protected:
		T data;
		Node<T> *next;
		Node<T> *prev;
	public:
		Node();
		Node(T dt);
		~Node();
		void setData(T data);
    		T getData();
		void setNext(Node<T>* next);
		void setPrev(Node<T>* next);
		Node<T>* getNext()const;
		Node<T>* getPrev()const;

		friend class MyList<T>;

};

//MyList class

template<class T>
class MyList
{
	private:			//include node count?
		Node<T> *Head;
		Node<T> *Tail;
		int ListSize;
	public:

		class iterator;
		friend class iterator;
		MyList();
		~MyList();
		iterator begin(); // iterator to first element
		iterator end();
		const MyList& operator=(const MyList &L2)
		{
			Node<T> *ptr, *ptr2;
			ptr = Head;
			ptr2 = L2.Head;
			for (int i = 0; i < L2.ListSize; i++)
			{
				ptr->setData(ptr2->getData());
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
			return *this;
		}

		void push_front(T pFront);
		void push_back(T pBack);
		T front();
		void pop_front();
		int listSize();

		class iterator
		{
			friend ostream& operator<<(ostream &out, const iterator &it)
			{
				out << *it.curr << " ";
				return out;
			}
			protected:
				Node<T> *curr;
				T & retrieve() const; // retrieve the element refers to
				iterator(Node<T> *p); // protected constructor
			public:
				iterator();
				T & operator*();	//ONE OF THESE IS UNECESSARY!
				const T & operator*() const; // operator*() to return element

				iterator & operator++();
				iterator operator++(int);
				bool operator==(const iterator &rhs) const;
				bool operator!=(const iterator &rhs) const;
			friend class MyList<T>;
		};
};









//Node functions start
//Node initialisers
template<class T>
Node<T>::Node()
{
	next = NULL;
	prev = NULL;
}

template<class T>
Node<T>::Node(T dt)
{
	data = dt;
	next = NULL;
	prev = NULL;
}

template<class T>
Node<T>::~Node()
{
	next = NULL;
	prev = NULL;
}
//data touching
template<class T>
void Node<T>::setData(T Sdata)
{
	data = Sdata;
}

template<class T>
T Node<T>::getData()
{
	return data;
}

//set new next and prev node pointers

template<class T>
void Node<T>::setNext(Node<T>* Snext)
{
	next = Snext;
}

template<class T>
void Node<T>::setPrev(Node<T>* Sprev)
{
	prev = Sprev;
}

//get pointer to next or previous node

template<class T>
Node<T>* Node<T>::getNext()const///const can help complier to tell different function overloaded.
{
	return next;
}

template<class T>
Node<T>* Node<T>::getPrev()const
{
	return prev;
}









//MyList functions start
//Initialisations and data sets:

template<class T>
MyList<T>::MyList()
{
	ListSize = 0;
	Head = new Node<T>;
	Tail = new Node<T>;
	/*Head->setData(-999);
	Tail->setData(-999);*/
	Head->next = Tail;
	Tail->prev = Head;
}

template<class T>
MyList<T>::~MyList()
{
	while (Head->next != NULL && Head->next != Tail)
	{
		Node<T> *ptr;
		ptr = Head->next;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ListSize--;
		delete ptr;
	}
	delete Head;
	delete Tail;
}

template <class T>
typename MyList<T>::iterator MyList<T>::begin()
{ // iterator to first element
	if ( Head->next != NULL)
		return iterator( Head);
}

template <class T>
typename MyList<T>::iterator MyList<T>::end()
{ // iterator to first element
	if ( Head->next != NULL)
		return iterator( Tail->prev );
}

//pushes and pops:

template<class T>
void MyList<T>::push_front(T pFront)
{
	Node<T> *newNode = new Node<T>(pFront);
	if(Head == NULL && Tail == NULL)
	{
		Tail = Head = newNode;
	}
	else
	{
		Head->setPrev(newNode);
		newNode->setNext(Head);
		Head = newNode;
	}
	ListSize++;
}

template<class T>
void MyList<T>::push_back(T pBack)
{
	Node<T> *newNode = new Node<T>(pBack);
	if(Head == NULL && Tail == NULL)	//(Head->getData() == -999) for task1, originally
	{
		Head = Tail = newNode;
	}
	else
	{
		Tail->setNext(newNode);
		newNode->setPrev(Tail);
		Tail = newNode;
		Tail->setNext(NULL);
	}
	ListSize++;
}

template<class T>
void MyList<T>::pop_front()
{
	if(Head != NULL)
	{
		Node<T> *tmp = Head;
		Head = Head->next;
		if (Tail == tmp)
		{
			Tail = NULL;
		}
		else
		{
			Head->setPrev(NULL);
		}
		if (ListSize > 1)
			delete tmp;
		else
			Head->setData(NULL);	//-999 for task1, originally
		ListSize--;
	}
}

template<class T>
T MyList<T>::front()
{
	Node<T>* ptr = Head;
	return ptr->getData();
}

template<class T>
int MyList<T>::listSize()
{
	return ListSize;
}










//Iterator functions start:

template <class T>
MyList<T>::iterator::iterator()
{
	curr = NULL;	
}

template <class T>
MyList<T>::iterator::iterator(Node<T> *p)
{			// one-parameter constructor
			// Set current to the given node pointer p
	curr = p;
}

template <class T>
const T& MyList<T>::iterator::operator*() const
{				// returns a reference to the corresponding element in the list by calling retrieve() member function.
	return retrieve();
}

template <class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator++()
{
	curr = curr->next;
	return *this;
}

template <class T>
typename MyList<T>::iterator MyList<T>::iterator::operator++(int)
{
	iterator old = *this;
	++( *this );
	return old;
}

template <class T>
bool MyList<T>::iterator::operator==(const iterator &rhs) const
{
	return curr == rhs.curr;
}

template <class T>
bool MyList<T>::iterator::operator!=(const iterator &rhs) const
{
	return !( *this == rhs );
}

template <class T>
T& MyList<T>::iterator::retrieve() const
{						// return a reference to the corresponding element in the list.
	return curr->data;
}

#endif
