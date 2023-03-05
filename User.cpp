#include "User.h"
Admin* Admin::admin/* = nullptr*/;
void Guest::SaveUserDataToEntry()
{
	ofstream fout("Guest.txt", ios::app);
	if (fout.is_open()) {
		fout << login << endl;
		fout << password << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}
	fout.close();
}

void Guest::SaveUserDataAll()
{
	ofstream fout("GuestData.txt", ios::app);
	if (fout.is_open()) {
		fout << login << endl;
		fout << password << endl;
		fout << FIO << endl;
		fout << adress << endl;
		fout << phone << endl;
		fout << "1" << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}
	fout.close();
}

bool Admin::CheckAdminExsist(string file /*= "Admin.txt"*/)
{
	ifstream fin(file);
	if (!fin.is_open()) {
		std::cerr << "Could not open file Admin.txt for reading." << std::endl;
	}
	string line;
	if (fin.peek() == ifstream::traits_type::eof())
	{
		fin.close();
		return false;
	}
	else
	{
		fin.close();
		return true;
	}
}

void Admin::SetLoginPassAdmin(string log, string pass)
{
	SetLoginAdmin(log);
	SetPasswordAdmin(pass);
}

void Admin::SaveUserDataToEntry() 
{
	ofstream fout("Admin.txt");
	if (fout.is_open()) {
		fout << login << endl;
		fout << password << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}
	fout.close();
}