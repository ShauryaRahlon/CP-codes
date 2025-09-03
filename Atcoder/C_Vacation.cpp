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

int dp[100001][4];
int rec(int i, vi &a, vi &b, vi &c, int prev1) // intitially prev1 to be kept -1
{
    // base
    if (i >= a.size())
        return 0;

    if (dp[i][prev1] != -1)
        return dp[i][prev1];
    int ans = 0;
    if (prev1 == 3)
    {
        // do any activity
        // changing states i and prev
        int a1 = a[i] + rec(i + 1, a, b, c, 0);
        int b2 = b[i] + rec(i + 1, a, b, c, 1);
        int c3 = c[i] + rec(i + 1, a, b, c, 2);
        ans = max({a1, b2, c3});
    }
    // if done activity 1 take max of activity 2 and 3
    if (prev1 == 0)
    {
        int b2 = b[i] + rec(i + 1, a, b, c, 1);
        int c3 = c[i] + rec(i + 1, a, b, c, 2);
        ans = max(b2, c3);
    }
    if (prev1 == 1)
    {
        int a1 = a[i] + rec(i + 1, a, b, c, 0);
        int c3 = c[i] + rec(i + 1, a, b, c, 2);
        ans = max(a1, c3);
    }
    if (prev1 == 2)
    {
        int b2 = b[i] + rec(i + 1, a, b, c, 1);
        int a1 = a[i] + rec(i + 1, a, b, c, 0);
        ans = max(a1, b2);
    }
    return dp[i][prev1] = ans;
}
void solve()
{
    int n;
    cin >> n;
    // dp for n+1,3

    memset(dp, -1, sizeof(dp));
    vi a(n);
    vi b(n);
    vi c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    cout << rec(0, a, b, c, 3) << endl;
}
int main()
{

    FAST_IO;
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}