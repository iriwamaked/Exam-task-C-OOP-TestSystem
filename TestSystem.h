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
    //Форма для регистрации пользователя
	void Registration() override;
    //Проверка уникальности логина при регистрации пользователя
	bool LoginUnique(string log);

	void ShowGuest()	{guest->ShowGuestInf();	}
    //Метод для верификации пользователя при входе в систему
    bool Verification() override;
	//Метод для проверки соответствия пароля логину при верификации
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
	//Проверка соответствия логина и пароля для входа в систему
	bool CheckAdminLoginPassword(string log, string pass, string filename = "Admin.txt");
public:
	AdminTestSystem() :admin(Admin::GetAdmin()) {}
	//Регистрация админа
	void Registration() override;
	//Верификация админа
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
