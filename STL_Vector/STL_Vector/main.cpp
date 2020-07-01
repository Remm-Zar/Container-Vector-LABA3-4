#include <iostream>
#include "Vector.h"
#include <functional>
using namespace std;
template <class A>
class Func
{
public:
    bool operator()(A a)
    {
        return a < 0;
    }
};
template <typename T, class T1>
T* FF(T* begin, T* end, const T1& other)
{
    while (begin != end)
    {
        if (other(*begin))
        {
            return begin;
        }
    }
    return end;
}

bool F1(int a)
{
    return a > 0;
}
int main()
{
    Func<int> f4;
    auto lam = [](int a) {return a > 3; };
    int A[5] = { 1,3,2,4,3 };
    Vector<int> c{ 1,2,3,4,5,6,7,8 };
    int* x = FF((int*)c.begin(), (int*)c.end(), lam);
    cout << *x;

    return 0;
}

