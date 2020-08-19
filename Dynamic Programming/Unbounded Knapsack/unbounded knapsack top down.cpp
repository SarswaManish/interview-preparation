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



int32_t main() {
	std::ios::sync_with_stdio(false);
	// cin.ignore(); must be there when using getline(cin, s)
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, cap;
		cin >> n >> cap;
		vector<vector<int>>dp;

		int val[n], w[n];
		for (int i = 0; i < n; i++)
			cin >> val[i];

		for (int i = 0; i < n; i++)
			cin >> w[i];

		dp.resize(n + 1, vector<int>(cap + 1));

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= cap; j++)
				if (i == 0 || j == 0)
					dp[i][j] = 0;
		}


		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= cap; j++)
			{
				if (w[i - 1] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max(val[i - 1] + dp[i][j - w[i - 1]], dp[i - 1][j]);
				}
			}
		}

		cout << dp[n][cap] << endl;


	}
	return 0;
}
