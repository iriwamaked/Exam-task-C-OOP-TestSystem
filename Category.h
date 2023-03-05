#pragma once
#include"Test.h"
#include<map>
#include<filesystem>
namespace fs = std::filesystem;
class Category
{
    string category_name;
    string concrete_test_name;
    int number_of_categories=0;
    Test* test;
    map<string, vector<string>> tests;
public:
    //� ������������ ��������� ��� ��������� � �����, ������� ���� � ����� "Categories", � map
    Category(const string& dir_path = "Categories");
 
    //����� ��� ������ ���������� ���������
    string ChoiceCategories();
    //����� ��� ������ ����������� ����� 
    string ChoiceTest();
 
    //�������� ��� ��������� � �����
    void ShowCategories();

    void AddCategory(string CategoryName)
    {
        /*string line;
        cout << "\n\t������� �������� ���������: ";
        getline(cin, line);
        cin.ignore(1, '\n');*/
        // ���������, ��� ��������� � ����� ������ ��� �� ����������
            if (tests.find(CategoryName) == tests.end()) {
                tests.insert({CategoryName, {} }); // ��������� ��������� � map � ������ �������� ������
                ++number_of_categories;
                // ������� ��������������� ����� � ���������� "Categories"
                fs::create_directory("Categories/" + CategoryName);
                cout << "\n\t��������� " << CategoryName << " ������� ���������!" << endl;
            }
            else 
            {
                cout << "\n\t��������� " << CategoryName << " ��� ����������." << endl;
            }
    }
    void AddTestToCategory(string CategoryName, string TestName)
    {
        AddCategory(CategoryName);
        string category_path = "Categories/" + CategoryName;

        string test_path = category_path + "/" + TestName + ".txt";
        std::ofstream file(test_path); // ������� ����� ����

        if (file.is_open()) {
            // ���� ������� ������
            file.close(); // ��������� ����
            // ��������� �������� ����� � ������ ��������������� ��������� � map
            tests[category_name].push_back(TestName);
        }
        else {
            // ��������� ������ ��� �������� �����
            throw std::runtime_error("Failed to create test file");
        }
        test->AddTest(CategoryName, TestName);
    }
};

