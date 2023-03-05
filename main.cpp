/*
* Экзаменнационное задание 2: система тестирования.
* Удалось реализовать систему регистрации пользователя/админа. 
* Проверку уникальности логина пользователя при регистрации.
* Админ в системе один, второй раз зарегистрироваться не может.
* Вход и админа, и пользователя - проверка соответствия логина и пароля.
* Категории для тестирования загружаются из директории, как и файлы с вопросами.
* Вопросы загружаются из файла в вектор с вопросами.
* Категории с конкретными тестами - через map.
* Система считает количество правильных вопросов, выдает количество, оценку, процент правильных ответов.
* Админ может добавить категорию и файл для теста, сам тест добавить в файл не получилось.. 
* Задание очень объемное, не знаю, выбрала, потому что интересное,
* но полностью реализовать весь функционал через файлы - это... очень много времени.
* Догадываюсь, что тут нужна база данных, но мы это только будем учить.
* Надеюсь, на оценку не повлияет отсутствие всего функционала, указанного в задании.
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
	cout << "\n\tДобро пожаловать в нашу систему тестирования.";
	cout << "\n\tВыберите режим работы с системой: 1 - Тестируемый; 2 - Администратор. "; cin >> user;
	switch (user)
	{
	case 1:
	{
		GuestTestSystem guest;
		int choice;
		cout << "\n\tНажмите 1 - регистрация в системе, любую клавишу - для входа в систему."; cin >> choice;
		if (choice == 1)
		{
			guest.Registration();
		}
		if (guest.Verification())
		{
			cout << "\n\tВыберите, что вы хотите сделать: ";
			cout << "\n\tПройти тест: "; cin >> choice;
			switch (choice)
			{
			case 1:
			{
				Test* test = new TestInf5class;
				guest.PassTest(test);
				cout << "\n\tКоличество правильных ответов: " << guest.TestResults(test);
				cout << "\n\tОценка: " << guest.TestResults(test);
				cout << "\n\tПроцент правильных ответов: " << guest.Percent(guest.TestResults(test)) << "%" << endl;
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
		cout << "\n\tНажмите 1 - регистрация в системе, любую клавишу - для входа в систему."; cin >> choice;
		if (choice == 1)
		{
			admin.Registration();
		}
		if (admin.Verification())
		{
			cout << "\n\tВыберите, что вы хотите сделать: ";
		}
	}
	break;
	}*/
	int user;
	cout << "\n\tДобро пожаловать в нашу систему тестирования.";
	cout << "\n\tВыберите режим работы с системой: 1 - Тестируемый; 2 - Администратор. "; cin >> user;
	switch (user)
	{
	case 1:
	{
		GuestTestSystem guest;
		int choice;
		cout << "\n\tНажмите 1 - регистрация в системе, любую клавишу - для входа в систему."; cin >> choice;
		if (choice == 1)
		{
			guest.Registration();
		}
		if (guest.Verification())
		{
			cout << "\n\tВыберите, что вы хотите сделать: ";
			cout << "\n\tПройти тестирование: "; /*cin >> choice;*/
			/*switch (choice)
			{
			case 1:
			{*/
				string category=guest.ChoiceCategory();
				string test=guest.ChoiceTest();

				guest.PassTest2(category, test);
				cout << "\n\tКоличество правильных ответов: " << guest.TestResults();
				cout << "\n\tОценка: " << guest.TestResults();
				cout << "\n\tПроцент правильных ответов: " << guest.Percent(guest.TestResults()) << "%" << endl;
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
		cout << "\n\tНажмите 1 - регистрация в системе, любую клавишу - для входа в систему."; cin >> choice;
		if (choice == 1)
		{
			admin.Registration();
		}
		if (admin.Verification())
		{
			string category_name, test_name;
			cout << "\n\tДобавить категорию - нажмите 1, добавить тест, нажмите 2:"; cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "\n\tВведите название категории: ";
				getline(cin, category_name);
				cin.ignore(1, '\n');
				admin.AddCategory(category_name);
			}
			break;
			case 2:
			{
				cout << "\n\tВведите название категории: ";
				getline(cin, category_name);
				cin.ignore(1, '\n');
				cout << "\n\tВведите название теста: ";
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
