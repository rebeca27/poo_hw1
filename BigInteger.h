#Rebeca_Oprea_grupa_252
#include <vector>


class BigInteger
{
public:
	BigInteger();
	BigInteger(const char* numberSequence);
	BigInteger(const char* numberSequence, int base);
	virtual ~BigInteger();		//functia virtuala asigură că se apeleaza corect funcția pentru un obiect
	int getBase();
	char getSign();
	char* toString();

	friend ostream& operator<<(ostream &out, const BigInteger &A);
	friend istream& operator >> (istream &in, BigInteger &A);

	friend int compare(const BigInteger &A, const BigInteger &B);
	bool operator==(const BigInteger &A) const;
	bool operator!=(const BigInteger &A) const;


	friend bool operator < (BigInteger x, BigInteger y);
	friend bool operator > (const BigInteger &a, BigInteger b);
	friend bool operator == (BigInteger a, BigInteger b);
	friend bool operator <= (BigInteger a, BigInteger b);
	friend bool operator >= (BigInteger a, BigInteger b);
	friend bool operator < (BigInteger a, int b);
	friend bool operator > (BigInteger a, int b);
	friend bool operator == (BigInteger a, int b);
	friend bool operator >= (BigInteger a, int b);
	friend bool operator <= (BigInteger a, int b);
	friend BigInteger maxim(BigInteger a, BigInteger b);
	friend BigInteger minim(BigInteger a, BigInteger b);
	friend BigInteger operator + (BigInteger a, BigInteger b);
	friend BigInteger operator + (BigInteger a, int b);

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
	char* numberSequence;
	int base;
	bool isUnsigned;
	std::vector<unsigned char> val;
}
