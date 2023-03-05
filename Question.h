#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<filesystem>
namespace fs = std::filesystem;
using namespace std;
class Question
{
	string _question;
	vector<string> _answer;
	int _correctAnswerID;
public:
	Question(): _question(""), _answer(std::vector<string>(3)), _correctAnswerID(0){}
	Question(string question, vector<string> answer, int corrrectAnswerID):_question(question),
		_answer(answer), _correctAnswerID(corrrectAnswerID){}
	void SetQuestion(string question) { _question = question; }
	void SetAnswer(vector<string> answer) { _answer = answer; }
	/*void SetAnswers(int i, string answer) { _answer[i] = answer; }*/
	void SetCorrectAnswer(int correct) { _correctAnswerID = correct; }
	string GetQuestion() { return _question; }
	vector<string> GetAnswers() { return _answer; }
	int GetCorrectAnswerID() { return _correctAnswerID; }
	void SaveQuestion();
	
};

ostream& operator<<(ostream& out, Question obj);

istream& operator>>(istream& in, Question &obj);