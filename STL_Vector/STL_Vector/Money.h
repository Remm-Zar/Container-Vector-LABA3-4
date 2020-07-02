#pragma once
#include <iostream>
#include <initializer_list>
#include <cmath>
using namespace std;
class Money 
{
	long m_main = 0;//Rubles
	unsigned char m_k = 0;//kopeyki
public:
	Money() {};
	Money(long R, int k)
	{
		m_main = R;
		m_k = (unsigned char)k;
	}
	void print()const 
	{
		cout << m_main << "," << (int)m_k;
	}
	friend istream& operator>>(istream& in, Money& m)
	{
		cout << "\nInput Rubles: ";
		in >> m.m_main;
		cout << "\nInput Kopeyki: ";
		in >> m.m_k;
		return in;
	}
	bool SetSum(long R, int K)
	{
		if ((K < 0) || (R < 0))
		{
			return 1;
		}
		else
		{
			m_k = K % 100;
			m_main = R + K / 100;
		}
		return 0;
	}
	long GetRubles()const
	{
		return m_main;
	}
	unsigned char GetKopeyki()const
	{
		return m_k;
	}
	Money operator+(const Money& n)
	{
		unsigned char K = m_k + n.m_k;
		long R = m_main + n.m_main + K / 100;
		K = K % 100;
		return Money(R, K);
	}
	friend Money operator+(const Money& m, const Money& n)
	{
		unsigned char K = m.m_k + n.m_k;
		long R = m.m_main + n.m_main + K / 100;
		K = K % 100;
		return Money(R, K);
	}
	friend Money operator-(const Money& m, const Money& n)
	{
		int total = (m.m_main * 100 + m.m_k) - (n.m_main * 100 + n.m_k);
		long R = total / 100;
		unsigned char K = total % 100;
		return Money(R, K);
	}
	friend Money operator/(const Money& m, const Money& n)
	{
		double total = ((double)m.m_main * 100 + m.m_k) / ((double)n.m_main * 100 + n.m_k);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Money(R, K);
	}
	Money operator/(double n)
	{
		double total = ((double)m_main * 100 + m_k) / (n * 100);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Money(R, K);
	}
	bool operator==(const Money& m)
	{
		return (m_main * 100 + m_k == m.m_main * 100 + m.m_k);
	}
	bool operator!=(const Money& m)
	{
		return !(*this==m);
	}
	bool operator>(const Money& m)
	{
		return (m_main * 100 + m_k > m.m_main * 100 + m.m_k);
	}
	bool operator<(const Money& m)
	{
		return !((*this>m) || (*this==m));
	}
	bool operator>=(const Money& m)
	{
		return !(*this < m);
	}
	bool operator<=(const Money& m)
	{
		return !(*this>m);
	}	
	operator double()
	{
		return (double(m_main) * 100.0 + double(m_k)) / 100.0;
	}
	bool operator==(double n)
	{
		if (abs(double(*this) - n) < 0.00000001)
		{
			return true;
		}
		return false;
	}
	bool operator==(int n)
	{
		return (abs(double(*this) - n)<0.00000001);
	}
	friend class Account;
};
Money operator*(const Money& m, double n);
Money operator*(double n, const Money& m);
