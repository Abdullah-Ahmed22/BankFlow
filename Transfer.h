#pragma once
#include "TransactionsFile.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include<iostream>
#include<string>

using namespace std;

class Transfer : public TransactionsFile
{
private:
	string from_acc_number;
	string to_acc_number;
	double amount;
	//Deposit d;
	//Withdrawal w;
	
public:
	Transfer(string transaction_number, string transaction_type, string transaction_date, string account_transferred, string from_acc_number, string to_acc_number, double amount);
	void transfer_process();
    
private:
	void save_transactions_in_file() const override;
};

