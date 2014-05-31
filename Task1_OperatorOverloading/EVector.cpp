/*
Name: Aaron Colin Foote
Date: 2nd May 2013
User: acf502, 4258770
File Description: EVector.cpp for task 1 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/
#include "EVector.h"

// Extraction operator overload

ostream& operator<<(ostream &out, const EVector &EV)
{
	cout << "(";
	for (int i = 0; i < EV.size; i++)	//Print 'size' total of values
	{
		cout << EV.vector[i];
		if (i < (EV.size-1))		//If more values still to be printed, print comma
			cout << ", ";
	}
	cout << ")";
	return out;
}

// Insertion operator overload

istream& operator>>(istream &in, EVector &EV)
{
	bool test = false;		//Determines whether Vector value should be re-entered
	in >> EV.size;
	delete []EV.vector;
	const int SIZE = EV.size;	//Set size of new vector
	EV.vector = new double[SIZE];
	for (int i = 0; i < SIZE; i++)	//User enters values in vector
	{
		test = true;
		while (test == true)
		{
			try
			{
				in >> EV.vector[i];
				string type = typeid(EV.vector[i]).name();	//find type of value entered by user
				if ( type != "double")				//if not double, throw error
					throw "Must enter a double value!";
				else
					test = false;
			}
			catch (const char *errmsg)	//error caught, message displayed, repeat loop for new vector value
			{
				cout << errmsg << endl;
			}
			in.ignore();	//ignore extra numeric characters
		}
	}
	return in;
}

EVector::EVector()
{
	size = 0;
	vector = NULL;
}
EVector::~EVector()
{
	delete []vector;
	size = 0;
}

// Copy constructor overload

EVector EVector::operator=(const EVector &ev)
{
	if (vector != NULL)
		delete []vector;
	size = ev.size;					//Get size of new Vector, create memory
	vector = new double[size];
	for (int i = 0; i < size; i++)		//Set new vectors value's to values of passed vector, in loop
		vector[i] = ev.vector[i];
	return *this;	
}

// Addition operator overload

EVector EVector::operator+(const EVector &ev)
{
	EVector tmp;					//Prepare temporary EVector to return to main
	if (size != ev.size)				//If vector size does not match, throw error msg
	{
		throw msg;
	}
	else
	{
		tmp.size = size;			//Get size of new Vector, create memory
		tmp.vector = new double[tmp.size];
		for (int i=0; i<tmp.size; i++)		//Set new vectors value's to the added values of passed vectors, in loop
		{
			tmp.vector[i] = vector[i] + ev.vector[i];
		}
		
		return tmp;
	}
}

// Subtraction operator overload

EVector EVector::operator-(const EVector &ev)
{
	EVector tmp;					//Prepare temporary EVector to return to main
	if (size != ev.size)				//If vector size does not match, throw error msg
	{
		throw msg;
	}
	else
	{
		tmp.size = size;			//Get size of new Vector, create memory
		tmp.vector = new double[tmp.size];
		for (int i=0; i<tmp.size; i++)		//Set new vectors value's to the subtracted values of passed vectors, in loop
		{
			tmp.vector[i] = vector[i] - ev.vector[i];
		}
		
		return tmp;
	}
}

// Inner product operator overload

EVector EVector::operator*(const EVector &ev)
{
	EVector tmp;					//Prepare temporary EVector to return to main
	if (size != ev.size)				//If vector size does not match, throw error msg
	{
		throw msg;
	}
	else
	{
		tmp.size = 1;				//Get size of new Vector (since there is only 1 end value, use 1), create memory
		tmp.vector = new double[tmp.size];
		tmp.vector[0] = 0;			//Default the single value to 0
		for (int i = 0; i < size; i++)		//Set new vectors value's to the multiplied values of passed vectors, in loop
		{
			tmp.vector[0] += vector[i] * ev.vector[i];
		}
		return tmp;
	}
}

// Multiplication operator overload (vector * double)

EVector operator*(double num, const EVector &ev)
{
	EVector tmp;					//Prepare temporary EVector to return to main

	tmp.size = ev.size;				//Get size of new Vector, create memory
	tmp.vector = new double[tmp.size];
	for (int i = 0; i < tmp.size; i++)		//Set new vectors value's to the value of each vector element multiplied by passed value, in loop
	{
		tmp.vector[i] = ev.vector[i] * num;
	}
	return tmp;
}

// Multiplication operator overload (double * vector)

EVector operator*(const EVector &ev, double num)
{
	EVector tmp;					//Prepare temporary EVector to return to main

	tmp.size = ev.size;				//Get size of new Vector, create memory
	tmp.vector = new double[tmp.size];
	for (int i = 0; i < tmp.size; i++)
	{
		tmp.vector[i] = ev.vector[i] * num;	//Set new vectors value's to the value of each vector element multiplied by passed value, in loop
	}
	return tmp;
}

// Division operator overload

EVector operator/(const EVector &ev, double num)
{
	EVector tmp;					//Prepare temporary EVector to return to main
	tmp.size = ev.size;				//Get size of new Vector, create memory
	tmp.vector = new double[tmp.size];
	
	if (num == 0)		//Check for division by zero, as a safeguard
	{
		cout << "\nDivision by zero NOT permitted! Program will now divide by 1 instead" << endl;
		num = 1;
	}
	for (int i = 0; i < tmp.size; i++)
	{
		tmp.vector[i] = ev.vector[i] / num;	//Set new vectors value's to the value of each vector element divided by passed value, in loop
	}
	return tmp;
}
