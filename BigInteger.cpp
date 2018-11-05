#include "pch.h"
#include<vector>
#include<string>
#include<string.h>
#include<stdexcept>
#include<algorithm>
#include<cstdlib>
#include <sstream>
#include <cmath>
#include "BigInteger.h"

BigInteger::BigInteger() // initializeaza vectorul cu 0
{
	val  = "0";
	is_unsigned = false;
}

BigInteger::BigInteger(int val, unsigned char base)
{
	int digit;
	bool isNegative = false;
	if (val < 0)
	{
		isNegative = true;
		val = val * (-1);
	}

	if (val == 0)
		digit.push_back(0);

	while (val != 0)
	{
		digit = val % 10;
		digit.push_back(digit);
		val = val / 10;
	}


	if (isNegative == true)
		sign = '-';
	else
		sign = '+';
	this->val = val;
	this->base = base;
}

BigInteger::BigInteger(long long int val, unsigned char base)
{

	if (val >= 0) sign = '+';
	else sign = '-';
	if (val == 0) val.push_back('0');

	val = std::abs(val);
	while (val != 0)
	{
		int a = val % 10;
		val.push_back(a + '0');
		val /= 10;
	}

	this->val = (long long int)val;
	this->base = 10;
}

BigInteger::BigInteger(const std::string& val, unsigned char base)
{
	if (val[0] == '-') sign = '-';
	else if (val[0] == '+')  sign = '+';
	else
		for (int i = 1; i < val.length; i++) {
			if (val[i] >= (int) '0' && val[i] <= (int) '9' || val[i] == '+' || val[i] == '-') {
				this->val[i] = val[i];
			}
			else {
				throw std::runtime_error("valoarea introdusa nu este un numar valid");
			}
		}

	for (int i = val.length() - 1; i >= 1; i--)
	{
		if (strchr("0123456789", val[i]) == NULL)
			throw std::runtime_error("stringul initial nu este un numar");
		val.push_back(val[i]);
	}

	this->val = (const std::string&)val;
	this->base = 10;
}

const string& BigInteger::getNumber() // intoarce numarul
{
	return number;
}

int BigInteger::getBase()
{
	return this->base;
}

char BigInteger::getSign()
{
	return this->is_unsigned ? '+' : '-';
}

void BigInteger:: setSign(bool s)
{
	sign = s;
}

BigInteger::~BigInteger()
{
	delete this->val;
	delete &this->base;
}

BigInteger BigInteger::Integer(char a[])                  //returneaza forma string a unui numar
{
	string r = "";
	for (i = 0; i <= strlen(a) - 1; i++)
		r = r + a[i];
	return r;
}

bool BigInteger::equals(BigInteger n1, BigInteger n2)
{
	return n1.getNumber() == n2.getNumber()
		&& n1.getSign() == n2.getSign();
}
bool BigInteger::less(BigInteger n1, BigInteger n2)
{
	bool sign1 = n1.getSign();
	bool sign2 = n2.getSign();

	if (sign1 && !sign2) // daca n1 este -ve si n2 este +ve
		return true;

	else if (!sign1 && sign2)
		return false;

	else if (!sign1) // amebele +ve
	{
		if (n1.getNumber().length() < n2.getNumber().length())
			return true;
		if (n1.getNumber().length() > n2.getNumber().length())
			return false;
		return n1.getNumber() < n2.getNumber();
	}
	else // ambele -ve
	{
		if (n1.getNumber().length() > n2.getNumber().length())
			return true;
		if (n1.getNumber().length() < n2.getNumber().length())
			return false;
		return n1.getNumber().compare(n2.getNumber()) > 0; 
	}
}
bool BigInteger::greater(BigInteger n1, BigInteger n2)
{
	return !equals(n1, n2) && !less(n1, n2);
}

BigInteger::BigInteger(long long a) {
	int n = 0;
	for (int i = 0; i < 250; i++) m[i] = 0;
	if (a >= 0) is_unsigned = true;		//se seteaza numarul ca fiind pozitiv daca este mai mare sau egal cu 0 sau
	else {
		is_unsigned = false;					//negativ altfel
		a *= (-1);							//dacă numarul este negativ, se obtine inversul lui și se continua să se citeasca numărul
	}
	while (a != 0) {						// se scrie numărul în matrice
		val[n] = a % 10;
		a /= 10;
		n++;
	}
}

// constructor din șir
BigInteger::BigInteger(const char *st) {
	n = 0;
	for (int i = 0; i < 250; i++) val[i] = 0;
	int l = strlen(st);								// lungimea șirului de citire
	char str[250];
	for (int i = 0; i < l; i++) str[i] = st[i];     // se copiaza sirul pe o linie noua

	if (str[0] == '-' || str[0] == '+') {         //daca se gaseste semn la inceput atunci daca e negativ  
		if (str[0] == '-') is_unsigned = false;		//variabila semnului pozitiv va primi valoarea negativa
		else sign = true;				//altfel daca e pozitiv variabila semnului pozitiv va primi valoarea pozitiva
		for (int i = 1; i < l; i++) {
			str[i - 1] = str[i];
		}
		l--;
	}
	else is_unsigned = true;					// dacă semnul nu este specificat, numărul este pozitiv
	int u = 0;								 // numărul de zerouri de la începutul șirului de citire
	for (int i = 0; i < l; i++) {			// se numara numărul de zerouri
		if (str[i] == '0') u++;
		else break;
	}
	if (u == l) {							// dacă linia are numai zerouri, se scrie numărul 0
		is_unsigned = true;
		val[0] = 0;
		n = 1;
	}
	else {									// dacă zerourile sunt doar la începutul numărului se sterg
		for (int i = u; i < l; i++) {
			str[i - u] = str[i];
		}
		l -= u;			// se seteaza lungimea
		while (l) {	// se scrie numărul în matrice
			val[n] = str[l - 1] - '0';
			n++;
			l--;
		}
	}
}

BigInteger :: operator ++()
{
	count = count + 1;
	return count;
}

BigInteger :: operator --()
{
	count = count - 1;
	return count;
}

BigInteger:: istream& operator >> (istream &in, BigInteger &A) {
	char str[250];										// string pentru a scrie caracterele
	stream >> str;										// citiți caracterele
	BigInteger B(str);
	A = B;
	return stream;
}

BigInteger:: ostream& operator << (ostream &out, const BigInteger &A)
{
	if (!A.signplus) out << '-';							//afisati semnul dacă numărul este negativ
	for (int i = A.n - 1; i >= 0; i--) out << A.m[i];
	return out;
}

int BigInteger:: compare(const BigInteger &A, const BigInteger &B) {
	if (A.n > B.n) return 1;			// comparând lungimea numerelor, dacă sunt diferite se returnează numarul mai mare
	else if (A.n < B.n) return 2;
	else {
		for (int i = A.n - 1; i > -1; i--) { //se compara numerele descrescator
			if (A.m[i] > B.m[i]) return 1;
			else if (B.m[i] > A.m[i]) return 2;
		}
		return 0;					// daca nu se gasesc diferențe numerele raman la fel
	}
}

BigInteger BigInteger:: operator ^ (const BigInt & base, int exp)
{
	BigInt result;
	if (exponent == 0)
	{
		result.val.push_back(1);
		return result;
	}
	for (i = 0; i < exp; i++)
		result *= base;
	return result;
}

bool BigInteger :: operator < (BigInteger b)
{
	return less((*this), b);
}

bool BigInteger :: operator > (BigInteger b)
{
	return greater((*this), b);
}

bool BigInteger :: operator == (BigInteger a, BigInteger b)
{
	return (!(a < b) && !(b < a));
}
bool BigInteger:: operator == (BigInteger b)
{
	return equals((*this), b);
}

bool BigInteger :: operator <= (BigInteger a, BigInteger b)
{
	return (a < b || a == b);
}

bool BigInteger::operator <= (BigInteger b)
{
	return equals((*this), b)
		|| less((*this), b);
}
bool BigInteger :: operator >= (BigInteger a, BigInteger b)
{
	return (b < a || b == a);
}

bool BigInteger::operator >= (BigInteger b)
{
	return equals((*this), b)
		|| greater((*this), b);
}

BigInteger BigInteger:: maxim(BigInteger a, BigInteger b)
{
	if (a > b) return a;
	return b;
}

BigInteger BigInteger::minim(BigInteger a, BigInteger b)
{
	if (a < b) return a;
	return b;
}

BigInteger BigInteger::operator+(const BigInteger &A) const {
	BigInteger V;
	V.n = max(A.n, n);
	int r = 0;
	if ((A.is_unsigned&&is_unsigned) || ((!A.is_unsigned) && (!is_unsigned))) {
		for (int i = 0; i < V.n; i++) {
			V.m[i] = m[i] + A.m[i] + r;
			if (V.m[i] >= 10) {
				r = 1;
				V.m[i] -= 10;
			}
			else r = 0;
		}
		if (r > 0) {
			V.n++;
			V.m[V.n - 1] = r;
		}
		if (!A.is_unsigned && !is_unsigned) V.is_unsigned = false;
	}
	else {//dacă semnele sunt diferite, scade de la cele mai mari la cele mai mici 

		int y = compare(*this, A);
		if (y == 1) {								// dacă primul este mai mult decât al doilea
			V.n = n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = m[i] - A.m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.is_unsigned = is_unsigned;
		}
		else if (y == 2) {					// dacă al doilea este mai mare decât primul
			V.n = A.n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = A.m[i] - m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.is_unsigned = A.is_unsigned;
		}
		else if (y == 0) {		//daca numerele sunt egale atunci setate la zero
			V.n = 1;
			V.m[0] = 0;
		}
	}
	return V;
}

BigInteger BigInteger::operator+(long long a) const {
	BigInteger A(a);
	return *this + A;
}

BigInteger BigInteger:: operator+(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V + A;
}

BigInteger BigInteger::operator+=(const BigInteger &A) {
	*this = *this + A;
	return *this;
}

BigInteger BigInteger:: operator+=(long long a) {
	BigInteger A(a);
	*this = *this + A;
	return *this;
}

BigInteger BigInteger::operator-(const BigInteger &A) const { //se schimba semnul -> se transforma in opusul lui si se trateaza cazul pozitiv
	BigInteger N1 = A;
	if (N1.is_unsigned) N1.is_unsigned = false;
	else N1.is_unsigned = true;
	return *this + N1;
}

BigInteger BigInteger::operator-(long long a) {
	BigInteger A(a);
	return *this - A;
}

BigInteger operator-(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V - A;
}

BigInteger BigInteger::operator-=(const BigInteger &A) {
	*this = *this - A;
	return *this;
}

BigInteger BigInteger::operator-=(long long a) {
	BigInteger A(a);
	*this = *this - A;
	return *this;
}

BigInteger BigInteger :: operator * (BigInteger t, BigInteger b)
{
	BigInteger C;
	C.n = n + A.n + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < A.n; j++)
			C.m[i + j] += m[i] * A.m[j];
	for (int i = 0; i < C.n; i++) {
		C.m[i + 1] += C.m[i] / 10;
		C.m[i] %= 10;
	}
	while (C.m[C.n - 1] == 0 && C.n > 1) C.n--;

	if (mul.getNumber() == "0") // avoid (-0) problem
		mul.setSign(false);
	return C;
}

BigInteger& BigInteger::operator *= (BigInteger b)
{
	(*this) = (*this) * b;
	return (*this);
}

void BigInteger :: operator *= (BigInteger &a, BigInteger b)
{
	a = a * b;
}

void BigInteger :: operator *= (BigInteger &a, int b)
{
	a = a * b;
}

BigInteger delete(const BigInteger &A) {     // impartire cu 2 (necesara pentru căutarea binară în timpul impartirii)
	BigInteger B;
	B.n = A.n;
	int ost = 0, r = 0;
	for (int i = A.n - 1; i >= 0; i--) {
		r = ost * 10 + A.m[i];
		B.m[i] = r / 2;
		ost = r % 2;
	}
	if (B.m[B.n - 1] == 0) B.n--;
	return B;
}

BigInteger BigInteger::operator/(const BigInteger &A) const {  // căutare binară
	BigInteger L("0"), R(1), M;
	while (compare(A*R, *this) == 2) R = R * 2;
	BigInteger I("1"), O("0");
	while ((R - L) != I && (R - L) != O) {
		M = del2(L + R);
		if (compare(A*M, *this) == 2) {
			L = M;
		}
		else {
			R = M;
		}
	}
	if (R*A == *this) return R;
	else return L;
}

BigInteger& BigInteger::operator /= (BigInteger b)
{
	(*this) = (*this) / b;
	return (*this);
}

void  BigInteger :: operator /= (BigInteger &a, BigInteger b) {
	a = a / b;
}

void BigInteger :: operator /= (BigInteger &a, int b) {
	a = a / b;
}


BigInteger BigInteger::operator%(const BigInteger &a, const BigInteger &b)
{
	BigInteger q = a / b;
	BigInteger x = q + b;
	BigInteger result = a - b;
	return result;
}

BigInteger BigInteger::operator%(long long a) const {
	BigInteger A(a);
	return *this - A * (*this / A);
}

BigInteger BigInteger::operator%(long long a, const BigInteger &A) {
	BigInteger B(a);
	return B - A * (B / A);
}

BigInteger BigInteger::operator%=(const BigInteger &A) {
   *this = *this % A;
    return *this;
}

BigInteger BigInteger::operator%=(long long a) {
    BigInteger A(a);
    *this = *this % A;
    return *this;
}

// converteste long long in string
string BigInteger::toString(long long n)
{
	stringstream ss;
	string temp;

	ss << n;
	ss >> temp;

	return temp;
}

// converteste string in long long
long long BigInteger::toInt(string s)
{
	long long sum = 0;

	for (int i = 0; i < s.length(); i++)
		sum = (sum * 10) + (s[i] - '0');

	return sum;
}


// inmulteste 2 stringuri si le aduna intr-un alt string 
string BigInteger::multiply(string n1, string n2)
{
	if (n1.length() > n2.length())
		n1.swap(n2);

	string res = "0";
	for (int i = n1.length() - 1; i >= 0; --i)
	{
		string temp = n2;
		int currentDigit = n1[i] - '0';
		int carry = 0;

		for (int j = temp.length() - 1; j >= 0; --j)
		{
			temp[j] = ((temp[j] - '0') * currentDigit) + carry;

			if (temp[j] > 9)
			{
				carry = (temp[j] / 10);
				temp[j] -= (carry * 10);
			}
			else
				carry = 0;

			temp[j] += '0'; //inapoi la string
		}

		if (carry > 0)
			temp.insert(0, 1, (carry + '0'));

		temp.append((n1.length() - i - 1), '0'); // inmulteste cu 10, 100, 1000, 10000 etc.

		res = add(res, temp); // O(n)
	}

	while (res[0] == '0' && res.length() != 1) // sterge 0-urile ramase
		res.erase(0, 1);

	return res;
}

