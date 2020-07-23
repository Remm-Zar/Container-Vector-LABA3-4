#include <iostream>
#include "Vector.h"
#include "Fraction.h"
#include "Algorythm.h"
#include "malloc.h"
#include <list>

using namespace std;
template<typename T>
class Functor
{
    T sum = 0;
public:
    Functor(){}
    template <class U>
    void operator()(U a)
    {
        // ИТЕРАТОР НАДО РАЗЫМЕНОВЫВАТЬ В АЛГОРИТМЕ, ЧТОБЫ НЕ ПЕРЕКЛАДЫВАТЬ НА ПОЛЬЗОВАТЕЛЯ
        // ЗАБОТЫ О ТОМ, ЧТО К НЕМУ МОЖЕТ ПРИЛЕТЕТЬ ОБЪЕКТ НЕПОНЯТНОГО ТИПА, ВОЗМОЖНО ЭТОТ
        // ФУНКТОР БЫЛ НАПИСАН ВООБЩЕ ДЛЯ ДРУГИХ ЦЕЛЕЙ И НИЧЕГО НЕ ДОЛЖЕН ЗНАТЬ ОБ ИТЕРАТОРАХ,
        // ПОЛЬЗОВАТЕЛЬ РАБОТАЕТ ТОЛЬКО СО СВОИМ ТИПОМ T
        sum += *a;
    }
    T Get()
    {
        return sum;
    }
};
template<typename T>
class Fu
{
public:
    bool operator()(T a)
    {
        return true;
    }
};


int main()
{
    list<int> int_list = { 1, 2, 3 }; 
    // 1. ИСПРАВИТЬ КОД ВЕКТОРА ТАК, ЧТОБЫ СЛЕДУЮЩАЯ СТРОКА РАБОТАЛА
     Vector<int> int_vector(int_list.begin(), int_list.end());

    // 2. ПОСЧИТАТЬ ПРИ ПОМОЩИ АЛГОРИТМОВ ДВУМЯ СПОСОБАМИ СУММУ ЭЛЕМЕНТОВ В int_vector
     //first way
     Functor<int> fu;
     fu=For_each(int_vector.begin(), int_vector.end(), fu);
     cout << "Result 1: "<<fu.Get();
     //second way
     // ВТОРОЙ СПОСОБ ЗАКЛЮЧАЕТСЯ В ИСПОЛЬЗОВАНИИ ДРУГОГО ФУНКЦИОНАЛЬНОГО ОБЪЕКТА И
     // ТОГО ЖЕ АЛГОРИТМА For_each
     // У ТЕБЯ ОЧЕНЬ СЛОЖНЫЙ СПОСОБ ПОЛУЧИЛСЯ, ПРОЩЕ ЗАПУСТИТЬ ЦИКЛ БЕЗ АЛГОРИТМА И
     // ПОСЧИТАТЬ, НО НАМ СЕЙЧАС ТАК НЕ НАДО
     Fu<int> fu1;
     Vector<int>::IT begin = int_vector.begin(), end = int_vector.end();
     int Sum = 0;
     while (begin != end)
     {
         Sum += *Find_if(begin, end, fu1);
         ++begin;
     }
     cout << "\nResult 2: "<<Sum;

    // 3. ДОБАВИТЬ В ВЕКТОР ФУНКЦИЮ emplace_back
    // http://www.cplusplus.com/reference/vector/vector/emplace_back/
     // emplace_back ПРИНИМАЕТ АРГУМЕНТЫ КОНСТРУКТОРА, ДЛЯ СОЗДАНИЯ ОБЪЕКТА,
     // КОТОРЫЙ ХРАНИТСЯ В ВЕКТОРЕ. ТО ЕСТЬ ЕСЛИ В ВЕКТОРЕ ЛЕЖИТ ТИП Т,
     // ТО В emplace_back(a, b, c) ВЫЗЫВАЕТСЯ КОНСТРУКТОР Т(a, b, c),
     // ПОЭТОМУ В ЭТОЙ ФУНКЦИИ НЕ НАДО ВЫДЕЛЯТЬ ПЕРВЫЙ АРГУМЕНТ, ЭТО ВСЁ АРГУМЕНТЫ
     // ДЛЯ ОДНОГО ОБЪЕКТА
     // КРОМЕ ТОГО, В АРГУМЕНТЕ emplace_back - УНИВЕРСАЛЬНАЯ ССЫЛКА И НАДО ИСПЛЬЗОВАТЬ
     // ЕЁ ПРЕИМУЩЕСТВА ДЛЯ ИЗБЕЖАНИЯ ЛИШНИХ КОПИРОВАНИЙ, ЕСЛИ БУДЕТ ПЕРЕДАВАТЬСЯ
     // rvalue
     // И ЕЩЁ, ЧТОБЫ МАКСИМАЛЬНО ИСПОЛЬЗОВАТЬ ВСЕ ПРЕМУЩЕСТВА ПЕРЕНОСА, НАДО НАПИСАТЬ
     // ФУНКЦИЮ push_back С АРГУМЕНТОМ rvalue И ЭТА ФУНКЦИЯ ДОЛЖНА ВЫЗЫВАТЬСЯ ИЗ emplace_back
     // ДЛЯ ВСТАВКИ НОВОГО ОБЪЕКТА
     int_vector.emplace_back(4,5,6);
     cout << "\n"<<int_vector;
     int_vector.emplace_back(56,4,78,9,10);
     cout << "\n" << int_vector;
    return 0;  
}

