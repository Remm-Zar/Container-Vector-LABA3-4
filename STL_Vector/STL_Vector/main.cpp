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
public:
    bool operator()(T a, T b)
    {
        return a > b;
    }
};


int main()
{
    auto lam1 = [](int a) {return a > 4; };
    auto lam2 = [](Fraction a, Fraction b) {return a < b; };

    list<int> int_list = { 1, 2, 3 };
    // 1. ИСПРАВИТЬ КОД ВЕКТОРА ТАК, ЧТОБЫ СЛЕДУЮЩАЯ СТРОКА РАБОТАЛА
    Vector<int> int_vector(int_list.begin(), int_list.end());
    // 2. ПОСЧИТАТЬ ПРИ ПОМОЩИ АЛГОРИТМОВ ДВУМЯ СПОСОБАМИ СУММУ ЭЛЕМЕНТОВ В int_vector
    // 3. ДОБАВИТЬ В ВЕКТОР ФУНКЦИЮ emplace_back
    // http://www.cplusplus.com/reference/vector/vector/emplace_back/
    Vector<int> i = { 1,2,3,4,5,6,7,8,9 }, j = { 7,7,7,7,7 };
    Vector<char> c(6, 'h');
    Vector<Fraction> f(5);
    //<int>
    cout << "\nINT";
    cout << "\ninsert (1):\n";
    i.insert(i.begin() + 4, i.begin() + 1, i.end() - 1);
    i.resize(15);
    cout << i;
    i.pushBack(152);
    i.pushBack(1);
    i.pushBack(-45);
    i.pushBack(8);
    i.popBack();
    cout << "\nPushback()x4 popback() Result: "<<i<<"\n ascending Sort: ";
    Functor<int> fu;
    sort(i.begin(), i.end(), fu);
    cout << i;
    copy_if(j.begin(), j.begin() + 3, i.begin() + 3, lam1);
    cout << "\n copy_if: " << i;
    //<char>
    cout << "\nCHAR";
    c.pushBack('d');
    cout << "\nPushback(): "<<c;
    c[3] = 'w';
    Vector<char>::IT ch = Find_if(c.begin(), c.end(), lam1);
    cout << "\nFind_if result: " << *ch;
    //<Fraction>
    cout << "\nFRACTIONS:";
    Vector<Fraction>::IT f_beg = f.begin();
    while (f_beg != f.end())
    {
        cin >> *f_beg;
        ++f_beg;
    }
    Vector<Fraction>::IT fr = Max_element(f.begin(), f.end());
    cout << "\nMax_element result: " << *fr;
    fr = Min_element(f.begin(), f.end());
    cout << "\nMin_element result: " << *fr;
    sort(f.begin(), f.end(), lam2);
    cout << "\nDescending sort: " << f << "\nClear result: "; 
    f.clear();
    cout << f;   
    return 0;
   
}

