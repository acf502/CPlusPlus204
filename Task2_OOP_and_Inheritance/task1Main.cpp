/*
Name: Aaron Colin Foote
Date: 2nd May 2013
User: acf502, 4258770
File Description: task1Main.cpp for task 1 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __TASK1MAIN_CPP_
#define __TASK1MAIN_CPP_

#include "EVector.h"

int main()
{
	bool hide[3];	//Check for whether each operation should be shown, for first 3 operations (only these are concerned about matching vector size)
	for (int i = 0; i < 3; i++)
		hide[i] = false;
		
	EVector v1, v2, v3, v4;
	cout << "Input dimension and tuples for a Euclidean vector v1: ";	// Insert Vector into memory
	cin >> v1;
	cout << "Euclidean vector v1 = " << v1 << endl << endl;			//Output contents of Vector
	
	cout << "Input dimension and tuples for a Euclidean vector v2: ";	//Repeat for v2
	cin >> v2;
	cout << "Euclidean vector v2 = " << v2 << endl << endl;
	
	
	try	//Addition attempt
	{
		v3 = v1 + v2;
	}
	catch (const char *msg)	//Catch error message, defined in header
	{
		cout << msg;
		hide[0] = true;
	}
	if (hide[0] == false)	//Show results of addition, if sizes of v1 and v2 are the same
		cout << "v3 = v1 + v2 = " << v3 << endl <<endl;
	else
		cout << "\nv3 addition hidden" << endl;



	try	//Subtraction attempt, same checks but for subtraction
	{
		v3 = v1 - v2;
	}
	catch (const char *msg)
	{
		cout << msg;
		hide[1] = true;
	}
	if (hide[1] == false)
		cout << "v3 = v1 - v2 = " << v3 << endl << endl;
	else
		cout << "\nv3 subtraction hidden" << endl;
		
		
		
	try	//Multiplication attempt, same checks but for multiplication
	{
		v3 = v1 * v2;
	}
	catch (const char *msg)
	{
		cout << msg;
		hide[2] = true;
	}
	if (hide[2] == false)
		cout << "v3 = v1 * v2 = " << v3 << endl << endl;
	else
		cout << "\nv3 multiplication hidden" << endl;
	
	
	// Multiplication operator overload (double * vector)	
	
	double d = 0;
	cout << "Input a double value for d: ";
	cin >> d;
	
	cout << "d * v1 = " << d << " * " << v1 << " = ";
	v4  = d * v1;
	cout << v4 << endl << endl;
	
	// Multiplication operator overload (vector * double)
	
	cout << "v1 * d = " << v1 << " * " << d << " = ";
	v4  = v1 * d;
	cout << v4 << endl << endl;
	
	// Division operator overload
	
	cout << "v1 / d = " << v1 << " / " << d << " = ";
	v4  = v1 / d;
	cout << v4 << endl << endl;
	
	return 0;
	
}

#endif
