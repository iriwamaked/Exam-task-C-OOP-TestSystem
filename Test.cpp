#include "Test.h"


void Test::LoadQuestions(string nameCat, string testName)
{
	
	const string& dir_path = "Categories";

	// создаем путь к папке с категориями
	fs::path category_path = dir_path + "/" + nameCat;

	// проверяем, существует ли папка с категорией
	if (!fs::exists(category_path) || !fs::is_directory(category_path)) {
		cout << "Category " << nameCat << " does not exist." << endl;
		return;
	}
	string extention = testName+".txt";
	// создаем путь к файлу с тестом
	fs::path test_path = category_path / extention;;

	// проверяем, существует ли файл с тестом
	if (!fs::exists(test_path) || !fs::is_regular_file(test_path)) {
		cout << "Test " << testName << " does not exist in category " << nameCat << "." << endl;
		return;
	}


	ifstream fin(test_path);
	if (!fin.is_open()) {
		cout << "Could not open file" << testName << "for reading." << endl;
	}
	questions.clear();
	Question q1;
	while (fin >> q1)
	{
		questions.push_back(q1);
	}
	fin.close();
}

void Test::ShowQuestions()
{
	int i = 0;
	for (const auto& q : questions) {
		cout << ++i << " " << q << endl;
	}

	cout << "\nsize" << questions.size();
}

void Test::SaveTest()
{
	for (auto& q : questions)
	{
		q.SaveQuestion();
	}
}

void Test::GoTest()
{
	int numquest = 0;
	for (auto& q : questions)
	{
		cout << "\n\t" << ++numquest << ". " << q.GetQuestion() << endl;
		int numans = 0;
		for (auto it : q.GetAnswers())
			cout << "\t " << ++numans << ". " << it << endl;;
		int ans;
		cout << "\n\tВведите правильный ответ: "; cin >> ans;
		if (ans == q.GetCorrectAnswerID())
			rightAns++;
	}
}
