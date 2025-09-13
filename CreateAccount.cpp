#include "CreateAccount.h"
#include<iostream>
#include<string>

using namespace std;

CreateAccount::CreateAccount()
{
	cout << "===========================================================" << endl;
	cout << "Enter name customer: ";
	getline(cin, name_customer);

	cout << "\nEnter national number of customer: ";
	getline(cin, national_number);

	cout << "\nEnter date birth customer(day-month-year): ";
	getline(cin, date_birth);

	cout << "\nEnter address of customer: ";
	getline(cin, address);

	cout << "\nEnter Id customer: ";
	getline(cin, id);

	cout << "\nEnter phone number customer: ";
	getline(cin, phone_number);

	cout << "\nEnter date create account: ";
	getline(cin, date_create_account);

	cout << "\nEnter password account: ";
	getline(cin, password_account);

	cout << "\nEnter number account: ";
	getline(cin, number_account);

	cout << "\nEnter current balance: ";
	getline(cin, current_balance);

	cout << "\nEnter type account(Saving or Current): ";
	getline(cin, type_account);
	cout << "===========================================================" << endl << endl;

}

string CreateAccount::get_name_customer() const
{
	return name_customer;
}

string CreateAccount::get_national_number() const
{
	return national_number;
}

string CreateAccount::get_date_birth() const
{
	return date_birth;
}

string CreateAccount::get_address() const
{
	return address;
}

string CreateAccount::get_id() const
{
	return id;
}

string CreateAccount::get_phone_number() const
{
	return phone_number;
}

string CreateAccount::get_date_create_account() const
{
	return date_create_account;
}

string CreateAccount::get_password_account() const
{
	return password_account;
}

string CreateAccount::get_number_account() const
{
	return number_account;
}

string CreateAccount::get_current_balance() const
{
	return current_balance;
}

string CreateAccount::get_type_account() const
{
	return type_account;
}




