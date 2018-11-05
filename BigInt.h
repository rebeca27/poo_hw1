#Rebeca_Oprea_grupa_252

using namespace std;

typedef int64_t a;
typedef long long ll;

class BigInteger
{
private:
	char* numberSequence;
	int base;
	bool isUnsigned;

public:
	BigInteger();
	BigInteger(const char* numberSequence);
	BigInteger(const char* numberSequence, int base);
	virtual ~BigInteger();		//functia virtuala asigură că se apeleaza corect funcția pentru un obiect
	int getBase();
	char getSign();
	char* toString();

void operator ++() 
    { 
        count = count+1; 
    }

void operator --() 
    { 
        count = count-1; 
    }

void operator >> (istream &in, BigInteger &a)
{
	string s;
	getline(cin, s);
	a = Integer(s);
}

void operator << (ostream &out, BigInteger a)
{
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	for(i = a.size() - 2; i >= 0; i--)
		printf("%09d", a[i]); 
	printf("\n");
}

friend bool operator < (BigInteger x, BigInteger y);
friend bool operator > (BigInteger a, BigInteger b);
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
friend BigInteger operator ++ (BigInteger &a); 

void operator += (BigInteger &a, BigInteger b);
void operator += (BigInteger &a, int b);
	
friend BigInteger operator - (BigInteger a, BigInteger b) ;
friend BigInteger operator - (BigInteger a, int b);

friend void operator -- (BigInteger &a);
void operator -= (BigInteger &a, BigInteger b);
void operator -= (BigInteger &a, int b);

friend BigInteger operator * (BigInteger t, BigInteger b);

friend BigInteger operator * (BigInteger a, int b);

void operator *= (BigInteger &a, BigInt b) ;

void operator *= (BigInteger &a, int b) ;

friend BigInteger operator / (BigInteger a, BigInteger b) ;

friend BigInteger operator / (BigInteger t, int b) ;

void operator /= (BigInteger &a, BigInteger b) ;

void operator /= (BigInteger &a, int b) ;

friend BigInteger operator % (BigInteger a, BigInteger b);

friend int operator % (BigInteger a, int b);

void operator %= (BigInteger &a, BigInteger b);
void operator %= (BigInteger &a, int b);
	
;}
