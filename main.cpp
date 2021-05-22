#include "Functions.h"
int _stateMenu;
void Menu()
{
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы" << endl
        << "(1) Ввод данных" << endl
        << "(2) Вывод данных" << endl
        << "(3) Изменение данных" << endl
        << "(4) Удаление данных" << endl
        << "(5) Добавление данных" << endl
        << "(6) Сохранение данных" << endl
        << "(7) Cортировка" << endl;
    cin >> _stateMenu;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DataInitialization();

	Menu();
    int  _actions;
    string fileName;
    int _size = 0;
    Data* d = new Data[_size];
    while (_stateMenu != 0)
    {
        switch (_stateMenu)
        {
        case 1:
            system("cls");
            cout << "Ввести данные вручную (1) или из файла (2)? ";
            cin >> _actions;
            system("cls");
            if (_actions == 1)
            {
                DataEntry();
            }
            else if (_actions == 2)
            {
                cout << "Название файла ";
                cin >> fileName;
                system("cls");
                DataReading(fileName);
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");
            cout << "Название файла ";
            cin >> fileName;
            Print(fileName);

            system("pause");
            system("cls");
            Menu();
            break;
        case 3:
            system("cls");

            DataChange();

            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");

            DeleteData();

            system("pause");
            system("cls");
            Menu();
            break;
        case 5:
            system("cls");

            AddData();

            system("pause");
            system("cls");
            Menu();
            break;
        case 6:
            system("cls");

            cout << "введите название файла ";
            cin >> fileName;

            system("cls");

            SaveData(fileName);

            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            int n;
            system("cls");
            cout << "По скольки сессиям отсортировать данные? ";
            cin >> n;
            DataReading(d, _size);
            SortingData(d, _size);
            SaveData(d, _size);
            Print("Buffer.txt");
            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Неправильно выбран пункт меню" << endl;
            break;
        }

    }
    system("cls");
    if (DataCleaning())
        cout << "Данные очищены" << endl;
    else
        cout << "Данные НЕ очищены";
    cout << "Работа завершена";
    system("pause");

}

