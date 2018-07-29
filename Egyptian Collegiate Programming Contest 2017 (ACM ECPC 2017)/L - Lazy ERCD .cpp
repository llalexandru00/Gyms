#include <iostream>
#include <fstream>

using namespace std;

int t, n;

int main()
{
	freopen("lazy.in", "r", stdin);
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		cin >> n;
		cout << "Case " << i << ": "<<n - 1<<'\n';
	}
}