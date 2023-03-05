#include "TestSystem.h"

bool GuestTestSystem::LoginUnique(string log)
{
	string line;
	ifstream fin("Guest.txt");
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (line.empty())
				break;
			if (line.find(log) != string::npos)
			{
				if (line.compare(log) == 0)
				{
					fin.close();
					return true;
				}
			}
		}
		fin.close();
		return false;
	}
	
}

bool GuestTestSystem::Verification()
{
	string login;
	string password;
	cin.ignore(1, '\n');
	cout << "\n\t������� �����: ";
	
	getline(cin, login);

	cout << "\n\t������� ������: ";
	/*cin.ignore();*/
	getline(cin, password);
	if (AllLoginsAndPasswords(login, password))
	{
		cout << "\n\t���� �������� �������.\n";
		return 1;
	}
	else
	{
		cout << "\n\t�������� ����� ��� ������. ���������� �����.\n";
		Verification();
	}
}

bool GuestTestSystem::AllLoginsAndPasswords(string log, string pass)
{
	map<string, string> users;

	// ������ ������ �� ����� � ������ �� � map
	ifstream fin("Guest.txt");
	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			string login = line;
			getline(fin, line);
			string password = line;
			users[login] = password;
		}
		fin.close();
	}

	// �������� ������������ ������ � ������
	auto it = users.find(log);
	if (it != users.end() && it->second == pass)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GuestTestSystem::Registration()
{
	string tmp;
	cout << "\n\t������� �����: ";
	cin.ignore(1, '\n');
	getline(cin, tmp);
	
	if (!LoginUnique(tmp))
		guest->SetLogin(tmp);
	else
	{
		cout << "\n\t������������ � ����� ������� ��� ����������.";
		Registration();
	}

	cout << "\n\t������� ������: ";
	 getline(cin, tmp);
	 /*cin.ignore(1,'\n');*/
	guest->SetPassword(tmp);

	cout << "\n\t������� ���:";
	getline(cin, tmp);
	/*cin.ignore(1, '\n');*/
	guest->SetFIO(tmp);

	cout << "\n\t������� �������� �����: ";
	getline(cin, tmp);
	/*cin.ignore(1, '\n');*/
	guest->SetAdress(tmp);

	cout << "\n\t������� ����� ��������: ";
	
	getline(cin, tmp);
	cin.ignore(1, '\n');
	guest->SetPhone(tmp);
	guest->SaveUserDataToEntry();
	guest->SaveUserDataAll();
}

bool AdminTestSystem::Verification()
{
	string login;
	string password;

	cout << "\n\t������� �����: ";
	cin.ignore(1,'\n');
	getline(cin, login);
	//cin.ignore(1,'\n');
	cout << "\n\t������� ������: ";
	getline(cin, password);
	/*cin.ignore(1,'\n');*/
	if (CheckAdminLoginPassword(login, password))
	{
		cout << "\n\t���� �������� �������.\n";
		return 1;
	}
	else
	{
		cout << "\n\t�������� ����� ��� ������. ���������� �����.\n";
		Verification();
	}
}

void AdminTestSystem::Registration()
{
	if (!admin->CheckAdminExsist())
	{
		string login, password;
		cin.ignore(1, '\n');
		cout << "\n\t������� �����: ";
		getline(cin, login);
		cout << "\n\t������� ������: ";
		cin.ignore(1, '\n');
		getline(cin, password);
		/*cin.ignore(1, '\n');*/
		admin->SetLoginPassAdmin(login, password);
		admin->SaveUserDataToEntry();
	}
	else
	{
		cout << "\n\t������� ������������ ��� �������� �������������, �� �� ������ ������������������, ������� � �������.";
		/*Verification();*/
	}
}

bool AdminTestSystem::CheckAdminLoginPassword(string log, string pass, string filename)
{
	string login, password;
	ifstream fin(filename);
	if (fin.is_open())
	{
		getline(fin, login);
		getline(fin, password);
		fin.close();
		if (login == log && password == pass)
			return true;
		else
			return false;
	}
	fin.close();
}
