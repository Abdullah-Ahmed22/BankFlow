#include "Transfer.h"
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include <sstream>

using namespace std;


Transfer::Transfer(string transaction_number, string transaction_type, string transaction_date, string account_transferred, string from_acc_number, string to_acc_number, double amount)
	:TransactionsFile(transaction_number, transaction_type, transaction_date, account_transferred),
	from_acc_number(from_acc_number),
	to_acc_number(to_acc_number),
	amount(amount)
{
}

void Transfer::transfer_process()
{
    Withdrawal w(transaction_number, "Transfer", transaction_date, to_acc_number, from_acc_number, amount);
    w.withdrawal_process();

	Deposit d(transaction_number, "Receive", transaction_date, from_acc_number, to_acc_number, amount);
	d.deposit_process();

    cout << "Transfer successful, The amount transfer is: " << amount << endl;

    save_transactions_in_file();
}

void Transfer::save_transactions_in_file() const
{
    ofstream file("transactions.txt", ios::app);
    if (file.is_open())
    {
        file << transaction_number << ",Transfer," << transaction_date << ","
            << from_acc_number << "," << to_acc_number << "," << amount << "\n";
        file.close();
        cout << "Data saved to file transactions." << endl;
    }
    else
    {
        cout << "Error opening file transactions." << endl;
    }
}








