/*
Name: Aaron Colin Foote
Date: 10th May 2013
User: acf502, 4258770
File Description: task2Main.cpp for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#ifndef __TASK2MAIN_CPP_
#define __TASK2MAIN_CPP_

#include "GasBill.h"
#include "ElectricityBill.h"
#include "TelephoneBill.h"

bool menu(EList &, GList &, TList &);	//Base menu, bill lists passed by reference
void ElecInput(EList &EList);		//Menu selection 1
void GasInput(GList &GList);		//Menu selection 2
void TelInput(TList &TList);		//Menu selection 3
void SetElec(EList &EList);			//Menu selection 4
void SetGas(GList &GList);			//Menu selection 5
void Save(EList &EB, GList &GB, TList &TB);			//Menu selection 6
void Load(EList &EB, GList &GB, TList &TB);			//Menu selection 7

int main()
{
	EList EBills;	//Linked lists of bill types
	GList GBills;
	TList TBills;
	bool repeat = true;		//test for loop repetition of menu, program terminates when menu is finished
	do{
		if (! menu(EBills, GBills, TBills))		//when menu returns false (by entry of 0), the loop ends
		{
			repeat = false;
		}
	}while(repeat == true);
	return 0;
}

bool menu(EList &EList, GList &GList, TList &TList)
{
	int selection;
	cout << "1. Input electricity bill data;" << endl;	//menu
	cout << "2. Input gas bill data;" << endl;
	cout << "3. Input telephone bill data;" << endl;
	cout << "4. Set electricity rates;" << endl;
	cout << "5. Set gas rate;" << endl;
	cout << "6. Save bill data in a text file;" << endl;
	cout << "7. Load bill data from a text file;" << endl;
	cout << "0. Quit." << endl;
	cout << "Your choice: ";
	cin >> selection;
	cin.ignore();

	switch (selection)		//determine function to perform, based on menu selection
	{
		case 0:
			return false;
			break;
		case 1:
			ElecInput(EList);
			break;
		case 2:
			GasInput(GList);
			break;
		case 3:
			TelInput(TList);
			break;
		case 4:
			SetElec(EList);
			break;
		case 5:
			SetGas(GList);
			break;
		case 6:
			Save(EList, GList, TList);
			break;
		case 7:	
			Load(EList, GList, TList);
			break;

		default: cout << "Error in data entry, ensure you enter a digit that is between (inclusively) 0 and 7" << endl;
			cin.clear();
			cin.ignore(10000, '\n');	//protection against bad data entry
			return true;
	}
}
void ElecInput(EList &EList)	//Menu selection 1 still requires data entry
{
	char bName[MAXLENGTH], rNumber[MAXLENGTH], aName[MAXLENGTH], add[MAXLENGTH]; 	//tmp variables to set bill data
	int bCode ,pReading, cReading;
	long aNumber;
	float aDue, tGST;
	Date dDate, pSDate, pEDate;
	
	cout << "\nInput electricity bill data." << endl;	//all tmp variables filled

	cout << "Biller name: ";
	cin.getline(bName, MAXLENGTH);

	cout << "Biller code: ";	//input integer, ignore leftover '\n'
	cin >> bCode;
	cin.ignore();

	cout << "Reference: ";
	cin.getline(rNumber, MAXLENGTH);

	cout << "Account number: ";
	cin >> aNumber;
	cin.ignore();

	cout << "Account name: ";
	cin.getline(aName,MAXLENGTH);

	cout << "Address: ";
	cin.getline(add,MAXLENGTH);

	cout << "Start date: ";			//Fill Date structures
	cin >> pSDate.day >> pSDate.month >> pSDate.year;

	cout << "End date: ";
	cin >> pEDate.day >> pEDate.month >> pEDate.year;

	cout << "Due date: ";
	cin >> dDate.day >> dDate.month >> dDate.year;	
	
	cout << "Previous reading (kWh): ";
	cin >> pReading;
	cout << "Current reading (kWh): ";
	cin >> cReading;
	
	aDue = 0;
	tGST = 0;		//next line appends all given bill data to the end of bills list

	EList.EAppend(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, pReading, cReading);
}

void GasInput(GList &GList)	//same as ElecInput (previous function
{
	char bName[MAXLENGTH], rNumber[MAXLENGTH], aName[MAXLENGTH], add[MAXLENGTH]; 
	int bCode ,pReading, cReading;
	long aNumber;
	float aDue, tGST;
	Date dDate, pSDate, pEDate;
	
	cout << "\nInput gas bill data." << endl;

	cout << "Biller name: ";
	cin.getline(bName, MAXLENGTH);

	cout << "Biller code: ";	//input integer, ignore leftover '\n'
	cin >> bCode;
	cin.ignore();

	cout << "Reference: ";
	cin.getline(rNumber, MAXLENGTH);

	cout << "Account number: ";
	cin >> aNumber;
	cin.ignore();

	cout << "Account name: ";
	cin.getline(aName,MAXLENGTH);

	cout << "Address: ";
	cin.getline(add,MAXLENGTH);

	cout << "Start date: ";			//Fill Date structures
	cin >> pSDate.day >> pSDate.month >> pSDate.year;

	cout << "End date: ";
	cin >> pEDate.day >> pEDate.month >> pEDate.year;

	cout << "Due date: ";
	cin >> dDate.day >> dDate.month >> dDate.year;	
	
	cout << "Previous reading (Cubic meters): ";
	cin >> pReading;
	cout << "Current reading (Cubic meters): ";
	cin >> cReading;
	
	aDue = 0;
	tGST = 0;

	GList.GAppend(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, pReading, cReading);
}
void TelInput(TList &TList)	//same as ElecInput and GasInput, see above
{
	char bName[MAXLENGTH], rNumber[MAXLENGTH], aName[MAXLENGTH], add[MAXLENGTH]; 
	int bCode ,lCalls;
	long aNumber;
	float aDue, tGST, iCalls;
	Date dDate, pSDate, pEDate;
	
	cout << "\nInput telephone bill data." << endl;
	
	cout << "Biller name: ";
	cin.getline(bName, MAXLENGTH);

	cout << "Biller code: ";	//input integer, ignore leftover '\n'
	cin >> bCode;
	cin.ignore();

	cout << "Reference: ";
	cin.getline(rNumber, MAXLENGTH);

	cout << "Account number: ";
	cin >> aNumber;
	cin.ignore();

	cout << "Account name: ";
	cin.getline(aName,MAXLENGTH);

	cout << "Address: ";
	cin.getline(add,MAXLENGTH);

	cout << "Start date: ";			//Fill Date structures
	cin >> pSDate.day >> pSDate.month >> pSDate.year;

	cout << "End date: ";
	cin >> pEDate.day >> pEDate.month >> pEDate.year;

	cout << "Due date: ";
	cin >> dDate.day >> dDate.month >> dDate.year;	
	
	cout << "Number of local calls: ";
	cin >> lCalls;
	cout << "International calls: ";
	cin >> iCalls;
	
	aDue = 0;
	tGST = 0;

	TList.TAppend(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, lCalls, iCalls);
}
void SetElec(EList &EList)	//Menu selection 4 still requires fixing
{
	EList.ChangeElec();

}
void SetGas(GList &GList)	//Menu selection 5 still requires fixing
{
	GList.ChangeGas();

}
void Save(EList &EList, GList &GList, TList &TList)	//Menu selection 6
{
	int filecount = 0;	//counter of bills saved
	string filename;	//get filename from user
	cout << "Text file name: ";
	getline(cin, filename);
	filecount += EList.SaveEList(filename);	//save lists to file
	filecount += GList.SaveGList(filename);
	filecount += TList.SaveTList(filename);
	cout << filecount << " bills have been saved.\n\n";

}
void Load(EList &EList, GList &GList, TList &TList)	//Menu selection 7
{
	int filecount = 0;	//counter of bills loaded
	string filename;	//get filename from user
	cout << "Text file name: ";
	getline(cin, filename);
	filecount += EList.LoadEList(filename);	//load lists from file
	filecount += GList.LoadGList(filename);
	filecount += TList.LoadTList(filename);
	cout << filecount << " bills have been loaded.\n\n";
}

#endif
