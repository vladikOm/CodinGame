
/*
Це в нас обозначені числа 
 **********************************************************************************************************
 * |  1  | 2  |  3 | 4  |  5 |  6 |  7 | 8  | 9  |10  |11  |12  | 13 |14  |15  | 16 |17  |18  |19  | 20 | *
 * |*****|****|****|****|****|****|****|****|****|****|****|****|****|****|****|****|****|****|****|****| *
 * |.oo. |o...|oo..|ooo.|oooo|....|o...|oo..|ooo.|oooo|____|o...|oo..|ooo.|oooo|____|o...|oo..|ooo.|oooo| *
 * |o..o |....|....|....|....|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____| *
 * |.oo. |....|....|....|....|....|....|....|....|....|....|____|____|____|____|____|____|____|____|____| *
 * |.... |....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|____|____|____|____| *
 **********************************************************************************************************
*/

/*
ЧИСЛА МАЙЯ 
//Для копіювання в консоль
.oo.o...oo..ooo.oooo....o...oo..ooo.oooo....o...oo..ooo.oooo....o...oo..ooo.oooo
o..o................____________________________________________________________
.oo.....................................________________________________________
............................................................____________________

*/
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<deque>
//#include"Windows.h"
using namespace std;
//string substr(string string, int start , int length )
//Повертає строку від start по length 
//void 

void  inputNumber(string& tempNumber, int& tempRow)
{
    
     //Вводимо кількість рядків
    //Проходимо по кожному рядку і встановлюємо наше перше число Mayan число
    
    for (int i = 0; i < tempRow; i++)
    {
        string  numberLine;
        cin >> numberLine;
        tempNumber.append(numberLine);
    }
}
void  inputNumbersMayan(vector<string>& tempNumbers, int hight, int lines)
{
    //cout << "Вводимо всі числа Майя :\n";
    for (int i = 0; i < hight; i++)
    {
        string numeral;
        cin >> numeral;

       for (int j = 0; j < 20; ++j)
       tempNumbers[j].append(numeral.substr(j * lines, lines));
    }

}

long long  convertInt(vector<string>& tempNumbers, int hight, int lines, string& Number)
{
    long long   ValueNumber = 0;  //Значення числа майя в int

    for (int j = 0; j < Number.size() / (hight * lines); ++j)
    {
        for (int i = 0; i < tempNumbers.size(); ++i)
        {
            if (tempNumbers[i] == Number.substr(j * hight * lines, hight * lines))
                ValueNumber += i * pow(20, (Number.size() / (hight * lines)) - j - 1);
        }
    }
    return  ValueNumber;
}

long int Calc(string& tempOperation, long long& number1, long long& number2)
{
    long long result = 0 ;
    if (tempOperation == "+")
        result = number1 + number2;
    if (tempOperation == "-")
        result = number1 - number2;
    if (tempOperation == "*")
        result = number1 * number2;
    if (tempOperation == "/")
        result = number1 / number2;

    return result;
}
int main()
{  // SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);
  
    vector<string> numbers(20);       //Вектор де будуть зберігатися числа 
    string number1, number2;          // Дві змінні для зберігання символів
    int rowsNumbers = 0;                  //Змінна яка прийматиме кількість рядків в числа кратна 4
    string operation;
    int L;
    int H;
   // cout << "L, H  :";
    cin >> L >> H;  
    //заповнюємо вектор числами мая
    inputNumbersMayan(numbers, H, L);
     //  Вводимо перше число()
    //cout << "Вводимо перше число майя\n";
     cin >> rowsNumbers; 
     inputNumber(number1, rowsNumbers);
      
     // вводимо 2 число 
     //cout << "Вводимо друге число майя\n";
     cin >> rowsNumbers;  
     inputNumber(number2, rowsNumbers);
       // вводимо операцію
     long long num1 = convertInt(numbers, H, L, number1);
     long long num2 = convertInt(numbers, H, L, number2);
    // cout << "Вводимо операцію для чисел {'+','-','/','8'}\n";
     cin >> operation;
     long int Result = Calc(operation, num1, num2);
     deque<long int> resultingNumbers{ Result};
     
        while (Result > 20)
        {
            resultingNumbers.pop_front();//Видаляє перший елемнт 
            //на початок встановлюємо остачу від ділення  5325 % 20 = 5
            resultingNumbers.push_front(Result % 20);
           //Потім встановлюємо ціле число на початок тобто 5325/20 = 266
            resultingNumbers.push_front(Result / 20);
            Result /= 20;
        }

        for (long long num : resultingNumbers)
        {
            for (int i = 0; i < H; ++i)
                cout << numbers[num].substr(i * L, L) << endl;
        }
    


    return 0;
}