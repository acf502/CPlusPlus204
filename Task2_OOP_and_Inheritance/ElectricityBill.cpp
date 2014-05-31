/*
Name: Aaron Colin Foote
Date: 10th May 2013
User: acf502, 4258770
File Description: ElectricityBill.cpp for task 2 of Assignment 2 of CSCI204 (Object and Generic Programming in C++)
*/

#include "ElectricityBill.h"
						//static variables assigned base values
float ElectricityBill::rate1 = 0.245;
int ElectricityBill::rate1Threshold = 1750;
float ElectricityBill::rate2 = 0.264;
float ElectricityBill::supplyCharge = 0.699;

ElectricityBill::ElectricityBill()	//standard initialization
{
	previousReading = 0;
	currentReading = 0;
	next = NULL;
}
ElectricityBill::~ElectricityBill()	//return values to 0 on destruction of objects
{
	previousReading = 0;
	currentReading = 0;
	rate1 = 0;
	rate1Threshold = 0;
	rate2 = 0;
	supplyCharge = 0;
	next = NULL;
}
EList::~EList()
{
	ElectricityBill *curr = head;	//start from head of list
	while( curr != 0 ) 
	{
		ElectricityBill* next = curr->Next();	//delete current node, then change current to next using temporary holder of next
		delete curr;
		curr = curr->Next();
	}
	head = 0;
}

void EList::EAppend(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int pReading, int cReading) 
{

    // Create a new node
	ElectricityBill* newNode = new ElectricityBill;
	bool recalc = 1;
	newNode->Set(bName, bCode, rNumber, aNumber, aName, add, aDue, tGST, pSDate, pEDate, dDate, pReading, cReading, recalc);
	newNode->SetNext(NULL);

    // Create a temp pointer
	ElectricityBill *tmp = head;

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

void ElectricityBill::Set(char *bName, int bCode, char *rNumber, long aNumber, char *aName, char *add, float aDue, float tGST, Date pSDate, Date pEDate, Date dDate, int pReading, int cReading, bool recalc)
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

int EList::SaveEList(string fname) 
{

	int countNodes = 0;
	ElectricityBill *tmp = head;

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

int EList::LoadEList(string fname) 
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
	ElectricityBill *tmp = new ElectricityBill;
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
		if (letter[0] == 'E')
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

void ElectricityBill::Output(string fname)
{
	const char *file = fname.c_str();
	ofstream fout;
	fout.open(file, ios::app); //inserted cout billerName since the value is mysteriously disappearing, could not identify reason for disappearance
	fout << "E;" << "billerName" << ";" << billerCode << ";" << referenceNumber << ";" << accountNumber << ";" << accountName << "; " << address << ";" << periodStartDate.day << "/" << periodStartDate.month << "/" << periodStartDate.year << ";" << periodEndDate.day << "/" << periodEndDate.month << "/" << periodEndDate.year << ";" << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << ";" << previousReading << ";" << currentReading << ";";
	fout << setprecision(2) << fixed;
	fout << amountDue << ";" << totalGST << endl;
	fout.close();
}

void ElectricityBill::Print()
{
	cout << "\nElectricity bill:" << endl;
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

void ElectricityBill::calc()	//Calculate total amount due and GST
{
	float Electricity = 0, supCharge = 0;	

	if (((currentReading - previousReading) < rate1Threshold))
		Electricity = (currentReading - previousReading) * rate1;
	else
		Electricity = (currentReading - previousReading) * rate1 + ((currentReading - previousReading) - rate1Threshold) * rate2;
		
	if (periodEndDate.year > periodStartDate.year)
		supCharge += ((periodEndDate.year - periodStartDate.year) * (365 * supplyCharge));	//increase by 365 for year's difference, assume no leap years
	if ((periodEndDate.year >= periodStartDate.year) && (periodEndDate.month > periodStartDate.month))
		supCharge += ((periodEndDate.month - periodStartDate.month) * (30 * supplyCharge));	//round all months to 30 days
	if ((periodEndDate.year >= periodStartDate.year) && (periodEndDate.month >= periodStartDate.month) && (periodEndDate.day > periodStartDate.day))
		supCharge += ((periodEndDate.day - periodStartDate.day) * supplyCharge);

	cout << setprecision(2) << fixed;
	amountDue = Electricity + supCharge;
	totalGST = (amountDue / 10);
}

void EList::ChangeElec()
{
	ElectricityBill *tmp = head;
	float r1, r2, sCharge;
	int r1Threshold;
	cout << "\nSet Electricity rates." << endl;
	cout << "Rate 1 ($ per kWh): ";
	cin >> r1;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Threshold: ";
	cin >> r1Threshold;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Rate 2 (per kWh): ";
	cin >> r2;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Supply charge rate ($ per day): ";
	cin >> sCharge;
	cin.clear();
	cin.ignore(10000, '\n');
	tmp->SetElec(r1, r1Threshold, r2, sCharge);
	cout << "New rates for Electricity bills have been set.\n\n\n";
}

void ElectricityBill::SetElec(float r1, int r1Threshold, float r2, float sCharge)
{
	rate1 = r1;
	r1Threshold = r1Threshold;
	rate2 = r2;
	supplyCharge = sCharge;	
}
