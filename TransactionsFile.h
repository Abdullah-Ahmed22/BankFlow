#pragma once
#include<string>

using namespace std;


class TransactionsFile 
{
protected:
	string transaction_number;
	string transaction_type;
	string transaction_date;
	string account_transferred;

public:
	TransactionsFile(string transaction_number, string transaction_type, string transaction_date, string account_transferred)
	{
		this->transaction_number = transaction_number;
		this->transaction_type = transaction_type;
		this->transaction_date = transaction_date;
		this->account_transferred = account_transferred;

	}
	virtual void save_transactions_in_file() const = 0;
};

