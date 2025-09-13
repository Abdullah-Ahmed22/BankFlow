#include "DisplaySpecificAccount.h"
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include <sstream>

using namespace std;

void DisplaySpecificAccount::display_specific_account(string acc_number)
{
	ifstream fileIn("accounts.txt");
	string line;

	while (getline(fileIn, line))
	{
		stringstream ss(line);

		string id, account_number, current_balance, account_type, date_create;

		getline(ss, id, ',');
		getline(ss, account_number, ',');
		getline(ss, current_balance, ',');
		getline(ss, account_type, ',');
		getline(ss, date_create);

		if (account_number == acc_number)
		{
			cout << "ID is: " << id << endl;
			cout << "Account number is: " << account_number << endl;
			cout << "Current balance is: " << current_balance << endl;
			cout << "Type account: " << account_type << endl;
			cout << "Date create account: " << date_create << endl;
			fileIn.close();
			return;
			
		}
	}

	cout << "Account not found." << endl;
}
