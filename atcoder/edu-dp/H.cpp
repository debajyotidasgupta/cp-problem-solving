#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];
const int mod = 1e9 + 7;

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (auto &i : a)
        cin >> i;

    dp[1][1] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (a[i - 1][j - 1] == '.')
            {
                add(dp[i][j], dp[i - 1][j]);
                add(dp[i][j], dp[i][j - 1]);
            }
    cout << dp[h][w] << '\n';
}