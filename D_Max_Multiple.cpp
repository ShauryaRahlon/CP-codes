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

long long rec(int i, int k, int rem, int d, vl &a, vector<vector<vector<long long>>> &dp)
{

    if (k == 0)
    {
        return (rem == 0) ? 0 : -1e18;
    }
    if (i >= a.size())
    {
        return -1e18;
    }
    if (dp[i][k][rem] != -1)
    {
        return dp[i][k][rem];
    }

    int next_rem = (rem - (a[i] % d) + d) % d;
    long long include_sum = rec(i + 1, k - 1, next_rem, d, a, dp);

    // Only consider this path if it's valid (not -1e18)
    if (include_sum != -1e18)
    {
        include_sum += a[i];
    }

    // Option 2: Exclude a[i]
    long long exclude_sum = rec(i + 1, k, rem, d, a, dp);

    // Return the best possible outcome
    return dp[i][k][rem] = max(include_sum, exclude_sum);
}

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vl a(n);
    read(a);

    // dp[index][count][remainder]
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(d, -1)));

    long long result = rec(0, k, 0, d, a, dp);

    cout << (result <= 0 ? -1 : result) << endl; // Or handle 0 as a valid case if needed
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