#Rebeca_Oprea

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
	virtual ~BigInteger();
	int getBase();
	char getSign();
	char* toString();

};

BigInteger Integer(char a[])
{
	string r = "";
	FOR(i, 0, strlen(a) - 1) r = r + a[i];
	return Integer(r);
}

BigInteger Integer(b x)
{
	string r = "";
	while (x > 0) r = char(x % 10 + '0') + r, x /= 10;
	return Integer(r);
}

BigInteger Integer(int x) {
	return Integer((b)x);
}

bool operator < (BigInteger x, BigInteger y) 
{
	Set(x);
	Set(y);
	if (x.size() != y.size()) return (x.size() < y.size());
	FORD(i, x.size() - 1, 0)
		if (x[i] != y[i]) return (x[i] < y[i]);
	return false;
}


