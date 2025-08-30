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

/*
    my observation
             i
       -5 -3 6 7
           j
        -4 2 3


            1 1
           2 2 10


*/
using namespace std;
void solve()
{
    int n, m;
    cin >> n;
    vi a(n);
    read(a);
    cin >> m;
    vi b(m);
    read(b);
    vi ps1(n);
    vi ps2(m);
    ps1[0] = a[0];
    ps2[0] = b[0];
    for (int i = 1; i < n; ++i)
    {
        ps1[i] = ps1[i - 1] + a[i];
    }
    for (int i = 1; i < m; ++i)
    {
        ps2[i] = ps2[i - 1] + b[i];
    }
    int mx1 = 0;
    int mx2 = 0;
    for (int i = 0; i < n; ++i)
    {
        mx1 = max(mx1, ps1[i]);
    }
    for (int i = 0; i < m; ++i)
        mx2 = max(mx2, ps2[i]);

    cout << mx1 + mx2 << endl;
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