#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

template<class InIt>
void print_range(InIt first, InIt last, char const* delim = "\n") {
	--last;
	for (; first != last; ++first) {
		std::cout << *first << delim;
	}
	std::cout << *first;
}

// Function that convert Decimal to binary 
int decToBinary (int n)
{
	int v[100],j=0;

  // Size of an integer is assumed to be 32 bits 
	for (int i = 32; i >= 0; i--)
	{
		int k = n >> i;
		if (k & 1) 
		{
			v[j] = 1;
			j++;
		}
		else 
		{
			v[j] = 0;
			j++;
		}
		j--;
	}

	  std::vector<int> v(a, a + 5);
	  print_range(v.begin(), v.end(), "->");
	  std::cout << "\n=============\n";
	  print_range(v.rbegin(), v.rend(), "<-");
 
return v;
}

// driver code 
int
main ()
{
  int n;
  cin >> n;
  decToBinary (n);

}
