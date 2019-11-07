// Customer-Item-Transaction.cpp : Defines the entry point for the console application.
// Nile Weadick

#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "string"
#include "fstream"

using namespace std;


int main()
{
	//Declare files

	ifstream customer2e;
	ifstream itemsFile;
	ofstream transactions;

//Declare Variables

	string inputLine;
	string partNumber;
	string lastName;
	string firstName;
	string date;
	string partDescription;
	string partPrice;
	string partColor;
	string colorCode;
	
//Open files 

	customer2e.open(".dat");
	if (!customer2e.is_open())
	{
		cout << "Customer file failed to open" << endl;
	}
	itemsFile.open(".pip");
	if (!itemsFile.is_open())
	{
		cout << "Item file failed to open" << endl;
	}
	transactions.open(".xml");
	if (!transactions.is_open())
	{
		cout << "Transactions file failed to open" << endl;
	}
	
// Read customers File

	// read a complete line of data

	getline(customer2e, inputLine);

	firstName = inputLine.substr(20,5);
	lastName  = inputLine.substr(39,6);
	date = inputLine.substr(0,10);
	partNumber = inputLine.substr(10,8);
	colorCode = partNumber.substr(5,1);

  if(colorCode == "1")
        {
           partColor = "Red";
        }
        else if (colorCode == "2")
        {
            partColor = "Blue";
        }
        else if (colorCode == "3")
        {
            partColor = "White";
        }
        else if (colorCode == "4")
        {
            partColor = "Black";
        }
        else
        {
            partColor = "Invalid color code in part number.";
        }

// Read Items File

	getline(itemsFile, inputLine);

	partDescription = inputLine.substr(0,7);
	partPrice = inputLine.substr(23,4);
	
	
// Write XML file

	transactions << "<Transaction>" << endl;
  	transactions << "<Customer>" << endl;
   	transactions << "<Lastname>" << lastName << "</Lastname>" << endl;
    transactions << "<Firstname>" << firstName << "</Firstname>" << endl;
    transactions << "</Customer>" << endl;
   	transactions << "<TransactionDate>" << date << "</TransactionDate>" << endl;
    transactions << "<Items>" << endl;
    transactions << "<Item>" << endl;
    transactions << "<PartNumber>" << partNumber << "</PartNumber>" << endl;
    transactions << "<PartColor>" << partColor << "</PartColor>" << endl;
    transactions << "<PartDescription>" << partDescription << "</PartDescription>" << endl;
    transactions << "<PartPrice>" << partPrice << "</PartPrice>" << endl;
    transactions << "</Item>" << endl;
    transactions << "</Items>" << endl;
    transactions << "</Transaction>" << endl;

// close files 

	customer2e.close();
	itemsFile.close();
	transactions.close();

// Freeze screen 

  string junk;
  cout << "Hit any key to continue...";
  cin >> junk;

	return 0;
}

