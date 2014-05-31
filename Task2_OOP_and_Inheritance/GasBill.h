/*
Name: Aaron Colin Foote
Date: 8th May 2013
User: acf502, 4258770
File Description: GasBill.h for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __GBILL_H_
#define __GBILL_H_

#include "Bill.h"

class GasBill : public Bill
{
	private:
		float previousReading;
		float currentReading;
		static float heatingValue;
		static float pressureFactor;
		static float rate;
		static float supplyCharge;
		GasBill *next;
	public:
		GasBill();
		~GasBill();
		void Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, float pReading, float cReading, bool recalc);
		void calc();	//Calculate total amount due and GST
		void SetNext(GasBill *aNext) { next = aNext; };
		GasBill *Next() { return next; };		
		void Output(string fname);
		void SetGas(float hValue, float pFactor, float r, float sCharge);
		void Print();
};

class GList {

	private:
		GasBill *head;
	public:
		GList() { head = NULL; };
		~GList();
		int SaveGList(string fname);
		int LoadGList(string fname);
		void GAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, float pReading, float cReading);
		void ChangeGas();
};

#endif
