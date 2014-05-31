/*
Name: Aaron Colin Foote
Date: 8th May 2013
User: acf502, 4258770
File Description: Bill.cpp for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#include "Bill.h"

istream& operator>>(istream &in,Bill &bill)	//operator works but is unused in program
{
	cout << "Biller name: ";			//1. prompt char pointer input
	if (bill.billerName != NULL)			//if variable contains data
		delete []bill.billerName;			//delete to free space
	bill.billerName = new char[MAXLENGTH];		//re-allocate memory
	in.getline(bill.billerName,MAXLENGTH);		//store data in memory
		delete []bill.billerName;

	cout << "Biller code: ";	//2. input integer, ignore leftover '\n'
	in >> bill.billerCode;
	in.ignore();

	cout << "Reference: ";				//Repeat of step 1
	if (bill.referenceNumber != NULL)
		delete []bill.referenceNumber;
	bill.referenceNumber = new char[MAXLENGTH];
	in.getline(bill.referenceNumber,MAXLENGTH);
		delete []bill.referenceNumber;

	cout << "Account number: ";	//Repeat of step 2
	in >> bill.accountNumber;
	in.ignore();

	cout << "Account name: ";		//1.
	if (bill.accountName != NULL)
		delete []bill.accountName;
	bill.accountName = new char[MAXLENGTH];
	in.getline(bill.accountName,MAXLENGTH);
		delete []bill.accountName;

	cout << "Address: ";			//1.
	if (bill.address != NULL)
		delete []bill.address;
	bill.address = new char[MAXLENGTH];
	in.getline(bill.address,MAXLENGTH);
		delete []bill.address;

	cout << "Start date: ";			//Fill Date structures
	in >> bill.periodStartDate.day >> bill.periodStartDate.month >> bill.periodStartDate.year;

	cout << "End date: ";
	in >> bill.periodEndDate.day >> bill.periodEndDate.month >> bill.periodEndDate.year;

	cout << "Due date: ";
	in >> bill.dueDate.day >> bill.dueDate.month >> bill.dueDate.year;

	return in;
}

Bill::Bill(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date dDate, Date pSDate, Date pEDate)
{
	billerName = new char[MAXLENGTH];	//set memory aside for char * variables and assign all variables to passed values
		billerName = bName;
	billerCode = bCode;
	referenceNumber = new char[MAXLENGTH];
		referenceNumber = rNumber;
	accountNumber = aNumber;
	accountName = new char[MAXLENGTH];
		accountName = aName;
	address = new char[MAXLENGTH];
		address = add;	
	amountDue = aDue;
	totalGST = tGST;
	dueDate.day = dDate.day;
	dueDate.month = dDate.month;
	dueDate.year = dDate.year;
	periodStartDate.day = pSDate.day;
	periodStartDate.month = pSDate.month;
	periodStartDate.year = pSDate.year;
	periodEndDate.day = pEDate.day;
	periodEndDate.month = pEDate.month;
	periodEndDate.year = pEDate.year;
}
Bill::Bill()	//set all variables to value of 0
{
	billerCode = 0;
	accountNumber = 0;
	amountDue = 0;
	totalGST = 0;
	dueDate.day = 0;
	dueDate.month = 0;
	dueDate.year = 0;
	periodStartDate.day = 0;
	periodStartDate.month = 0;
	periodStartDate.year = 0;
	periodEndDate.day = 0;
	periodEndDate.month = 0;
	periodEndDate.year = 0;
}
Bill::~Bill()
{
/*	if (billerName != NULL)		//unsure why this would cause segmentation faults on program close
	{
		delete []billerName;	//variables are checked for values and deleted if so
		billerName = NULL;
	}
	if (referenceNumber != NULL)
	{
		delete []referenceNumber;
		referenceNumber = NULL;
	}
	if (accountName != NULL)
	{
		delete []accountName;
		accountName = NULL;
	}
	if (address != NULL)
	{
		delete []address;
		address = NULL:
	}*/
		billerCode = 0;
		accountNumber = 0;
		amountDue = 0;
		totalGST = 0;
		dueDate.day = 0;
		dueDate.month = 0;
		dueDate.year = 0;
		periodStartDate.day = 0;
		periodStartDate.month = 0;
		periodStartDate.year = 0;
		periodEndDate.day = 0;
		periodEndDate.month = 0;
		periodEndDate.year = 0;
}
