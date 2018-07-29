#include <iostream>
#include <fstream>

using namespace std;

int t, n, a, b, c;

inline int min(int a, int b) {
	return a < b ? a : b;
}

int main()
{
	freopen("katryoshka.in", "r", stdin);
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		cin >> a >> b >> c;
		int x = min(a, min(b, c));
		a -= x;
		c -= x;
		x += min(a / 2, c);
		cout << "Case " << i << ": "<< x <<'\n';
	}
}