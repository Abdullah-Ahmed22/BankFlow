#include "AccountsFile.h"
#include <fstream>
#include <iomanip>


void AccountsFile::save_accounts_in_file(const CreateAccount& acc)
{
	ofstream outfile("accounts.txt", ios::app);

	if (outfile.is_open())
	{
		outfile << acc.get_id() << "," << acc.get_number_account() << "," << acc.get_current_balance() << "," << acc.get_type_account() << "," << acc.get_date_create_account() << endl;
		outfile.close();
		cout << "Data saved to file accounts." << endl << endl;
	}
	else
	{
		cout << "Error opening file accounts." << endl;
	}
}
