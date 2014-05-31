/*
Name: Aaron Colin Foote
Date: 10th May 2013
User: acf502, 4258770
File Description: Bill.h for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __BILL_H_
#define __BILL_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

const MAXLENGTH = 80;

struct Date	//Simplification of dates held in bill class
		{
			int day;
			int month;
			int year;
		};

class Bill{
	friend istream& operator>>(istream &,Bill &);
	protected:
		char *billerName;
		int billerCode;
		char *referenceNumber;
		long accountNumber;
		char *accountName;
		char *address;
		float amountDue;
		float totalGST;
		Date dueDate;
		Date periodStartDate;
		Date periodEndDate;
	public:
		Bill();		//Initialise all values to 0 or ""
		Bill(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date dDate, Date pSDate, Date pEDate);
		~Bill();	//Deletes all character pointer arrays
};

#endif
