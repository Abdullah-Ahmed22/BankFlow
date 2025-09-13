#include "Deposit.h"
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include <sstream>
//#include<bool>

using namespace std;


Deposit::Deposit(string transaction_number, string transaction_type, string transaction_date, string account_transferred, string acc_number, double amount) 
	:TransactionsFile(transaction_number, transaction_type, transaction_date, account_transferred), 
	acc_number(acc_number), 
	amount(amount)
{

}

void Deposit::deposit_process()
{
	ifstream fileIn("accounts.txt");
	ofstream fileout("temp.txt");
	string line;

	bool account_found = false;

	while (getline(fileIn, line))
	{
		stringstream ss(line);

		string id, account_number, current_balance, account_type, date_create;
		double balance;

		getline(ss, id, ',');
		getline(ss, account_number, ',');
		getline(ss, current_balance, ',');
		balance = stod(current_balance);
		getline(ss, account_type, ',');
		getline(ss, date_create);

		if (account_number == acc_number)
		{
			balance += amount;
			cout << "Deposit successful, new balance is: " << balance << endl;
			account_found = true;
		}

		fileout << id << "," << account_number << "," << balance << "," << account_type << "," << date_create << endl;
	}

	fileIn.close();
	fileout.close();

	remove("accounts.txt");
	rename("temp.txt", "accounts.txt");

	if (account_found)
	{
		save_transactions_in_file();
	}
	else
	{
		cout << "Error: Account number " << acc_number << " not found!" << endl;
	}
	
}

void Deposit::save_transactions_in_file() const
{
	ofstream file("transactions.txt", ios::app);

	if (file.is_open())
	{
		file << transaction_number << "," << acc_number << "," << transaction_type << "," << amount << "," << transaction_date << "," << account_transferred << endl;
		file.close();
		cout << "Data saved to file transactions." << endl;
	}
	else
	{
		cout << "Error opening file transactions." << endl;
	}
}
