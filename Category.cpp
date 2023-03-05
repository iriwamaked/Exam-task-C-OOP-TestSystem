#include "Category.h"

Category::Category(const string& dir_path)
{
    {
        for (const auto& entry : fs::directory_iterator(dir_path)) { // �������� �� ���� ��������� ����������
            if (entry.is_directory()) { // ���� ��� �����
                string category_name = entry.path().filename().string();
                tests[entry.path().filename().string()]; // ��������� �� � map � ������ ��������
                ++number_of_categories;
                for (const auto& t : fs::directory_iterator(entry.path()))
                {
                    if (t.is_regular_file())
                    { // ���� ��� ����
                        string filename = t.path().stem().string(); // �������� �������� ����� ��� ����������
                        string extension = t.path().extension().string(); // �������� ���������� �����
                        if (extension == ".txt")
                        { // ���� ���������� .txt
                            // ������� ������������ �����, ������� �������� ����������
                            string category_name = entry.path().filename().string();
                            // ��������� �������� ����� � ������ ��������������� ��������� � map
                            tests[category_name].push_back(filename);
                        }
                    }
                }
            }
        }
    }
}

string Category::ChoiceCategories()
{
    vector<string> categories;
    int i = 0;
    cout << "\n\t��������� ���������: " << endl;
    for (const auto& pair : tests) {
        cout << "\n\t" << ++i << ". " << pair.first << endl;
        categories.push_back(pair.first);
    }
    int choice;
    cout << "\n�������� ���������: ";
    cin >> choice;
    if (choice < 1 || choice > categories.size()) {
        throw out_of_range("Invalid category index");
    }
    string category_name = categories[choice - 1];
    return category_name;
}

string Category::ChoiceTest()
{
    for (const auto& pair : tests) {
        int i = 0;
        for (const auto& el : pair.second)
        {
            cout << "\n\t" << ++i << " " << el << ";" << endl;
        }
        cout << endl;
    }
    int choice;
    cout << "\n\t�������� ����: "; cin >> choice;
    string test_name;
    for (const auto& pair : tests) {
        int i = 0;
        for (const auto& el : pair.second)
        {
            if (choice<1 || choice>pair.second.size())
            {
                throw out_of_range("Invalid test index");
            }
            test_name = pair.second[choice - 1];
        }
    }
    return test_name;
}

void Category::ShowCategories()
{
    for (const auto& pair : tests) {
        cout << "Categories: " << pair.first << ": ";
        int i = 0;
        for (const auto& el : pair.second)
        {
            cout << "\n\t" << ++i << " " << el << ";" << endl;
        }
        cout << endl;
    }
}
