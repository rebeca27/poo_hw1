#Rebeca_Oprea

using namespace std;

typedef int64_t a;
typedef long long ll;
typedef pair<a, a> a;
typedef pair<a, int> ai;
typedef pair<int, int> ii;

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

const int baza = 1e9;  //Format: 1,000,000,000.00


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
		lol.push_back(rest%baza);
		rest /= baza;
	}
	if (rest) 
		bas.push_back(rest);
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

BigInteger operator - (BigInteger a, BigInteger b) {
	Set(a);
	Set(b);
	BigInteger lol;
	int rest = 0; 
	for(i = 0; i <= a.size() - 1; i++)
	{
		rest += a[i] - (i < b.size() ? b[i] : 0);
		if (rest < 0)
			lol.push_back(rest + baza), rest = -1;
		else lol.push_back(rest), rest = 0;
	}
	Set(lol);
	return lol;
}

BigInteger operator - (BigInteger a, int b) {
	return a - Integer(b);
}

void operator -- (BigInteger &a) { 
	a = a - 1;
}

void operator -= (BigInteger &a, BigInteger b) {
	a = a + b;
}

void operator -= (BigInteger &a, int b) {
	a = a - b;
}


BigInteger operator * (BigInteger t, BigInteger b)
{
	Set(t);
	Set(b);
	BigInteger lol;
	lol.assign(t.size() + b.size(), 0);
	for (i = 0; i <= t.size() - 1; i++)
	{
		a carry = 0ll;
		for (int j = 0; j < b.size() || rest > 0; j++) {
			a s = lol[i + j] + rest + (a)t[i] * (j < b.size() ? (a)b[j] : 0ll);
			lol[i + j] = s % baza;
			rest = s / baza;
		}
	}
	Set(lol);
	return lol;
}

BigInteger operator * (BigInteger a, int b) {
	return a * Integer(b);
}

void operator *= (BigInteger &a, BigInt b) {
	a = a * b;
}

void operator *= (BigInteger &a, int b) {
	a = a * b;
}


BigInteger operator / (BigInteger a, BigInteger b) 
{
	Set(a);
	Set(b);
	if (b == Integer(0)) return Integer("-1");
	BigInteger lol, ent;

	for (int i = a.size() - 1; i >= 0; i--)
	{
		cur.insert(cur.begin(), a[i]);
		int x = 0, L = 0, R = baza;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (b*Integer(mij) > ent) {
				x = mij;
				R = mij - 1;
			}
			else
				L = mij + 1;
		}
		ent = ent - Integer(x - 1)*b;
		ans.insert(ans.begin(), x - 1);
	}
	Set(lol);
	return lol;
}

BigInt operator / (BigInt t, int b) {
	Set(t);
	BigInt lol;
	t ent = 0ll;
	FORD(i, t.size() - 1, 0) 
	for()
	{
		ent = (ent*(a)baza + (a)t[i]);
		lol.insert(lol.begin(), ent / b);
		ent %= b;
	}
	Set(lol);
	return lol;
}
