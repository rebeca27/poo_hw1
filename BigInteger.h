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
	const string& getNumber(); // intoarce numarul
	char getSign();
	void setSign(bool s);
	char* toString();

	friend ostream& operator << (ostream &out, const BigInteger &A);
	friend istream& operator >> (istream &in, BigInteger &A);

	friend int compare(const BigInteger &A, const BigInteger &B);

	bool operator==(const BigInteger &A) const;
	bool operator!=(const BigInteger &A) const;

	friend bool operator < (const BigInteger &b);
	friend bool operator > (const BigInteger &b);
	friend bool operator < (const BigInteger &a, int b);
	friend bool operator > (const BigInteger &a, int b);
	friend bool operator == (const BigInteger &a, const  BigInteger &b);
	friend bool operator == (const BigInteger b);
	friend bool operator <= (const BigInteger &a, const  BigInteger &b);
	friend bool operator <= (const BigInteger &b)
	friend bool operator >= (const BigInteger &a, const  BigInteger &b);
	friend bool operator >= (const BigInteger &b);

	friend BigInteger maxim(BigInteger a, BigInteger b);
	friend BigInteger minim(BigInteger a, BigInteger b);

	friend BigInt operator ^ (const BigInt &base, int exp);

	friend BigInteger operator+(const BigInteger &A) const;
	friend BigInteger operator+(long long a) const;
	friend BigInteger operator+(long long a, const BigInteger &A);
	BigInteger &operator += (const BigInteger &A;
	BigInteger &operator += (long long a);


	friend BigInteger operator - (const BigInteger &A) const;
	friend BigInteger operator - (long long a) const;
	friend BigInteger operator - (long long a, const BigInteger &A);

	BigInteger &operator -= (const BigInteger &A);
	BigInteger &operator -= (long long a);

	friend BigInteger operator * (BigInteger t, BigInteger b);
	friend BigInteger operator * (BigInteger a, int b);

	BigInteger &operator *= (BigInteger b);
	BigInteger &operator *= (BigInteger &a, BigInt b);
	BigInteger &operator *= (BigInteger &a, int b);

	friend BigInteger delete(const BigInteger &A);

	friend BigInteger operator / (BigInteger a, BigInteger b);
	friend BigInteger operator / (BigInteger t, int b);

	BigInteger &operator /= (BigInteger b);
	BigInteger &operator /= (BigInteger &a, BigInteger b);
	BigInteger &operator /= (BigInteger &a, int b);

	friend BigInteger operator %(const BigInteger &a, const BigInteger &b)
	friend BigInteger operator %(long long a) const;
	friend BigInteger operator %(long long a, const BigInteger &A);
	 BigInteger &operator %=(const BigInteger &A);
     BigInteger &operator %=(long long a);

private:
	int n;
	int base;
	bool is_unsigned;
	char sign;
	std::vector<unsigned char> val;

	//functii suplimentare cerintelor de la seminar dar necesare pentru cod
	bool equals(BigInteger n1, BigInteger n2);
	bool less(BigInteger n1, BigInteger n2);
	bool greater(BigInteger n1, BigInteger n2);
	//functii suplimentare cerintelor de la seminar dar necesare pentru folosirea vectorului std::vector<unsigned char> cu integer
	string toString(long long n);
	long long toInt(string s);
}
