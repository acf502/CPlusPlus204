/*
Name: Aaron Colin Foote
Date: 10th May 2013
User: acf502, 4258770
File Description: TelephoneBill.cpp for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#include "TelephoneBill.h"
		
TelephoneBill::TelephoneBill()	//standard initialization
{
	numberOfLocalCalls = 0;
	localCallRate = 0.3;
	internationalCallAmount = 0;
	lineRental = 29.9;
	internetConnection = 35;
	next = NULL;
}
TelephoneBill::~TelephoneBill()	//return values to 0 on destruction of objects
{
	numberOfLocalCalls = 0;
	localCallRate = 0;
	internationalCallAmount = 0;
	lineRental = 0;
	internetConnection = 0;
	next = NULL;
}
TList::~TList()
{
	TelephoneBill *curr = head;	//start from head of list
	while( curr != 0 ) 
	{
		TelephoneBill* next = curr->Next();	//delete current node, then change current to next using temporary holder of next
		delete curr;
		curr = curr->Next();
	}
	head = 0;
}

void TList::TAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int lCalls, float iCalls) 
{

    // Create a new node
	TelephoneBill* newNode = new TelephoneBill;
	bool recalc = 1;
	newNode->Set(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, lCalls, iCalls, recalc);
	newNode->SetNext(NULL);

    // Create a temp pointer
	TelephoneBill *tmp = head;

	if ( tmp != NULL ) 
	{
		while ( tmp->Next() != NULL ) 
		{
			tmp = tmp->Next();
		}

    // Point the last node to the new node
	tmp->SetNext(newNode);
	}
	else 
	{
    // First node in the list
		head = newNode;
	}
}

void TelephoneBill::Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int lCalls, float iCalls, bool recalc)
{
	billerName = bName;
	billerCode = bCode;
	referenceNumber = rNumber;
	accountNumber = aNumber;
	accountName = add;
	address = add;
	amountDue = aDue;
	totalGST = tGST;
	dueDate = dDate;
	periodStartDate = pSDate;
	periodEndDate = pEDate;
	numberOfLocalCalls = lCalls;
	internationalCallAmount = iCalls;
	if (recalc)
		calc();
}

int TList::SaveTList(string fname) 
{

    // Temp pointer
	int countNodes = 0;
	TelephoneBill *tmp = head;

    // One node in the list
	if (head != NULL)
	{
    // Parse and print the list
		do 
		{
			tmp->Output(fname);	//change to output data
			tmp = tmp->Next();
			countNodes++;
		}
		while ( tmp != NULL );
	}

	return countNodes;
}

int TList::LoadTList(string fname) 
{

	//class variables
	char bName[MAXLENGTH], rNumber[MAXLENGTH], aName[MAXLENGTH], add[MAXLENGTH];
	string addtmp, bNametmp, rNumbertmp, aNametmp;
	string junk;
	int bCode, numberOfLocalCalls;
	long aNumber;
	float aDue, tGST, internationalCallAmount;
	Date pSDate, pEDate, dDate;
	bool recalc = 0;
	
	//file variables
	const char *file = fname.c_str();
	TelephoneBill *tmp = new TelephoneBill;
	ifstream fin;
	fin.open(file);
	if (!fin.good())
   	{
		cout << "Could not open file: " << file << endl;
		return 0;
	}
	int countNodes = 0;
	if (tmp != NULL)
	{
		while (tmp->Next() != NULL)
		{
			tmp = tmp->Next();
		}
	}
	else 
	{
		tmp = head;
	}
	while (!fin.eof())
	{
		string letter;
		getline(fin,letter,';');
		if (letter[0] == 'T')
		{
			countNodes++;
			
			getline(fin,bNametmp,';');
			int length = bNametmp.length();
			for (int i=0; i<=length; i++)
				bName[i] = bNametmp[i];
			length++;
			bName[length] = '\0';
			
			fin >> bCode;
			fin.ignore(256,';');
			
			getline(fin,rNumbertmp,';');
			length = rNumbertmp.length();
			for (int i=0; i<=length; i++)
				rNumber[i] = rNumbertmp[i];
			length++;
			rNumber[length] = '\0';
			
			fin >> aNumber;
			fin.ignore(256,';');
			
			getline(fin,aNametmp,';');
			length = aNametmp.length();
			for (int i=0; i<=length; i++)
				aName[i] = aNametmp[i];
			length++;
			aName[length] = '\0';
			
			fin.ignore(256, ' ');
			getline(fin,addtmp,';');
			length = addtmp.length();
			for (int i=0; i<=length; i++)
				add[i] = addtmp[i];
			length++;
			add[length] = '\0';
			
			fin >> pSDate.day;
			fin.ignore(256,'/');
			fin >> pSDate.month;
			fin.ignore(256,'/');
			fin >> pSDate.year;
			fin.ignore(256,';');
			
			fin >> pEDate.day;
			fin.ignore(256,'/');
			fin >>pEDate.month;
			fin.ignore(256,'/');
			fin >> pEDate.year;
			fin.ignore(256,';');
			
			fin >> dDate.day;
			fin.ignore(256,'/');
			fin >> dDate.month;
			fin.ignore(256,'/');
			fin >> dDate.year;
			fin.ignore(256,';');

			fin >> numberOfLocalCalls;
			fin.ignore(256,';');
			fin >> internationalCallAmount;
			fin.ignore(256,';');
			fin >> aDue;
			fin.ignore(256,';');
			fin >> tGST;
			fin.ignore(256,'\n');
			tmp->Set(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, numberOfLocalCalls, internationalCallAmount, recalc);
			tmp->Print();
			tmp->SetNext(NULL);
		}
		else
		{
			getline(fin, junk, '\n');
		}
	}
	fin.close();
	return countNodes;
}

void TelephoneBill::Output(string fname)
{
	const char *file = fname.c_str();
	ofstream fout;
	fout.open(file, ios::app); //inserted cout billerName since the value is mysteriously disappearing, could not identify reason for disappearance
	fout << "T;" << "billerName" << ";" << billerCode << ";" << referenceNumber << ";" << accountNumber << ";" << accountName << ";" << address << ";" << periodStartDate.day << "/" << periodStartDate.month << "/" << periodStartDate.year << ";" << periodEndDate.day << "/" << periodEndDate.month << "/" << periodEndDate.year << ";" << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << ";" << numberOfLocalCalls << ";" << internationalCallAmount << ";";
	fout << setprecision(2) << fixed;
	fout << amountDue << ";" << totalGST << endl;
	fout.close();
}

void TelephoneBill::Print()
{
	cout << "Telephone bill:" << endl;
	cout << "Biller name: " << billerName << endl;
	cout << "Biller code: " << billerCode << endl;
	cout << "Reference number: " << referenceNumber << endl;
	cout << "Account number: " << accountNumber << endl;
	cout << "Account name: " << accountName << endl;
	cout << "Address: " << address << endl;
	cout << "Start date: " << periodStartDate.day << "/" << periodStartDate.month << "/" << periodStartDate.year << endl;
	cout << "End date: " << periodEndDate.day << "/" << periodEndDate.month << "/" << periodEndDate.year << endl;
	cout << "Due date: " << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << endl;
	cout << "Number of local calls: " << numberOfLocalCalls << endl;
	cout << "International calls: " << internationalCallAmount << endl;
	cout << setprecision(2) << fixed;
	cout << "Total amount due: $" << amountDue << endl;
	cout << "Total GST: $" << totalGST << endl << endl;
}

void TelephoneBill::calc()	//Calculate total amount due and GST
{
	float totLCall = 0;
	
	totLCall = numberOfLocalCalls * localCallRate;

	amountDue = totLCall + internationalCallAmount + lineRental + internetConnection;
	totalGST = (amountDue / 10);
	
	cout << setprecision(2) << fixed;
	cout << "\nTotal amount due: $" << amountDue << endl;
	cout << "Total GST: $" << totalGST << "\n\n\n";		
}

