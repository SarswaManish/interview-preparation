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


int dp[1001][1001];

int is_present(int a[], int pos, int sum)
{


	if (sum == 0)
	{
		return true;
	}
	if (pos < 0)
	{
		return false;
	}


	if (a[pos] > sum)
	{
		return is_present(a, pos - 1, sum);
	}
	else
	{
		return  (is_present(a, pos - 1, sum - a[pos]) || is_present(a, pos - 1, sum));
	}

}
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
		int n;
		cin >> n;


		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int sum;
		cin >> sum;

		cout << (is_present(a, n - 1, sum) ? "true" : "false") << endl;


	}
	return 0;
}
