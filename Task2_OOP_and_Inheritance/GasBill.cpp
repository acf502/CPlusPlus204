/*
Name: Aaron Colin Foote
Date: 10th May 2013
User: acf502, 4258770
File Description: GasBill.cpp for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#include "GasBill.h"
					//static variables assigned base values
float GasBill::heatingValue = 38.82;
float GasBill::pressureFactor = 0.9942;
float GasBill::rate = 0.0297;
float GasBill::supplyCharge = 0.443;

GasBill::GasBill()	//standard initialization
{
	previousReading = 0;
	currentReading = 0;
	next = NULL;
}
GasBill::~GasBill()	//return values to 0 on destruction of objects
{
	previousReading = 0;
	currentReading = 0;
	next = NULL;
}
GList::~GList()
{
	GasBill *curr = head;	//start from head of list
	while( curr != 0 ) 
	{
		GasBill* next = curr->Next();	//delete current node, then change current to next using temporary holder of next
		delete curr;
		curr = curr->Next();
	}
	head = 0;
}

void GList::GAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, float pReading, float cReading) 
{

    // Create a new node
	GasBill* newNode = new GasBill;
	bool recalc = 1;
	newNode->Set(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, pReading, cReading, recalc);
	newNode->SetNext(NULL);

    // Create a temp pointer
	GasBill *tmp = head;

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

void GasBill::Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, float pReading, float cReading, bool recalc)
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
	previousReading = pReading;
	currentReading = cReading;
	if (recalc)
		calc();
}

int GList::SaveGList(string fname) 
{

	int countNodes = 0;
	GasBill *tmp = head;

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

int GList::LoadGList(string fname) 
{
	//class variables
	char bName[MAXLENGTH], rNumber[MAXLENGTH], aName[MAXLENGTH], add[MAXLENGTH];
	string addtmp, bNametmp, rNumbertmp, aNametmp;
	string junk;
	int bCode, pReading, cReading;
	long aNumber;
	float aDue, tGST;
	Date pSDate, pEDate, dDate;
	bool recalc = 0;
	
	//file variables
	const char *file = fname.c_str();
	GasBill *tmp = new GasBill;
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
		if (letter[0] == 'G')
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

			fin >> pReading;
			fin.ignore(256,';');
			fin >> cReading;
			fin.ignore(256,';');
			fin >> aDue;
			fin.ignore(256,';');
			fin >> tGST;
			fin.ignore(256,'\n');
			tmp->Set(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, pReading, cReading, recalc);
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

void GasBill::Output(string fname)
{
	const char *file = fname.c_str();
	ofstream fout;
	fout.open(file, ios::app); //inserted cout billerName since the value is mysteriously disappearing, could not identify reason for disappearance
	fout << "G;" << "billerName" << ";" << billerCode << ";" << referenceNumber << ";" << accountNumber << ";" << accountName << "; " << address << ";" << periodStartDate.day << "/" << periodStartDate.month << "/" << periodStartDate.year << ";" << periodEndDate.day << "/" << periodEndDate.month << "/" << periodEndDate.year << ";" << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << ";" << previousReading << ";" << currentReading << ";";
	fout << setprecision(2) << fixed;
	fout << amountDue << ";" << totalGST << endl;
	fout.close();
}

void GasBill::Print()
{
	cout << "Gas bill:" << endl;
	cout << "Biller name: " << billerName << endl;
	cout << "Biller code: " << billerCode << endl;
	cout << "Reference number: " << referenceNumber << endl;
	cout << "Account number: " << accountNumber << endl;
	cout << "Account name: " << accountName << endl;
	cout << "Address: " << address << endl;
	cout << "Start date: " << periodStartDate.day << "/" << periodStartDate.month << "/" << periodStartDate.year << endl;
	cout << "End date: " << periodEndDate.day << "/" << periodEndDate.month << "/" << periodEndDate.year << endl;
	cout << "Due date: " << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << endl;
	cout << "Previous reading: " << previousReading << endl;
	cout << "Current reading: " << currentReading << endl;
	cout << setprecision(2) << fixed;
	cout << "Total amount due: $" << amountDue << endl;
	cout << "Total GST: $" << totalGST << endl << endl;

}

void GasBill::calc()	//Calculate total amount due and GST
{
	float MJ = 0, gas = 0, supCharge = 0;	
		
	MJ = (currentReading - previousReading) * heatingValue * pressureFactor;	
	gas = MJ * rate;
	
	if (periodEndDate.year > periodStartDate.year)
		supCharge += ((periodEndDate.year - periodStartDate.year) * (365 * supplyCharge));	//increase by 365 for year's difference, assume no leap years
	if ((periodEndDate.year >= periodStartDate.year) && (periodEndDate.month > periodStartDate.month))
		supCharge += ((periodEndDate.month - periodStartDate.month) * (30 * supplyCharge));	//round all months to 30 days
	if ((periodEndDate.year >= periodStartDate.year) && (periodEndDate.month >= periodStartDate.month) && (periodEndDate.day > periodStartDate.day))
		supCharge += ((periodEndDate.day - periodStartDate.day) * supplyCharge);
	cout << setprecision(2) << fixed;
	amountDue = gas + supCharge;
	totalGST = (amountDue / 10);
	
	cout << "\nTotal amount due: $" << amountDue << endl;
	cout << "Total GST: $" << totalGST << "\n\n\n";		
}

void GList::ChangeGas()
{
	GasBill *tmp = head;
	float hValue, pFactor, r, sCharge;
	cout << "\nSet gas rates." << endl;
	cout << "Rate ($ per MJ): ";
	cin >> r;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Heating value: ";
	cin >> hValue;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Pressure factor: ";
	cin >> pFactor;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Supply charge rate ($ per day): ";
	cin >> sCharge;
	cin.clear();
	cin.ignore(10000, '\n');
	tmp->SetGas(r, hValue, pFactor, sCharge);
	cout << "New rates for gas bills have been set.\n\n\n";
}


void GasBill::SetGas(float r, float hValue, float pFactor, float sCharge)
{
	rate = r;
	heatingValue = hValue;
	pressureFactor = pFactor;
	supplyCharge = sCharge;	
}
