#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1e9);
    for (auto &i : a)
        cin >> i;

    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > 0)
            dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        if (i > 1)
            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp.back() << '\n';
}