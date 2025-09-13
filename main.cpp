#include<iostream>
#include<string>
#include "CreateAccount.h"
#include "CustomersFile.h"
#include "AccountsFile.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include "Transfer.h"
#include "DisplaySpecificCustomer.h"
#include "DisplaySpecificAccount.h"
#include "DisplaySpecificTransaction.h"


using namespace std;

// Prototype functions
int get_choice();
void handle_choice(int choice);


int main()
{
	int choice;
	do
	{
		choice = get_choice(); // Call bank flow choice
		handle_choice(choice); // Choice operation based on user choice
	} while (choice != 0); // If user selected zero finish process
	
	return 0;
}

// Function display the bank flow menu and return the user choice
int get_choice()
{
	int choice; // Choice taken from user

	// MENU
	cout << "======================== BankFlow ========================" << endl << endl;

	cout << "===========================================================" << endl;
	cout << "1. Create Account." << endl;
	cout << "2. Deposit Money." << endl;
	cout << "3. Withdrawal Money." << endl;
	cout << "4. Transfer Money." << endl;
	cout << "5. Display Specific Customer." << endl;
	cout << "6. Display Specific Account." << endl;
	cout << "7. Display Specific Transaction." << endl;
	cout << "0. Exit." << endl;
	cout << "===========================================================" << endl << endl;

	cout << "===========================================================" << endl;
	cout << "Enter Your Process: ";
	cin >> choice;
	cin.ignore();
	cout << "===========================================================" << endl << endl;

	return choice;

}

// Function handle choice based on user choice
void handle_choice(int choice)
{
	switch (choice)
	{
	case 1: {
		CreateAccount acc;
		CustomerFile::save_customers_in_file(acc);
		AccountsFile::save_accounts_in_file(acc);
		break;
	}
	case 2: {
		string transaction_number, transaction_date, acc_number;
		//string transaction_type = "Deposit";
		string account_transferred = "Null";
		double amount;

		cout << "===========================================================" << endl;
		cout << "Enter Transaction Number : ";
		getline(cin, transaction_number);

		/*cout << "Enter Transaction Type: ";
		getline(cin, transaction_type);*/

		cout << "Enter Transaction Date(day-month-year): ";
		getline(cin, transaction_date);

		cout << "Enter Account Number: ";
		getline(cin, acc_number);

		cout << "Enter Amount Money: ";
		cin >> amount;
		cin.ignore();

		Deposit d(transaction_number, "Deposit", transaction_date, account_transferred, acc_number, amount);
		d.deposit_process();
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 3: {
		string transaction_number, transaction_date, acc_number;
		//string transaction_type = "Withdrawal";
		string  account_receiving = "Null";
		double amount;

		cout << "===========================================================" << endl;
		cout << "Enter Transaction Number : ";
		getline(cin, transaction_number);

		/*cout << "Enter Transaction Type: ";
		getline(cin, transaction_type);*/

		cout << "Enter Transaction Date(day-month-year): ";
		getline(cin, transaction_date);

		cout << "Enter Account Number: ";
		getline(cin, acc_number);

		cout << "Enter Amount Money: ";
		cin >> amount;
		cin.ignore();

		Withdrawal w(transaction_number, "Withdrawal", transaction_date, account_receiving, acc_number, amount);
		w.withdrawal_process();
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 4: {
		string transaction_number, transaction_date, from_acc_number, to_acc_number;
		//string transaction_type = "Transfer";
		double amount;

		cout << "===========================================================" << endl;
		cout << "Enter Transaction Number : ";
		getline(cin, transaction_number);

		/*cout << "Enter Transaction Type: ";
		getline(cin, transaction_type);*/

		cout << "Enter Transaction Date(day-month-year): ";
		getline(cin, transaction_date);

		cout << "Enter Sender Account Number: ";
		getline(cin, from_acc_number);

		cout << "Enter Receive Account Number: ";
		getline(cin, to_acc_number);

		cout << "Enter Amount Money: ";
		cin >> amount;
		cin.ignore();

		Transfer t(transaction_number, "Transfer", transaction_date, from_acc_number, from_acc_number, to_acc_number, amount);
		t.transfer_process();
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 5: {
		string name;

		cout << "===========================================================" << endl;
		cout << "Enter Name Customer: ";
		getline(cin, name);
		cout << "-------------------------------------------------------" << endl;

		DisplaySpecificCustomer::display_specific_customer(name);
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 6: {
		string acc_number;

		cout << "===========================================================" << endl;
		cout << "Enter Account Number: ";
		getline(cin, acc_number);
		cout << "-------------------------------------------------------" << endl;

		DisplaySpecificAccount::display_specific_account(acc_number);
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 7: {
		string acc_number, acc_number_transferred;
		int num_process;

		cout << "===========================================================" << endl;
		cout << "1. Deposit." << endl;
		cout << "2. Withdrawal." << endl;
		cout << "3. Transfer." << endl;
		cout << "Enter process Type: ";
		cin >> num_process;
		cin.ignore();

		cout << "Enter Account Number: ";
		getline(cin, acc_number);

		cout << "Enter Transferred Account Number: ";
		getline(cin, acc_number_transferred);
		cout << "-------------------------------------------------------" << endl;

		DisplaySpecificTransaction::display_specific_transaction(num_process, acc_number, acc_number_transferred);
		cout << "===========================================================" << endl << endl;
		break;
	}
	case 0:
		// Exit the program
		cout << "Exiting..." << endl;
		break;
	default:
		// If user input number not found in menu
		cout << "Invalid choice!" << endl;
	}
}