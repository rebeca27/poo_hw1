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
	for(i = 0; i <= strlen(a) - 1; i++) 
		r = r + a[i];
	return Integer(r);
}

void Set(BigInteger &bi) 
{
	while (bi.size() > 1 && bi.back() == 0) bi.pop_back();
}

BigInteger Integer(string s) 
{
	BigInteger lol;
	if (s[0] == '-') return lol;
	if (s.size() == 0) { lol.push_back(0); return lol; }
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = 0; i < s.size(); i += 9) {
		int v = 0;
		for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
		lol.insert(lol.begin(), v);
	}
	Set(lol);
	return lol;
}

BigInteger Integer(char ch[]) 
{
	string s = "";
	for(i = 0; i <= strlen(ch) - 1; s = s + ch[i]; i++)
	return Integer(s);
}

BigInteger Integer(b x)
{
	string r = "";
	while (x > 0)
		r = char(x % 10 + '0') + r, x /= 10;
	return Integer(r);
}

BigInteger Integer(int x)
{
	return Integer((b)x);
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

bool operator < (BigInteger x, BigInteger y)
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

bool operator > (BigInt a, BigInt b) {
	return (b < a);
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

BigInteger operator / (BigInteger t, int b) {
	Set(t);
	BigInteger lol;
	t ent = 0ll;
	for(i = t.size() - 1; i >= 0; i--)
	{
		ent = (ent*(a)baza + (a)t[i]);
		lol.insert(lol.begin(), ent / b);
		ent %= b;
	}
	Set(lol);
	return lol;
}

void operator /= (BigInteger &a, BigInteger b) {
	a = a / b;
}

void operator /= (BigInteger &a, int b) {
	a = a / b;
}


BigInteger operator % (BigInteger a, BigInteger b)
{
	Set(a);
	Set(b);
	if (b == Integer(0)) return Integer("-1");
	BigInteger lol;
	for(i = a.size() - 1; i >= 0; i--)
	{
		lol.insert(lol.begin(), a[i]);
		int x = 0, L = 0, R = baza;
		while (L <= R) {
			int mij = (L + R) >> 1;
			if (b*Integer(mij) > lol) {
				x = mij;
				R = mij - 1;
			}
			else
				L = mij + 1;
		}
		lol = lol - Integer(x - 1)*b;
	}
	Set(lol);
	return lol;
}

int operator % (BigInteger a, int b)
{
	Set(a);
	if (b == 0) return -1;
	int Gucci = 0;
	for (i = a.size() - 1; i >= 0; i--)
		Gucci = (Gucci*(base%b) + a[i] % b) % b;
	return Gucci;
}

void operator %= (BigInteger &a, BigInteger b) {
	a = a % b;
}

void operator %= (BigInteger &a, int b) {
	a = a % Integer(b);
}

