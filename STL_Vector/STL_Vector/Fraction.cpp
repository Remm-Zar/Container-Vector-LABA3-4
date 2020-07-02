#include "Fraction.h"
inline short Fraction::denominator(short a, short b)
{
	return a * b / short(NOD(a, b));
}
 inline int Fraction::NOD(int a, int b)
{
	if (a < 0)
	{
		a = -a;
	}
	if (a == b)
	{
		return a;
	}
	else
	{
		return a > b ? NOD(b, a - b) : NOD(a, b - a);
	}
}
inline void Fraction::cut()
{
	if (!m_main == 0)
	{
		int delim = NOD(int(m_main), int(m_frac));
		m_main /= delim;
	    m_frac /= delim;
	}	
}
 Fraction operator+(const Fraction& f, const Fraction& g)
{
	short ComDen = Fraction::denominator(f.m_frac, g.m_frac);
	long M = short(ComDen) / f.m_frac * f.m_main + short(ComDen) / g.m_frac * g.m_main;
	Fraction temp(M, ComDen);
	temp.cut();
	return temp;
}
 Fraction operator+(const Fraction& f, int a)
 {
	 long M = f.m_main + a * f.m_frac;
	 Fraction temp(M, f.m_frac);
	 temp.cut();
	 return temp;
 }
 Fraction operator+(int a, const Fraction& f)
 {
	 long M = f.m_main + a * f.m_frac;
	 Fraction temp(M, f.m_frac);
	 temp.cut();
	 return temp;
 }
 inline Fraction operator-(const Fraction& f, int a)
 {
	 return f + (-a);
 }
  inline Fraction operator-(int a, const Fraction& f)
 {
	 return f + (-a);
 }
 Fraction operator-(const Fraction& f, const Fraction& g)
 {
	 short ComDen = Fraction::denominator(f.m_frac, g.m_frac);
	 long M = short(ComDen) / f.m_frac * f.m_main - short(ComDen) / g.m_frac * g.m_main;
	 Fraction temp(M, ComDen);
	 temp.cut();
	 return temp;
 }
 Fraction operator*(const Fraction& f, const Fraction& g)
 {
	 short F = f.m_frac * g.m_frac;
	 long M = f.m_main * g.m_main;
	 Fraction temp(M, F);
	 temp.cut();
	 return temp;
 }
 Fraction operator*(const Fraction& f, int a)
 {
	 long M = f.m_main * a;
	 Fraction temp(M, f.m_frac);
	 temp.cut();
	 return temp;
 }
