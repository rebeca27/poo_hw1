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

BigInteger Integer(char a[]) {
	string r = "";
	FOR(i, 0, strlen(a) - 1) r = r + a[i];
	return Integer(r);
}




