#include <bits/stdc++.h>
using namespace std;

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
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)

/*------------------------- Solution -------------------------*/

void solve()
{
    int n;
    cin >> n;
    vi b(n);
    read(b);

    vector<pair<int, int>> vb(n);
    loop(i, 0, n)
    {
        vb[i] = {b[i], i};
    }
    sort(all(vb));

    bool possible = true;
    for (int i = 0; i < n;)
    {
        int val = vb[i].first;
        int j = i;
        while (j < n && vb[j].first == val)
        {
            j++;
        }
        int count = j - i;
        if (count % val != 0)
        {
            possible = false;
            break;
        }
        i = j;
    }

    if (!possible)
    {
        cout << -1 << "\n";
        return;
    }

    vi a(n);
    int label = 0;
    for (int i = 0; i < n;)
    {
        int val = vb[i].first;
        int j = i;
        while (j < n && vb[j].first == val)
        {
            j++;
        }
        for (int k = i; k < j; k++)
        {
            if ((k - i) % val == 0)
            {
                label++;
            }
            int original_index = vb[k].second;
            a[original_index] = label;
        }
        i = j;
    }

    loop(i, 0, n)
    {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
    return 0;
}