#include <iostream>
#include "Vector.h"
#include "Fraction.h"
#include "Algorythm.h"
#include "malloc.h"
#include <list>
#include <functional>

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
        sum += a;
    }
    T Get()
    {
        return sum;
    }
};



int main()
{
    
    function<int(int)> h;
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
     int sum = 0;
     auto lam = [&](int a) {sum += a; };
     For_each(int_vector.begin(), int_vector.end(), lam);
     cout <<"\nResult 2: "<< sum;

    // 3. ДОБАВИТЬ В ВЕКТОР ФУНКЦИЮ emplace_back
    // http://www.cplusplus.com/reference/vector/vector/emplace_back/
     int_vector.emplace_back(10);
     cout << "\nint_vector.emplace_back(10): "<<int_vector;
     Vector<Fraction> f(3);
     for (auto i = f.begin(); i < f.end(); ++i)
     {
         cin >> *i;
     }
     f.emplace_back(1, 2);
     cout << " f.emplace_back(1, 2): "<<f << endl;
    
    return 0;  
}

