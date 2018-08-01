#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int t, n, m, q, MF[205][205][2005], M[205][205];
int F[2005];

void getFrecv(int x1, int y1, int x2, int y2)
{
	memset(F, 0, sizeof(F));
	for (int k = 1; k <= 2000; k++)
	{
		F[k] = MF[x2][y2][k] - MF[x2][y1 - 1][k] - MF[x1 - 1][y2][k] + MF[x1 - 1][y1 - 1][k];
	}
}

void BuildFrecv()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= 2000; k++)
			{
				MF[i][j][k] = MF[i-1][j][k] + MF[i][j-1][k] - MF[i-1][j-1][k] + (M[i][j]==k);
			}
		}
	}
}

inline int min(int a, int b) { return a < b ? a : b; }

int getMedian()
{
	int i, j;
	for (i = 1, j = 2000; i < j;)
	{
		while  (F[i] == 0 && i < j) i++;
		while  (F[j] == 0 && i < j) j--;
		int minim = min(F[i], F[j]);
		F[i] -= minim;
		F[j] -= minim;
	}
	return i;
}

int main()
{
	freopen("important.in", "r", stdin);
	
	cin >> t;
	for (ll i=1; i<=t; i++)
	{
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> M[i][j];
			}
		}
		BuildFrecv();
		cout << "Case " << i << ": " << '\n';
		for (int i = 1; i <= q; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			getFrecv(x1, y1, x2, y2);
			int ans = getMedian();
			cout << ans << '\n';
		}
	}
}