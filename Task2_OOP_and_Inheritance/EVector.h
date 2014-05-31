/*
Name: Aaron Colin Foote
Date: 2nd May 2013
User: acf502, 4258770
File Description: EVector.h for task 1 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __EVECTOR_H_
#define __EVECTOR_H_

#include <iostream>
#include <string>

using namespace std;

const char msg[] = "Error: Size of Euclidean Vectors in operation is not equivalent!";	//Standard error for inequivalent vector sizes

class EVector {
	friend ostream& operator<<(ostream &, const EVector &);	// Extraction operator overload
	friend istream& operator>>(istream &, EVector &);	// Insertion operator overload
	private:
		int size;
		double *vector;
	public:
		EVector();
		~EVector();
		EVector operator=(const EVector &);				// Copy constructor overload
		EVector operator+(const EVector &);				// Addition operator overload
		EVector operator-(const EVector &);				// Subtraction operator overload
		EVector operator*(const EVector &);				// Inner product operator overload
		friend EVector operator*(double, const EVector &);			// Multiplication operator overload (double * vector)
		friend EVector operator*(const EVector &, double);			// Multiplication operator overload (vector * double)
		friend EVector operator/(const EVector &, double);			// Division operator overload
};

#endif
