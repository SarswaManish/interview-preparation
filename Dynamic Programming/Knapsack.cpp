#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define vi vector<int>
#define vll vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 1000005;


int tracker[N] = {};


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int par[N] = {};
vector<int>v1;


int dp[1001][1001] = {};

int _knapsack(int a[], int w[], int pos, int cap)
{
	if (pos < 0)
	{
		return 0;
	}

	if (dp[pos][cap] != -1)
		return dp[pos][cap];
	if (w[pos] > cap)
	{
		return dp[pos][cap] = _knapsack(a, w, pos - 1, cap);
	}
	else
	{
		return dp[pos][cap] = max(a[pos] + _knapsack(a, w, pos - 1, cap - w[pos]), _knapsack(a, w, pos - 1, cap));

	}
}

int32_t main() {
	std::ios::sync_with_stdio(false);
	// cin.ignore(); must be there when using getline(cin, s)
	/*#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif*/
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i <= 1000; i++)
		{
			for (int j = 0; j <= 1000; j++)
			{
				dp[i][j] = -1;
			}
		}
		int n;
		cin >> n;
		int cap;
		cin >> cap;

		int w[n], a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < n; i++)
			cin >> w[i];

		cout << _knapsack(a, w, n - 1, cap) << endl;

	}
	return 0;
}
