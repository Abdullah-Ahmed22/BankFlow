#include "DisplaySpecificTransaction.h"
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include <sstream>

using namespace std;

void DisplaySpecificTransaction::display_specific_transaction(int number_process, string acc_number, string acc_number_transferred)
{
	if (number_process == 1)
	{
		ifstream fileIn("transactions.txt");
		string line;
		bool account_found = false;

		while (getline(fileIn, line))
		{
			stringstream ss(line);

			string transaction_number, account_number, type_process, amount, date_transaction, account_transferred;

			getline(ss, transaction_number, ',');
			getline(ss, account_number, ',');
			getline(ss, type_process, ',');
			getline(ss, amount, ',');
			getline(ss, date_transaction, ',');
			getline(ss, account_transferred);

			if (account_number == acc_number && type_process == "Deposit")
			{
				account_found = true;
				cout << "Transaction number is: " << transaction_number << endl;
				cout << "Account number is: " << account_number << endl;
				cout << "Type process is: " << type_process << endl;
				cout << "Amount is: " << amount << endl;
				cout << "Transaction date is: " << date_transaction << endl;
				cout << "Transferred number is: " << account_transferred << endl;
				cout << "#######################################################" << endl << endl;
				//fileIn.close();
				//return;

			}
		}
		fileIn.close();

		if (!account_found)
		{
			cout << "Error: Account number " << acc_number << " not found!" << endl;
		}

		//cout << "Transaction not found." << endl;
	}
	else if (number_process == 2)
	{
		ifstream fileIn("transactions.txt");
		string line;
		bool account_found = false;

		while (getline(fileIn, line))
		{
			stringstream ss(line);

			string transaction_number, account_number, type_process, amount, date_transaction, account_transferred;

			getline(ss, transaction_number, ',');
			getline(ss, account_number, ',');
			getline(ss, type_process, ',');
			getline(ss, amount, ',');
			getline(ss, date_transaction, ',');
			getline(ss, account_transferred);

			if (account_number == acc_number && type_process == "Withdrawal")
			{
				account_found = true;
				cout << "Transaction number is: " << transaction_number << endl;
				cout << "Account number is: " << account_number << endl;
				cout << "Type process is: " << type_process << endl;
				cout << "Amount is: " << amount << endl;
				cout << "Transaction date is: " << date_transaction << endl;
				cout << "Transferred number is: " << account_transferred << endl;
				cout << "#######################################################" << endl << endl;
				/*fileIn.close();*/
				//return;

			}
		}
		fileIn.close();
		if (!account_found)
		{
			cout << "Error: Account number " << acc_number << " not found!" << endl;
		}

		//cout << "Transaction not found." << endl;
	}
	else if (number_process == 3)
	{
		ifstream fileIn("transactions.txt");
		string line;

		while (getline(fileIn, line))
		{
			stringstream ss(line);

			string transaction_number, account_number, type_process, amount, date_transaction, account_transferred;

			getline(ss, transaction_number, ',');
			getline(ss, account_number, ',');
			getline(ss, type_process, ',');
			getline(ss, amount, ',');
			getline(ss, date_transaction, ',');
			getline(ss, account_transferred);

			if ((account_number == acc_number || account_number == acc_number_transferred) && (type_process == "Transfer" || type_process == "Receive" || type_process == "receive"))
			{
				cout << "Transaction number is: " << transaction_number << endl;
				cout << "Account number is: " << account_number << endl;
				cout << "Type process is: " << type_process << endl;
				cout << "Amount is: " << amount << endl;
				cout << "Transaction date is: " << date_transaction << endl;
				cout << "Transferred number is: " << account_transferred << endl;
				cout << "#######################################################" << endl << endl;

				/*fileIn.close();*/
				//return;

			}
		}
		fileIn.close();
		//cout << "Transaction not found." << endl;
	}
	else
	{
		cout << "Wrong type process." << endl;
	}
}
