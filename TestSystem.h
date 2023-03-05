#pragma once
#include "User.h"
#include"Test.h"
#include"Category.h"
class ITestSystem
{
protected:
	Category cat;
	Test test;
public:
	virtual void Registration() = 0;
	virtual bool Verification() = 0;
};

class GuestTestSystem : public ITestSystem
{
	Guest* guest;
public:
	GuestTestSystem(): guest(new Guest)/*, test(new Test)*/{}
    //����� ��� ����������� ������������
	void Registration() override;
    //�������� ������������ ������ ��� ����������� ������������
	bool LoginUnique(string log);

	void ShowGuest()	{guest->ShowGuestInf();	}
    //����� ��� ����������� ������������ ��� ����� � �������
    bool Verification() override;
	//����� ��� �������� ������������ ������ ������ ��� �����������
	bool AllLoginsAndPasswords(string log, string pass);

	string ChoiceCategory()
	{
		return cat.ChoiceCategories();
	}

	string ChoiceTest()
	{
		return cat.ChoiceTest();
	}
	/*void PassTest(Test* test){	test->GoTest();}*/

	void PassTest2(string Category, string TestName) {
		test.LoadQuestions(Category, TestName);
		test.GoTest();
	}

	int TestResults() { return test.TestResult(); }
	double Percent(int k)
	{
		double percent = (static_cast<double>(k) / 12) * 100;
		return percent;
	}
	~GuestTestSystem()
	{
		delete guest;
	}
};

class AdminTestSystem :public ITestSystem
{
	Admin* admin;
	//�������� ������������ ������ � ������ ��� ����� � �������
	bool CheckAdminLoginPassword(string log, string pass, string filename = "Admin.txt");
public:
	AdminTestSystem() :admin(Admin::GetAdmin()) {}
	//����������� ������
	void Registration() override;
	//����������� ������
	bool Verification() override;

	void AddCategory(string CategoryName)
	{
		cat.AddCategory(CategoryName);
	}
	
	void AddTest(string CategoryName, string TestName)
	{
		cat.AddTestToCategory(CategoryName, TestName);
	}
};
