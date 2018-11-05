
//Rebeca_Oprea_grupa_252
#include <vector>
#include <cstring>
#include <algorithm>

class BigInteger
{
public:
	BigInteger(std::string val, unsigned char base = '10');
	BigInteger(int val = 0, unsigned char base = '10');
	BigInteger(long long int val, unsigned char base = '10');
	virtual ~BigInteger();			//functia virtuala asigură că se apeleaza corect funcția pentru un obiect
	int getBase();
	char getSign();
	char* toString();

	friend ostream& operator << (ostream &out, const BigInteger &A);
	friend istream& operator >> (istream &in, BigInteger &A);

	friend int compare(const BigInteger &A, const BigInteger &B);

	bool operator==(const BigInteger &A) const;
	bool operator!=(const BigInteger &A) const;

	friend bool operator < (BigInteger x, BigInteger y);
	friend bool operator > (const BigInteger &a, BigInteger b);
	friend bool operator < (BigInteger a, int b);
	friend bool operator > (BigInteger a, int b);
	friend bool operator == (BigInteger a, BigInteger b);
	friend bool operator == (BigInteger a, int b);
	friend bool operator <= (BigInteger a, BigInteger b);
	friend bool operator >= (BigInteger a, BigInteger b);
	friend bool operator >= (BigInteger a, int b);
	friend bool operator <= (BigInteger a, int b);

	friend BigInteger maxim(BigInteger a, BigInteger b);
	friend BigInteger minim(BigInteger a, BigInteger b);

	friend BigInt operator ^ (const BigInt &base, int exp);

	friend BigInteger operator+(const BigInteger &A) const;
	friend BigInteger operator+(long long a) const;
	friend BigInteger operator+(long long a, const BigInteger &A);

	BigInteger &operator += (BigInteger a, BigInteger b);
	BigInteger &operator += (BigInteger a, int b);

	friend BigInteger operator - (BigInteger a, BigInteger b);
	friend BigInteger operator - (BigInteger a, int b);

	BigInteger &operator -= (BigInteger &a, BigInteger b);
	BigInteger &operator -= (BigInteger &a, int b);

	friend BigInteger operator * (BigInteger t, BigInteger b);
	friend BigInteger operator * (BigInteger a, int b);

	BigInteger &operator *= (BigInteger &a, BigInt b);
	BigInteger &operator *= (BigInteger &a, int b);

	friend BigInteger operator / (BigInteger a, BigInteger b);
	friend BigInteger operator / (BigInteger t, int b);

	BigInteger &operator /= (BigInteger &a, BigInteger b);
	BigInteger &operator /= (BigInteger &a, int b);

	friend BigInteger operator % (BigInteger a, BigInteger b);
	friend int operator % (BigInteger a, int b);
	BigInteger &operator %= (BigInteger &a, BigInteger b);
	BigInteger &operator %= (BigInteger &a, int b);

private:
	int n;
	int base;
	bool is_unsigned;
	char sign;
	std::vector<unsigned char> val;
}
