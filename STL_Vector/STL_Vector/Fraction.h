#pragma once
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
class Calculator;
class Fraction
{
	long m_main=0;
	short m_frac=0;
	static short denominator(short a, short b);
	static int NOD(int a, int b);
	void cut();
public:
	Fraction(){}
	Fraction(long m, short f)
	{
		SetFraction(m, f);
	}
	Fraction(char s[])
	{
		char* p = strchr(s, '/');
		int a = atoi(p+1);
		SetFraction(atoi(s),a);
	}
	friend ostream& operator<<(ostream& out, const Fraction& f)
	{
		if (f.m_main == 0)
		{
			out << 0;
		}
		else
		{
			if (f.m_frac == 1)
		    {
			    out << f.m_main;
		    }
		    else
		    {
			    out << f.m_main << "/" << f.m_frac;
		    }  			
		}
		return out; 		
	} 
	friend istream& operator>>(istream& in, Fraction& f)
	{
		cout << "\nInput numerator: ";
		in >> f.m_main;
		cout << "\nInput denominator: ";
		in >> f.m_frac;
		if (f.m_frac == 0)
		{
			throw exception("Деление на нуль!!!");
		}
		return in;
	}
	void SetFraction(long n,short d)
	{
		if (d == 0)
		{
			throw exception("Деление на нуль!!!");
		}
		m_main = n;
		m_frac = d;
	}
	void operator=(const Fraction& f)
	{
		m_main = f.m_main;
		m_frac = f.m_frac;
	}
	friend Fraction operator*(int a,const Fraction& f)
	{
		long M = f.m_main * a;
		Fraction temp(M, f.m_frac);
		temp.cut();
		return temp;
	}
	friend Fraction operator/(const Fraction& f, const Fraction& g)
	{
		short F = f.m_frac * short(g.m_main);
		long M = f.m_main * long(g.m_frac);
		Fraction temp(M, F);
		temp.cut();
		return temp;
	}
	friend Fraction operator/(const Fraction& f, int a)
	{
		short F = f.m_frac * short(a);
		Fraction temp(f.m_main, F);
		temp.cut();
		return temp;
	}
	friend Fraction operator/( int a,const Fraction& f)
	{
		short F = f.m_frac * short(a);
		Fraction temp(F,static_cast<short>(f.m_main));
		temp.cut();
		return temp;
	}
	friend bool operator==(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main==short(ComDen) / g.m_frac * g.m_main;
	}
	friend bool operator!=(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main != short(ComDen) / g.m_frac * g.m_main;
	}
	friend bool operator>(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main >short(ComDen) / g.m_frac * g.m_main;
	}
	friend bool operator<(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main < short(ComDen) / g.m_frac * g.m_main;
	}
	friend bool operator>=(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main >= short(ComDen) / g.m_frac * g.m_main;
	}
	friend bool operator<=(const Fraction& f, const Fraction& g)
	{
		short ComDen = denominator(f.m_frac, g.m_frac);
		return short(ComDen) / f.m_frac * f.m_main <= short(ComDen) / g.m_frac * g.m_main;
	}
	friend Fraction operator+(const Fraction& f, const Fraction& g);
	friend Fraction operator+(const Fraction& f, int a);
	friend Fraction operator+(int a, const Fraction& f);
	friend Fraction operator-(const Fraction& f, int a);
	friend Fraction operator-(int a, const Fraction& f);
	friend Fraction operator-(const Fraction& f, const Fraction& g);
	friend Fraction operator*(const Fraction& f, const Fraction& g);
	friend Fraction operator*(const Fraction& f, int a);
	friend class Calculator;
};

