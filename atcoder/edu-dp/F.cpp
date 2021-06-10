#include <bits/stdc++.h>
using namespace std;

int dp[3002][3002];
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans;
    int i = n, j = m;
    while (i && j)
    {
        if (s[i - 1] == t[j - 1])
            ans += s[i - 1], --i, --j;
        else if (dp[i - 1][j] == dp[i][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}