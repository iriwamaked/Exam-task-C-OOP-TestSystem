#include "Question.h"

ostream& operator<<(ostream& out, Question obj)
{
	out << obj.GetQuestion() << "\n";
	for (auto it : obj.GetAnswers()) out << it << "\n";
    out << "\n";
	out << obj.GetCorrectAnswerID() << "\n";
   /* out << "******";*/
	return out;
}

istream& operator>>(istream& in, Question& obj)
{
    string quest;
    vector<string> ans;
    int correct;

    // ��������� ������
    getline(in, quest);
    obj.SetQuestion(quest);

    // ��������� �������� �������
    string answer;
    while (getline(in, answer)) {
        if (answer.empty() /*|| isdigit(answer[0])*/) {
            break;  // ������������� ���� ��� ������� ������ ������ ��� �����
        }
        ans.push_back(answer);
    }
    obj.SetAnswer(ans);

    // ��������� ����� ����������� ������
    in >> correct;
    obj.SetCorrectAnswer(correct);

    // ��������� ������ �������� ������ ����� �����
    in.ignore(1, '\n');

    return in;
}

void Question::SaveQuestion()
{
    ofstream fout;
    fout.open("test2.txt", ios::app);
    fout << *this;
    fout.close();
}
