/*
Name: Aaron Colin Foote
Date: 24th May 2013
User: acf502 / 4258770
File.: task3Main.cpp for Assignment 3 of CSCI204
*/

#include "MyList.h"

int main()
{
	ListOneTwo();
	ListThree();
	return 0;
}

void ListOneTwo()	//int list 1 and 2
{

	//First list (push_front())

	MyList<int> intlist, intlist2;
	int intval, intListSiz;

	MyList<int>::iterator it;
	cout << "Input number of integers:";
	cin >> intListSiz;
	numCheck<int>(intListSiz);
	while (intListSiz < 2)
	{
		numRepeat(intListSiz);
	}
	cout << "Input " << intListSiz << " integers:";
	for (int i = 0; i < intListSiz; i++)
	{
		cin >> intval;
		numCheck<int>(intval);
		intlist.push_front(intval);
	}
	cout << "Integer list 1 (push_front(), loop by using iterator):" << endl;
	for (it = intlist.begin(); it != intlist.end(); it++)
	{
		cout << it;
	}
	cout << "\n\n\n";


	//Second list

	int intval2, intListSiz2;
	MyList<int>::iterator it2;

	cout << "Input number of integers:";
	cin >> intListSiz2;
	numCheck<int>(intListSiz2);
	while (intListSiz2 < 2)
	{
		numRepeat(intListSiz2);
	}
	cout << "Input " << intListSiz2 << " integers:";
	for (int i = 0; i < intListSiz2; i++)
	{
		cin >> intval2;
		numCheck<int>(intval2);
		intlist2.push_back(intval2);
	}
	cout << "Integer list 2 (push_back(), loop by using iterator):" << endl;
	if (intListSiz2 > 1)
	{
		for (it2 = ++(++(intlist2.begin())); it2 != ++(++((intlist2.end()))); it2++)
		{
			cout << it2;
		}
	}
	else
		cout << intlist2.front();
	cout << "\n\n\n";


	if (intListSiz == intListSiz2)
	{
		intlist2 = intlist;			
		cout << "Integer list 2 = list 1 (loop by using use front() and pop_front():" << endl;
		for (int i = 0; i < intListSiz; i++)
		{
			cout << intlist2.front() << " ";
			if ((intListSiz - i) > 1)
				intlist2.pop_front();
		}
		cout << "\n\n";	
	}
	else
	{
		cout << "int lists are not of equal size, can not perform 'list 2 = list 1'\n\n";
	}
	
}

void ListThree()	//double list
{
	//Third list (push_front())

	MyList<double> doblist;
	double dobval, dobListSiz;

	MyList<double>::iterator it;
	cout << "Input number of doubles:";
	cin >> dobListSiz;
	numCheck<double>(dobListSiz);
	while (dobListSiz < 2)
	{
		numRepeat(dobListSiz);
	}
	cout << "Input " << dobListSiz << " doubles:";
	for (double i = 0; i < dobListSiz; i++)
	{
		cin >> dobval;
		numCheck<double>(dobval);
		doblist.push_back(dobval);
	}
	cout << "Double list 1 (loop by using iterator):" << endl;
	if (dobListSiz > 1)
	{
		for (it = ++(++(doblist.begin())); it != ++(++((doblist.end()))); it++)
		{
			cout << it;
		}
	}
	else
		cout << doblist.front();
	cout << "\n\n\n";

}
