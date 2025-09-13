#pragma once
#include "TransactionsFile.h"
#include<string>

using namespace std;


class Withdrawal : public TransactionsFile
{
private:
	string acc_number;
	double amount;

public:
	Withdrawal(string transaction_number, string transaction_type, string transaction_date, string account_receiving, string acc_number, double amount);
	void withdrawal_process();

private:
	void save_transactions_in_file() const override;
};

