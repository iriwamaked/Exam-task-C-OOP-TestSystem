#pragma once
#include<iostream>
#include<map>
#include <string>
#include<fstream>
using namespace std;
class User
{
protected:
	string login;
	string password;
public:
	void SetLogin(string login) { this->login = login; }
	void SetPassword(string pass) { password = pass; }
	string GettLogin() { return login; }
	string GetPassword() { return password; }
	virtual void SaveUserDataToEntry() = 0;
};

class Guest :public User
{
	string FIO;
	string adress;
	string phone;
public:
	Guest() {};
	void SetFIO(string FIO) { this->FIO = FIO; }
	void SetAdress(string adress) { this->adress = adress; }
	void SetPhone(string phone) { this->phone = phone; }
	string GetFIO() { return FIO; }
	string GetAdress() { return adress; }
	string GetPhone() { return phone; }
	void ShowGuestInf()
	{
		cout << login << " " << password << " " << FIO << " " << adress << " " << phone << endl;
 	}
	//Сохраняем логин и пароль пользователя в файл для дальнейшей верификации при последущем входе
	void SaveUserDataToEntry() override;
	//Сохраняем полностью данные пользователя в файл 
	void SaveUserDataAll();

};

class Admin : public User
{
	static Admin* admin;
	Admin(){}
	void SetLoginAdmin(string login)
	{
		this->login = login;
	}
	void SetPasswordAdmin(string password)
	{
		this->password = password;
	}
	string Getlogin() const
	{
		return login;
	}
	string GetPassword() const
	{
		return password;
	}
public:
	static Admin* GetAdmin()
	{
		if (admin == nullptr)
			admin = new Admin();
		return admin;
	}
	//Проверка, есть ли админ в системе (должен быть один)
	bool CheckAdminExsist(string file = "Admin.txt");
	//Установка логина и пароля при регистрации
	void SetLoginPassAdmin(string log, string pass);
	//Сохранение данных админа при регистрации
	void SaveUserDataToEntry() override;
};

