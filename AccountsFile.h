#pragma once
#include "CreateAccount.h"

class AccountsFile
{
public:
	static void save_accounts_in_file(const CreateAccount& acc);
};

