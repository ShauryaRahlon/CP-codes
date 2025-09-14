#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++)
        cin >> A[i];

    vector<int> dp(N + 1, 0);
    vector<int> opp(N + 1, 0);
    for (int n = 1; n <= N; n++)
    {
        int best = 0;
        for (int a : A)
        {
            if (a > n)
                break;
            best = max(best, a + opp[n - a]);
        }
        dp[n] = best;

        int worst = INT_MAX;
        for (int a : A)
        {
            if (a > n)
                break;
            worst = min(worst, dp[n - a]);
        }
        if (worst == INT_MAX)
            worst = 0;
        opp[n] = worst;
    }

    cout << dp[N] << "\n";
}
