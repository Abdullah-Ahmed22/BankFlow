#include "DisplaySpecificCustomer.h"
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include <sstream>

using namespace std;

void DisplaySpecificCustomer::display_specific_customer(string name_customer)
{
	ifstream fileIn("customers.txt");
	string line;

	while (getline(fileIn, line))
	{
		stringstream ss(line);

		string id, name, phone_number, address, date_porn, national_number;

		getline(ss, id, ',');
		getline(ss, name, ',');
		getline(ss, phone_number, ',');
		getline(ss, address, ',');
		getline(ss, date_porn, ',');
		getline(ss, national_number);

		if (name == name_customer)
		{
			cout << "ID is: " << id << endl;
			cout << "Name is: " << name << endl;
			cout << "Phone number is: " << phone_number << endl;
			cout << "Address is: " << address << endl;
			cout << "Date of porn is: " << date_porn << endl;
			cout << "National number is: " << national_number << endl;
			fileIn.close();
			return;

		}
	}

	cout << "Customer not found." << endl;
}
