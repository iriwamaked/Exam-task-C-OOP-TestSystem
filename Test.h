#pragma once
#include"Question.h"
#include <filesystem>
#include<locale>

namespace fs = std::filesystem;
class Test
{
protected:
	vector<Question> questions;
	int rightAns;
public:
	/*Test() :questions(vector <Question>()),  rightAns(0) {};*/
	void LoadQuestions(string nameCat, string TestName);
	void ShowQuestions();
	void SaveTest();
	void GoTest();
	int TestResult()
	{
		return rightAns;
	}

	Test CreateTest()
	{
		Test tmp;
		int numQuestions = 12;
		for (int i = 1; i < numQuestions+1; i++)
		{
			Question q;
			string QuestionText;
			vector<string> ans;
			cout << i << "\n\tВведите вопрос теста: ";
			getline(cin, QuestionText);
			q.SetQuestion(QuestionText);
			for (int j = 1; j < 4; j++)
			{
				string AnswerText;
				cout << "\n\tВведите вариант ответа " << j << ": ";
				getline(cin, AnswerText);
				ans.push_back(AnswerText);
			}
			q.SetAnswer(ans);
			int correctAns;
			cout << "\n\tВведите правильный ответ (1-3): ";
			cin >> correctAns;
			cin.ignore();
			q.SetCorrectAnswer(correctAns);
		/*	Question q(QuestionText, ans, correctAns);*/
			questions.push_back(q);
		}
		return tmp;
	}
	void AddTest(string CategoryName, string TestName)
	{
		if (!fs::exists("\Categories\\" + CategoryName))
		{
			fs::create_directory("Categories\\" + CategoryName);
		}
		CreateTest();
		ofstream fout("Categories\\" + CategoryName + "\\" + TestName + ".txt");
		if (fout.is_open())
		{
			SaveTest();
			fout.close();
		}
		else
			cout << "\n\tНеудачная попытка открытия файла";
	}

};

//class TestInf5class : public Test
//{
//public:
//	TestInf5class():Test()
//	{
//		questions = {
//			Question("Microsoft Word - це", {"текстовый процесcор", "графічний редактор", "редактор презентацій"}, 1),
//			Question("Які клавіши потрібно використати, щоб видалити зайвий символ?", {"Shift", "Backspace", "Delete"}, 2),
//			Question("За допомогою сполучення клавіш Сtrl+X фрагмент тексту можна...", {"Вирізати", "Вставити", "Знайти"}, 3),
//			Question("За допомогою сполучення клавіш Ctrl+С фрагмент тексту можна...", {"Вставити", "Копіювати", "Виділити"}, 2),
//			Question("Частина тексту, набирання якого закінчується натисканням клавіші Enter називається:", {"Слово","Речення","Абзац"},3),
//			Question("Ширина й висота сторінки - це: ", {"Поля","Розміри сторінки","Орієнтація сторінки"},2),
//			Question("Перед розділовими знаками (такими як ;:.,!?) пропуск", {"не ставиться","ставиться","залежно від тексту"},2),
//			Question("Для введення тексту з нового абзацу слід натиснути клавішу ", {"Enter","Ctrl", "Shift"},1),
//			Question("Натиснувши сполучення клавіш Сtrl+A виділиться: ", {"слово", "рядок", "весь документ"},3),
//			Question("За допомогою сполучення клавіш Ctrl+V фрагмент тексту можна...", {"вирізати", "вставити", "копіювати"}, 2),
//			Question("Які види орієнтації сторінки бувають?", {"горизонтальна","вертикальна","книжкова"},3),
//			Question("За допомогою клавіші Delete можна вилучити символ, який знаходиться....", {"знизу під курсором", "ліворуч над курсором", "праворуч від курсора"}, 2)
//		};
//	}
//	
//};

