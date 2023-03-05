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
			cout << i << "\n\t������� ������ �����: ";
			getline(cin, QuestionText);
			q.SetQuestion(QuestionText);
			for (int j = 1; j < 4; j++)
			{
				string AnswerText;
				cout << "\n\t������� ������� ������ " << j << ": ";
				getline(cin, AnswerText);
				ans.push_back(AnswerText);
			}
			q.SetAnswer(ans);
			int correctAns;
			cout << "\n\t������� ���������� ����� (1-3): ";
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
			cout << "\n\t��������� ������� �������� �����";
	}

};

//class TestInf5class : public Test
//{
//public:
//	TestInf5class():Test()
//	{
//		questions = {
//			Question("Microsoft Word - ��", {"��������� ������c��", "��������� ��������", "�������� �����������"}, 1),
//			Question("�� ������ ������� �����������, ��� �������� ������ ������?", {"Shift", "Backspace", "Delete"}, 2),
//			Question("�� ��������� ���������� ����� �trl+X �������� ������ �����...", {"�������", "��������", "������"}, 3),
//			Question("�� ��������� ���������� ����� Ctrl+� �������� ������ �����...", {"��������", "��������", "�������"}, 2),
//			Question("������� ������, ��������� ����� ���������� ����������� ������ Enter ����������:", {"�����","�������","�����"},3),
//			Question("������ � ������ ������� - ��: ", {"����","������ �������","�������� �������"},2),
//			Question("����� ���������� ������� (������ �� ;:.,!?) �������", {"�� ���������","���������","������� �� ������"},2),
//			Question("��� �������� ������ � ������ ������ ��� ��������� ������ ", {"Enter","Ctrl", "Shift"},1),
//			Question("���������� ���������� ����� �trl+A ���������: ", {"�����", "�����", "���� ��������"},3),
//			Question("�� ��������� ���������� ����� Ctrl+V �������� ������ �����...", {"�������", "��������", "��������"}, 2),
//			Question("�� ���� �������� ������� �������?", {"�������������","�����������","��������"},3),
//			Question("�� ��������� ������ Delete ����� �������� ������, ���� �����������....", {"����� �� ��������", "������ ��� ��������", "�������� �� �������"}, 2)
//		};
//	}
//	
//};

