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
	for(i, 0, strlen(a) - 1) 
		r = r + a[i];
	return Integer(r);
}

BigInteger maxim(BigInteger a, BigInteger b)
{
	if (a > b) return a;
	return b;
}

BigInteger minim(BigInteger a, BigInteger b) 
{
	if (a < b) return a;
	return b;
}


BigInteger Integer(b x)
{
	string r = "";
	while (x > 0)
		r = char(x % 10 + '0') + r, x /= 10;
	return Integer(r);
}

BigInteger Integer(int x) {
	return Integer((b)x);
}

bool operator < (BigInteger x, BigInteger y) 
{
	Set(x);
	Set(y);
	if (x.size() != y.size()) 
		return (x.size() < y.size());
	for(int i = x.size() - 1, i >= 0; i--)
		if (x[i] != y[i]) 
			return (x[i] < y[i]);
	return false;
}

BigInteger operator + (BigInteger a, BigInteger b)
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
		lol.pb(rest%base);
		rest /= base;
	}
	if (rest) 
		bas.pb(rest);
	Set(lol);
	return lol;
}

BigInteger operator + (BigInteger a, int b) {
	return a + Integer(b);
}

BigInteger operator ++ (BigInteger &a) { 
	a = a + 1;
	return a;
}

void operator += (BigInteger &a, BigInteger b) {
	a = a + b;
}

void operator += (BigInteger &a, int b) {
	a = a + b;
}