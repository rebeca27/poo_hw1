#include "pch.h"
#include "BigInteger.h"

BigInteger::BigInteger()
{
}

BigInteger::BigInteger(const char* numberSequence)
{
	this->numberSequence = (char*)numberSequence;
	this->base = 10;
	this->isUnsigned = numberSequence[0] != '-';
}

BigInteger::BigInteger(const char* numberSequence, int base)
{
	this->numberSequence = (char*)numberSequence;
	this->base = base;
	this->isUnsigned = numberSequence[0] == '-';
}

BigInteger::~BigInteger()
{
	delete this->numberSequence;
	delete &this->base;
	delete &this->isUnsigned;
}

int BigInteger::getBase()
{
	return this->base;
}

char BigInteger::getSign()
{
	return this->isUnsigned ? '+' : '-';
}

char* BigInteger::toString()
{
	return this->numberSequence;
}

const int base = 10;

BigInteger BigInteger :: Integer(char a[])                  //returneaza forma string a unui numar
{
	string r = "";
	for(i = 0; i <= strlen(a) - 1; i++) 
		r = r + a[i];
	return r;
}

void BigInteger :: Set(BigInteger &bi)             //se repeta structura while de cate ori vectorul are mai mult de 1 elem,
				     //dar referinta ultimului element din vector este primul	
	
{
	while (bi.size() > 1 && bi.back() == 0) bi.pop_back();
}

BigInteger BigInteger :: Integer(string s) 
{
	BigInteger lol;
	if (s[0] == '-') return lol;				//daca nuamrul este negativ se intoarce
	if (s.size() == 0) 
	{ lol.push_back(0); 
	return lol; 
	}
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = 0; i < s.size(); i += 9) {
		int v = 0;
		for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
		lol.insert(lol.begin(), v);
	}
	Set(lol);
	return lol;
}

BigInteger BigInteger :: Integer(char ch[]) 
{
	string s = "";
	for(i = 0; i <= strlen(ch) - 1; s = s + ch[i]; i++)
	return Integer(s);
}

BigInteger BigInteger :: Integer(b x)
{
	string r = "";
	while (x > 0)
		r = char(x % 10 + '0') + r, x /= 10;
	return Integer(r);
}

BigInteger BigInteger :: Integer(int x)
{
	return Integer((b)x);
}

void BigInteger :: operator ++() 
    { 
        count = count+1; 
    }

void BigInteger :: operator --() 
    { 
        count = count-1; 
    }

void BigInteger :: operator >> (istream &in, BigInteger &a)
{
	string s;
	getline(cin, s);
	a = Integer(s);
}

void BigInteger :: operator << (ostream &out, BigInteger a)
{
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	for(i = a.size() - 2; i >= 0; i--)
		std::cout << a[i]; 
	std::cout << '\n';
}

bool BigInteger :: operator < (BigInteger x, BigInteger y)
{
	Set(x);
	Set(y);
	if (x.size() != y.size())
		return (x.size() < y.size());
	for (int i = x.size() - 1, i >= 0; i--)
		if (x[i] != y[i])
			return (x[i] < y[i]);
	return false;
}

bool BigInteger :: operator > (BigInteger a, BigInteger b) 
{
	return (b < a);
}

bool BigInteger :: operator == (BigInteger a, BigInteger b)
{
	return (!(a < b) && !(b < a));
}

bool BigInteger :: operator <= (BigInteger a, BigInteger b) 
{
	return (a < b || a == b);
}

bool BigInteger :: operator >= (BigInteger a, BigInteger b)
{
	return (b < a || b == a);
}

bool BigInteger :: operator < (BigInteger a, int b) 
{
	return (a < Integer(b));
}

bool BigInteger :: operator > (BigInteger a, int b) 
{
	return (a > Integer(b));
}

bool BigInteger :: operator == (BigInteger a, int b)
{
	return (a == Integer(b));
}

bool BigInteger :: operator >= (BigInteger a, int b)
{
	return (a >= Integer(b));
}

bool BigInteger :: operator <= (BigInteger a, int b)
{
	return (a <= Integer(b));
}

BigInteger maxim(BigInteger a, BigInteger b)
{
	if (a > b) return a;
	return b;
}

BigInteger BigInteger :: minim(BigInteger a, BigInteger b) 
{
	if (a < b) return a;
	return b;
}

BigInteger BigInteger :: operator + (BigInteger a, BigInteger b)
{
	Set(a);
	Set(b);
	BigInt lol;
	int rest = 0;
	int j = max(a.size(), b.size());
 	for(int i = 0; i <= j - 1; i++) 
	{
		if (i < a.size()) rest += a[i];
		if (i < b.size()) rest += b[i];
		lol.push_back(rest%base);
		rest /= base;
	}
	if (rest) 
		bas.push_back(rmd);
	Set(lol);
	return lol;
}

BigInteger BigInteger :: operator + (BigInteger a, int b)
{
	return a + Integer(b);
}

BigInteger BigInteger :: operator ++ (BigInteger &a) 
{ 
	a = a + 1;
	return a;
}

void BigInteger :: operator += (BigInteger &a, BigInteger b)
{
	a = a + b;
}

void BigInteger :: operator += (BigInteger &a, int b) 
{
	a = a + b;
}

BigInteger BigInteger :: operator - (BigInteger a, BigInteger b) 	//rmd=remainder
{
	Set(a);
	Set(b);
	BigInteger lol;
	int rmd = 0; 
	for(i = 0; i <= a.size() - 1; i++)
	{
		rmd += a[i] - (i < b.size() ? b[i] : 0);
		if (rmd < 0)
			lol.push_back(rmd + base), rmd = -1;
		else lol.push_back(rmd), rmd = 0;
	}
	Set(lol);
	return lol;
}

BigInteger BigInteger :: operator - (BigInteger a, int b)
{
	return a - Integer(b);
}

void BigInteger :: operator -- (BigInteger &a) 
{ 
	a = a - 1;
}

void BigInteger :: operator -= (BigInteger &a, BigInteger b) 
{
	a = a + b;
}

void BigInteger :: operator -= (BigInteger &a, int b) 
{
	a = a - b;
}


BigInteger BigInteger :: operator * (BigInteger t, BigInteger b)
{
	Set(t);
	Set(b);
	BigInteger lol;
	lol.assign(t.size() + b.size(), 0);
	for (i = 0; i <= t.size() - 1; i++)
	{
		a carry = 0ll;
		for (int j = 0; j < b.size() || rmd > 0; j++)
		{
			a s = lol[i + j] + rmd + (a)t[i] * (j < b.size() ? (a)b[j] : 0ll);
			lol[i + j] = s % base;
			rest = s / base;
		}
	}
	Set(lol);
	return lol;
}

BigInteger BigInteger :: operator * (BigInteger a, int b)
{
	return a * Integer(b);
}

void BigInteger :: operator *= (BigInteger &a, BigInt b) 
{
	a = a * b;
}

void BigInteger :: operator *= (BigInteger &a, int b) 
{
	a = a * b;
}


BigInteger BigInteger :: operator / (BigInteger a, BigInteger b) 
{
	Set(a);
	Set(b);
	if (b == Integer(0)) return Integer("-1");
	BigInteger lol, ent;

	for (int i = a.size() - 1; i >= 0; i--)
	{
		cur.insert (cur.begin(), a[i]);
		int x = 0, L = 0, R = base;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (b*Integer(mid) > ent)
			{
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		ent = ent - Integer (x - 1) * b;
		ans.insert (ans.begin(), x - 1);
	}
	Set(lol);
	return lol;
}

BigInteger BigInteger :: operator / (BigInteger t, int b) 
{
	Set(t);
	BigInteger lol;
	t ent = 0ll;
	for(i = t.size() - 1; i >= 0; i--)
	{
		ent = (ent*(a)base + (a)t[i]);
		lol.insert(lol.begin(), ent / b);
		ent %= b;
	}
	Set(lol);
	return lol;
}

void  BigInteger :: operator /= (BigInteger &a, BigInteger b) {
	a = a / b;
}

void BigInteger :: operator /= (BigInteger &a, int b) {
	a = a / b;
}


BigInteger BigInteger :: operator % (BigInteger a, BigInteger b)
{
	Set(a);
	Set(b);
	if (b == Integer(0)) return Integer("-1");
	BigInteger lol;
	for(i = a.size() - 1; i >= 0; i--)
	{
		lol.insert(lol.begin(), a[i]);
		int x = 0, L = 0, R = base;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (b*Integer(mij) > lol) {
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		lol = lol - Integer(x - 1)*b;
	}
	Set(lol);
	return lol;
}

int BigInteger :: operator % (BigInteger a, int b)
{
	Set(a);
	if (b == 0) return -1;
	int gcc = 0;
	for (i = a.size() - 1; i >= 0; i--)
		gcc = (gcc * (base % b ) + a[i] % b ) % b;
	return gcc;
}

void BigInteger :: operator %= (BigInteger &a, BigInteger b) {
	a = a % b;
}

void BigInteger :: operator %= (BigInteger &a, int b) {
	a = a % Integer(b);
}
