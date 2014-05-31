/*
Name: Aaron Colin Foote
Date: 8th May 2013
User: acf502, 4258770
File Description: TelephoneBill.h for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __TBILL_H_
#define __TBILL_H_

#include "Bill.h"

class TelephoneBill : public Bill
{
	private:
		int numberOfLocalCalls;
		float localCallRate;
		float internationalCallAmount;
		float lineRental;
		int internetConnection;
		TelephoneBill *next;
	public:
		TelephoneBill();
		~TelephoneBill();
		void Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int lCalls, float iCalls, bool recalc);
		void calc();	//Calculate total amount due and GST
		void SetNext(TelephoneBill *aNext) { next = aNext; };
		TelephoneBill *Next() { return next; };		
		void Output(string fname);
		void Print();
};

class TList {

	private:
		TelephoneBill *head;
	public:
		TList() { head = NULL; };
		~TList();
		int SaveTList(string fname);
		int LoadTList(string fname);
		void TAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int lCalls, float iCalls);
};

#endif
