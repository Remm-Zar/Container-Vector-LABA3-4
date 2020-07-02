#pragma once
template <typename T, class T1>
// other ПЕРЕДАЁТСЯ ПО ЗНАЧЕНИЮ
T Find_if(T begin, T end, T1& other)
{
    while (begin != end)
    {
        if (other(*begin))
        {
            return begin;
        }
        ++begin;
    }
    return end;
}
template<class T>
T Min_element(T begin, T end)
{
    bool YES = false;
    T Min = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin < *Min)
        {
            YES = true;
            Min = begin;
        }
        ++begin;
    }
    // YES - ЛИШНЯЯ ПЕРЕМЕННАЯ, МИНИМАЛЬНОЕ ЧИСЛО ВСЕГДА НАЙДЁТСЯ,
    // ЕСЛИ КОНТЕЙНЕР НЕ ПУСТОЙ
    // НАДО ВСЕГДА ВОЗВРАЩАТЬ Min, У НЕГО ЖЕ ВСЕГДА ЕСТЬ ЗНАЧЕНИЕ
    if (YES)return Min;
    else return end;
}
template<class T>
T Max_element(T begin, T end)
{
    bool YES = false;
    T Max = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin > * Max)
        {
            YES = true;
            Max = begin;
        }
        ++begin;
    }
    if (YES)return Max;
    else return end;
}

// For_each ВОЗВРАЩАЕТ ЗНАЧЕНИЕ
// http://www.cplusplus.com/reference/algorithm/for_each/?kw=for_each
template<class T, class T1>
void For_each(T begin, T end, T1& other)
{
    while (begin != end)
    {
        other(begin);
        ++begin;
    }
}
template<class T, class T2>
void sort(T begin, T end, T2& other)
{
    while (end - begin != (end - begin) / 2)
    {
        T cur = begin, c_end = end - 1;
        ++end;
        while (c_end != cur)
        {
            if (other(*cur, *c_end))
            {
                T t = end;
                *t = *cur;
                *cur = *c_end;
                *c_end = *t;
            }
            --c_end;
        }
        ++begin;
    }
}

// ТОЖЕ ВОЗВРАЩАЕТ ЗНАЧЕНИЕ
// http://www.cplusplus.com/reference/algorithm/copy_if/?kw=copy_if
template<class T, class T2>
void copy_if(T begin, T end, T pos, T2& other)
{
    while (begin != end)
    {
        if (other(*begin))
        {
            *pos = *begin;
            ++pos;
        }
        ++begin;
    }
}
