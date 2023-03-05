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
    //В конструкторе считываем все категории и файлы, которые есть в папке "Categories", в map
    Category(const string& dir_path = "Categories");
 
    //Метод для выбора конкретной категории
    string ChoiceCategories();
    //Метод для выбора конкретного теста 
    string ChoiceTest();
 
    //Показать все категории и тесты
    void ShowCategories();

    void AddCategory(string CategoryName)
    {
        /*string line;
        cout << "\n\tВведите название категории: ";
        getline(cin, line);
        cin.ignore(1, '\n');*/
        // Проверяем, что категория с таким именем еще не существует
            if (tests.find(CategoryName) == tests.end()) {
                tests.insert({CategoryName, {} }); // Добавляем категорию в map с пустым вектором тестов
                ++number_of_categories;
                // Создаем соответствующую папку в директории "Categories"
                fs::create_directory("Categories/" + CategoryName);
                cout << "\n\tКатегория " << CategoryName << " успешно добавлена!" << endl;
            }
            else 
            {
                cout << "\n\tКатегория " << CategoryName << " уже существует." << endl;
            }
    }
    void AddTestToCategory(string CategoryName, string TestName)
    {
        AddCategory(CategoryName);
        string category_path = "Categories/" + CategoryName;

        string test_path = category_path + "/" + TestName + ".txt";
        std::ofstream file(test_path); // создаем новый файл

        if (file.is_open()) {
            // файл успешно создан
            file.close(); // закрываем файл
            // добавляем название файла в вектор соответствующей категории в map
            tests[category_name].push_back(TestName);
        }
        else {
            // произошла ошибка при создании файла
            throw std::runtime_error("Failed to create test file");
        }
        test->AddTest(CategoryName, TestName);
    }
};

