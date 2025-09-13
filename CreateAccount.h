#pragma once
#include<iostream>
#include<string>

using namespace std;

class CreateAccount
{
private:
	string name_customer;
	string national_number;
	string date_birth;
	string address;
	string id;
	string phone_number;
	string date_create_account;
	string password_account;
	string number_account;
	string current_balance;
	string type_account;

public:
	CreateAccount(); 

	string get_name_customer() const;
	string get_national_number() const;
	string get_date_birth() const;
	string get_address() const;
	string get_id() const;
	string get_phone_number() const;
	string get_date_create_account() const;
	string get_password_account() const;
	string get_number_account() const;
	string get_current_balance() const;
	string get_type_account() const;
};

