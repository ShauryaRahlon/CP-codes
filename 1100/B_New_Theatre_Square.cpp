#include <bits/stdc++.h>
/*------------------------- Type Defs ----------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*------------------------- Macros -------------------------*/
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define all(a) a.begin(), a.end()
#define loop(x, start, end) for (ll x = start; x < end; x++)
#define rloop(i, m, n) for (int i = n; i >= m; i--)
#define read(x) loop(i, 0, x.size()) cin >> x[i];
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define p(x) cout << x << endl
#define p2(arr)                                   \
    loop(i, 0, arr.size()) cout << arr[i] << " "; \
    cout << endl
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)

/*------------------------- Maths --------------------------*/
const int MOD = 1e9 + 7;
template <typename T>
inline T gcd(T a, T b)
{
    T c;
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}
template <typename T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <typename T>
inline bool isPrime(T n)
{
    for (T i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
template <typename T>
inline T Power_MOD(T a, T b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
template <typename T>
inline T Power(T a, T b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

using namespace std;

int dp[1001][1001];
int rec(int n, int m, int x, int y, string &s)
{
    if (m == s.size())
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int take1 = 1e9;
    int take2 = 1e9;
    int exc = 0;
    if (s[m] == '.')
    {
        take1 = x + rec(n, m + 1, x, y, s);
        if (m < s.size() - 1 and s[m + 1] == '.')
            take2 = y + rec(n, m + 2, x, y, s);
        return dp[n][m] = min(take1, take2);
    }
    else
    {
        return dp[n][m] = rec(n, m + 1, x, y, s);
    }
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cnt += rec(i, 0, x, y, s);
    }
    cout << cnt << endl;
}
int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}