#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

void findLowest(double dAccidentsArray[], 
string sRName[]);
double getAccidents(string sRName);
void initializeRegions(string sRName[]);
void showResult(double dAccidentsArray[], 
string sRName[]);

int main()
{
	double dNumAccidents[5];

	string sRegion[5];

	initializeRegions(sRegion);
	

	dNumAccidents[0] = getAccidents(sRegion[0]);
	dNumAccidents[1] = getAccidents(sRegion[1]);
	dNumAccidents[2] = getAccidents(sRegion[2]);
	dNumAccidents[3] = getAccidents(sRegion[3]);
	dNumAccidents[4] = getAccidents(sRegion[4]);
	findLowest(dNumAccidents, sRegion);
	showResult(dNumAccidents, sRegion);
	
	system("pause");
	return 0;
}

void findLowest(double dAccidentsArray[], string sRName[])
{
	int iCnt;
	double dHoldLowest;
	string sHoldName;

	for (iCnt = 1; iCnt <= 4; iCnt++)
	{
		if (dAccidentsArray[iCnt - 1] < dAccidentsArray[iCnt])
		{
			dHoldLowest = dAccidentsArray[iCnt - 1];
			dAccidentsArray[iCnt - 1] = dAccidentsArray[iCnt];
			dAccidentsArray[iCnt] = dHoldLowest;
			sHoldName = sRName[iCnt - 1];
			sRName[iCnt - 1] = sRName[iCnt];
			sRName[iCnt] = sHoldName;
		}
	}
}

double getAccidents(string sRName)
{
	double dAccidents;

	cout << "For the region: " << sRName << endl;
	cout << "Enter car accidents for this region." << endl;
	cin >> dAccidents;

	return dAccidents;
}

void initializeRegions(string sRName[])
{
	sRName[0] = "North";
	sRName[1] = "West";
	sRName[2] = "East";
	sRName[3] = "South";
	sRName[4] = "Central";
}

void showResult(double dAccidentsArray[], string sRName[])
{
	int iCnt;
	cout << endl;

	for (iCnt = 0; iCnt <= 4; iCnt++)
	{
		cout << dAccidentsArray[iCnt] << "   " << sRName[iCnt] << endl;
	}
	cout << "The region with the lowest accidents is: " << sRName[4] << endl;
}


