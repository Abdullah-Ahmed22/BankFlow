#include "CustomersFile.h"
#include <fstream>
#include <iomanip>

void CustomerFile::save_customers_in_file(const CreateAccount& acc)
{
	ofstream outfile("customers.txt", ios::app);

	if (outfile.is_open())
	{
		outfile << acc.get_id() << "," << acc.get_name_customer() << "," << acc.get_phone_number() << "," << acc.get_address() << "," << acc.get_date_birth() << "," << acc.get_national_number() << endl;
		outfile.close();
		cout << "Data saved to file customers." << endl;
	}
	else
	{
		cout << "Error opening file customers." << endl;
	}
}
