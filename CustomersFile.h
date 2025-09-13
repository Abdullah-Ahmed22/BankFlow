#pragma once
#include "CreateAccount.h"

class CustomerFile
{
public:
	static void save_customers_in_file(const CreateAccount& acc);
};

