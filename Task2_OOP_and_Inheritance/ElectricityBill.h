/*
Name: Aaron Colin Foote
Date: 8th May 2013
User: acf502, 4258770
File Description: ElectricityBill.h for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __EBILL_H_
#define __EBILL_H_

#include "Bill.h"

class ElectricityBill : public Bill
{
	private:
		int previousReading;
		int currentReading;
		static float rate1;
		static int rate1Threshold;
		static float rate2;
		static float supplyCharge;
		ElectricityBill *next;
	public:
		ElectricityBill();
		~ElectricityBill();
		void Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int pReading, int cReading, bool recalc);
		void calc();	//Calculate total amount due and GST
		void SetNext(ElectricityBill *aNext) { next = aNext; };
		ElectricityBill *Next() { return next; };		
		void Output(string fname);
		void SetElec(float r1, int r1Threshold, float r2, float sCharge);
		void Print();
};

class EList {

	private:
		ElectricityBill *head;
	public:
		EList() { head = NULL; };
		~EList();
		int SaveEList(string fname);
		int LoadEList(string fname);
		void EAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int pReading, int cReading);
		void ChangeElec();
};

#endif
