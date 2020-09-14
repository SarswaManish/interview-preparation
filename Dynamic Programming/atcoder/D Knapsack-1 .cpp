#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1e15
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 100005;
int n, m;
vector<int>v[N];
int vis[N] = {};


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int func(int n, int a[])
{
	int l = 0;
	int sum = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < sum)
		{
			int diff = abs(a[i] - sum);
			l += diff;
			sum = a[i] + diff;
		}
		else {
			sum = a[i];
		}
	}
	return l;
}
vector<vector<int>>dp;

int32_t main()
{
	std::ios::sync_with_stdio(false);

// #ifndef ONLINE_JUDGE
// 	freopen("inputf.txt", "r", stdin);
// 	freopen("outputf.txt", "w", stdout);
// #endif

	int n, m;
	cin >> n >> m;
	int w[n], v[n];

	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> v[i];
	}



	dp.resize(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{

			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}\

	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (w[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][m] << endl;

	return 0;

}
