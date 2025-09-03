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

int rec(int i, vl &a, vl &b, vl &c, ll last, vector<vector<ll>> &dp)
{
    if (i >= a.size())
        return 0;

    if (dp[i][last] != -1)
        return dp[i][last];
    int ans = 0;

    int exc = rec(i + 1, a, b, c, last, dp);
    ans = max(ans, exc);

    //we cant do another task after ending a same task on a same day\
        if last != a[i]\
        then try max of include and exclude \
        else if last=a[i];\
        exclude this only nothing else u can do
    if (a[i] > last)
    {
        int inc = c[i] + rec(i + 1, a, b, c, b[i], dp);
        ans = max(ans, inc);
    }

    return dp[i][last] = ans;
}
void solve()
{
    int n;
    cin >> n;
    vl a(n), b(n);
    vl p1(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> p1[i];
    ll mx = *max_element(all(b));
    vector<vector<ll>> dp(n + 1, vector<ll>(mx + 1, -1));
    cout << rec(0, a, b, p1, 0, dp) << endl;
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