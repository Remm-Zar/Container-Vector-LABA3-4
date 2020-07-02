#include <iostream>
#include "Vector.h"
#include "Money.h"
#include "Fraction.h"
#include "Algorythm.h"
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
template<class T,class T2>
void copy_if(T begin, T end,T pos,T2& other)
{  
   
}

int main()
{
    auto lam1 = [](int a) {return a > 44; };
    auto lam2 = [](Fraction a, Fraction b) {return a < b; };
    Vector<int> i = { 6,4,9,3,0,11,1,6,8 };
    Vector<char> c(6, 'h');
    Vector<Fraction> f(5);
    Vector<Money> m(5);
    //<int>
    cout << "\ninsert (1):\n";
    i.insert(i.begin() + 4, i.begin() + 1, i.end() - 1);
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
    //<char>
    c.pushBack('d');
    cout << "\nPushback(): "<<c;
    c[3] = 'w';
    Vector<char>::IT ch = Find_if(c.begin(), c.end(), lam1);
    cout << "\nFind_if result: " << *ch;
    //<Fraction>
    Vector<Fraction>::IT f_beg = f.begin();
    while (f_beg != f.end())
    {
        cin >> *f_beg;
        ++f_beg;
    }
    Vector<Fraction>::IT fr = Max_element(f.begin(), f.end());
    cout << "\nMax_element result: " << *fr;
    sort(f.begin(), f.end(), lam2);
    cout << "\nDescending sort: " << f << "\nClear result: "; 
    f.clear();
    cout << f; 
    //<Money>
    Vector<Money>::IT m_beg = m.begin();
    while (m_beg != m.end())
    {
        cin >> *m_beg;
        ++m_beg;
    }
    m.insert(m.begin() + 3, Money(100, 00));
    cout << "\nInsert result: " << m;
    Vector<Money>::IT min = Min_element(m.begin(), m.end());
    cout << "\nmin element: " << *min;
    return 0;
   
}

