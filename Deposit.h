#pragma once
#include "TransactionsFile.h"
#include<string>

using namespace std;

class Deposit : public TransactionsFile
{
private:
	string acc_number;
	double amount;

public:
	Deposit(string transaction_number, string transaction_type, string transaction_date, string account_transferred, string acc_number, double amount);
	void deposit_process();
	void save_transactions_in_file() const override;

};

