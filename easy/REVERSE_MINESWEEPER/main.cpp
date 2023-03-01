#include<iostream>
#include<string>
//#include"Windows.h"
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
//Функція для вводу поля
void inputField(vector <vector<char>>& other);
//Функція для пошуку мін 
void findMines(vector <vector<int>>& vecMines, vector <vector<char>>& otherfield);
//Вивід в консоль поля 
void Print(vector <vector<int>>& vecMines);



// Перевіряє, чи є координати (i, j) дійсними координатами на полі розміром (n, m)
bool isValid(int i, int j, int w, int h)
{
    return i >= 0 && i < w&& j >= 0 && j < h;
}
int main()

{

    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    int w, h;
    // cout << "w and h";
    cin >> w >> h;
    vector<vector<char>> field(h, vector<char>(w));
    // cout << "  Ініціалізуємо поле з мінами та порожніми клітинками \n Вводимо 'x'-міна, '.'- порожня клітинка \n";
    inputField(field);
    vector<vector<int>> arrMines(h, vector<int>(w, 0));

    // Знаходимо кількість сусідніх мін для кожної порожньої клітинки
    findMines(arrMines, field);
    // cout << "  Виводимо результат\n";
    Print(arrMines);
    return 0;
}

void inputField(vector<vector<char>>& other)
{
    for (int i = 0; i < other.size(); i++)
    {
        for (int j = 0; j < other[i].size(); j++)
        {

            cin >> other[i][j];
        }

    }
}
void findMines(vector <vector<int>>& vecMines, vector <vector<char>>& otherfield)
{
    // Розрахунок числа бомб навколо кожної клітинки

    for (int i = 0; i < otherfield.size(); i++)
    {
        for (int j = 0; j < otherfield[i].size(); j++)
        {
            if (otherfield[i][j] == 'x')
            {
                vecMines[i][j] = -1;      // Клітинка з бомбою позначається -1
                continue;
            }
            int count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (isValid(k, l, otherfield.size(), otherfield[0].size()) && otherfield[k][l] == 'x')
                    {
                        count++;
                        vecMines[i][j] = count;  // Клітинки навколо бомби позначаються 1
                    }
                }
            }

        }
    }

}

void Print(vector <vector<int>>& vecMines)
{

    // Виведення поля з символами
    //cout << "Результат: " << endl;
    for (int i = 0; i < vecMines.size(); i++)
    {
        for (int j = 0; j < vecMines[i].size(); j++)
        {

            if (vecMines[i][j] == -1)
            {
                cout << '.';
            }
            else if (vecMines[i][j] == 0)
            {
                cout << '.';
            }
            else
            {
                cout << vecMines[i][j];
            }


        }
        cout << endl;
    }
}
