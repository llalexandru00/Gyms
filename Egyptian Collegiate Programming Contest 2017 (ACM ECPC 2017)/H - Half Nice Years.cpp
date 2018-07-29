#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
ll t, n, a, b, c;

inline ll min(ll a, ll b) {
	return a < b ? a : b;
}

ll getCif(ll x)
{
	ll l = 0;
	while (x)
	{
		x /= 10;
		l++;
	}
	return l;
}

bool P[10000007];
vector <ll> Prime;

void Ciur()
{
	P[0] = 1;
	for (ll i = 2; i <= 1e4; i++)
	{
		if (P[i] == 0)
		{
			for (ll j = i * i; j <= 1e7; j += i)
				P[j] = 1;
			Prime.push_back(i);
		}
	}
}

ll cmmd(ll x)
{
	ll p = 0;
	while (Prime[p] * Prime[p] <= x)
	{
		if (x%Prime[p] == 0)
			return Prime[p];
		p++;
	}
	return x;
}

inline ll  max(ll a, ll b) { return a > b ? a : b; }

int main()
{
	freopen("halfnice.in", "r", stdin);
	Ciur();
	cin >> t;
	for (ll i=1; i<=t; i++)
	{
		ll l, r, maxim=0;
		cin >> l >> r;
		ll lg = getCif(r);
		if (lg % 2 == 0)
		{
			ll a = r/pow(10, lg / 2);
			ll b = r % (ll)pow(10, lg / 2);
			while ((a==1 || cmmd(a) > b))
			{
				a--;
				b = pow(10, lg / 2) - 1;
				if (getCif(a) != lg / 2)
				{
					maxim = pow(10, lg - 1) - 1;
					lg--;
				}
			}
			lg = lg - getCif(a);

			ll p = 0;
			while (Prime[p] * Prime[p] <= a)
			{
				if (a%Prime[p] == 0)
				{
					ll b2 = b / Prime[p];
					b2 *= Prime[p];
					maxim = max(maxim, a*pow(10, lg) + b2);
					b2 = b / (a / Prime[p]);
					b2 *= a / Prime[p];
					maxim = max(maxim, a*pow(10, lg) + b2);
				}
				p++;
			}
			if (P[a] == 0)
			{
				ll b2 = b / a;
				b2 *= a;
				maxim = max(maxim, a*pow(10, lg) + b2);
			}
		} 
		else
		{
			ll a = r / pow(10, lg / 2 + 1);
			ll b = r % (ll)pow(10, lg / 2 + 1);
			while ((a == 1 || cmmd(a) > b))
			{
				a--;
				b = pow(10, lg / 2+1) - 1;
				if (getCif(a) != lg / 2)
				{
					maxim = pow(10, lg - 1) - 1;
					lg--;
				}
			}
			lg = lg - getCif(a);

			ll p = 0;
			while (Prime[p] * Prime[p] <= a)
			{
				if (a%Prime[p] == 0)
				{
					ll b2 = b / Prime[p];
					b2 *= Prime[p];
					maxim = max(maxim, a*pow(10, lg) + b2);
					b2 = b / (a / Prime[p]);
					b2 *= a / Prime[p];
					maxim = max(maxim, a*pow(10, lg) + b2);
				}
				p++;
			}
			if (P[a] == 0)
			{
				ll b2 = b / a;
				b2 *= a;
				maxim = max(maxim, a*pow(10, lg) + b2);
			}
		}
		if (maxim<l)
			cout << "Case " << i << ": " << "impossible" << '\n';
		else
			cout << "Case " << i << ": "<< maxim <<'\n';
	}
}