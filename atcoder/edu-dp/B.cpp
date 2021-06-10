#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n, 1e9);
    for (auto &i : a)
        cin >> i;

    dp[0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k; j++)
            if (j <= i)
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
    cout << dp.back() << '\n';
}