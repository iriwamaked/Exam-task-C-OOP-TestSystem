/*
* ���������������� ������� 2: ������� ������������.
* ������� ����������� ������� ����������� ������������/������. 
* �������� ������������ ������ ������������ ��� �����������.
* ����� � ������� ����, ������ ��� ������������������ �� �����.
* ���� � ������, � ������������ - �������� ������������ ������ � ������.
* ��������� ��� ������������ ����������� �� ����������, ��� � ����� � ���������.
* ������� ����������� �� ����� � ������ � ���������.
* ��������� � ����������� ������� - ����� map.
* ������� ������� ���������� ���������� ��������, ������ ����������, ������, ������� ���������� �������.
* ����� ����� �������� ��������� � ���� ��� �����, ��� ���� �������� � ���� �� ����������.. 
* ������� ����� ��������, �� ����, �������, ������ ��� ����������,
* �� ��������� ����������� ���� ���������� ����� ����� - ���... ����� ����� �������.
* �����������, ��� ��� ����� ���� ������, �� �� ��� ������ ����� �����.
* �������, �� ������ �� �������� ���������� ����� �����������, ���������� � �������.
* 
*/

#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>

#include"Question.h"
#include "Test.h"
#include"TestSystem.h"
#include"Category.h"
int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(65001);
	/*int user;
	cout << "\n\t����� ���������� � ���� ������� ������������.";
	cout << "\n\t�������� ����� ������ � ��������: 1 - �����������; 2 - �������������. "; cin >> user;
	switch (user)
	{
	case 1:
	{
		GuestTestSystem guest;
		int choice;
		cout << "\n\t������� 1 - ����������� � �������, ����� ������� - ��� ����� � �������."; cin >> choice;
		if (choice == 1)
		{
			guest.Registration();
		}
		if (guest.Verification())
		{
			cout << "\n\t��������, ��� �� ������ �������: ";
			cout << "\n\t������ ����: "; cin >> choice;
			switch (choice)
			{
			case 1:
			{
				Test* test = new TestInf5class;
				guest.PassTest(test);
				cout << "\n\t���������� ���������� �������: " << guest.TestResults(test);
				cout << "\n\t������: " << guest.TestResults(test);
				cout << "\n\t������� ���������� �������: " << guest.Percent(guest.TestResults(test)) << "%" << endl;
			}
			break;
			}
		}
	}
	break;
	case 2:
	{
		AdminTestSystem admin;
		int choice;
		cout << "\n\t������� 1 - ����������� � �������, ����� ������� - ��� ����� � �������."; cin >> choice;
		if (choice == 1)
		{
			admin.Registration();
		}
		if (admin.Verification())
		{
			cout << "\n\t��������, ��� �� ������ �������: ";
		}
	}
	break;
	}*/
	int user;
	cout << "\n\t����� ���������� � ���� ������� ������������.";
	cout << "\n\t�������� ����� ������ � ��������: 1 - �����������; 2 - �������������. "; cin >> user;
	switch (user)
	{
	case 1:
	{
		GuestTestSystem guest;
		int choice;
		cout << "\n\t������� 1 - ����������� � �������, ����� ������� - ��� ����� � �������."; cin >> choice;
		if (choice == 1)
		{
			guest.Registration();
		}
		if (guest.Verification())
		{
			cout << "\n\t��������, ��� �� ������ �������: ";
			cout << "\n\t������ ������������: "; /*cin >> choice;*/
			/*switch (choice)
			{
			case 1:
			{*/
				string category=guest.ChoiceCategory();
				string test=guest.ChoiceTest();

				guest.PassTest2(category, test);
				cout << "\n\t���������� ���������� �������: " << guest.TestResults();
				cout << "\n\t������: " << guest.TestResults();
				cout << "\n\t������� ���������� �������: " << guest.Percent(guest.TestResults()) << "%" << endl;
			/*}
			break;
			}*/
		}
	}
	break;
	case 2:
	{
		AdminTestSystem admin;
		int choice;
		cout << "\n\t������� 1 - ����������� � �������, ����� ������� - ��� ����� � �������."; cin >> choice;
		if (choice == 1)
		{
			admin.Registration();
		}
		if (admin.Verification())
		{
			string category_name, test_name;
			cout << "\n\t�������� ��������� - ������� 1, �������� ����, ������� 2:"; cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "\n\t������� �������� ���������: ";
				getline(cin, category_name);
				cin.ignore(1, '\n');
				admin.AddCategory(category_name);
			}
			break;
			case 2:
			{
				cout << "\n\t������� �������� ���������: ";
				getline(cin, category_name);
				cin.ignore(1, '\n');
				cout << "\n\t������� �������� �����: ";
				getline(cin, test_name);
				cin.ignore(1, '\n');
				admin.AddTest(category_name, test_name);
			}
			}

		}
	}
	break;
	}
	
	////Category cat;
	///////*cat.ReadALLCategories();*/
	///////*cat.ShowCategories();*/
	//////string category_choice= cat.ChoiceCategories();
	//////string choice= cat.ChoiceTest();
	//////cout << category_choice << endl;
	//////cout << choice << endl;
	//////GuestTestSystem g;
	//////g.PassTest2(category_choice, choice);
	//////cout << g.TestResults();
	////string category_name, test_name;
	////getline(cin, category_name);
	////cin.ignore(1, '\n');
	////getline(cin, test_name);
	////cin.ignore(1, '\n');
	////cat.AddTestToCategory(category_name, test_name);
}
