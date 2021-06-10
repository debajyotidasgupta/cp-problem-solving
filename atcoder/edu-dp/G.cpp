#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> dp(n), tp, in(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        in[y - 1]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        tp.push_back(u);
        for (auto &v : g[u])
        {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }

    reverse(tp.begin(), tp.end());
    for (int &i : tp)
        for (auto j : g[i])
            dp[i] = max(dp[i], 1 + dp[j]);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}