#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t, Case = 0;
    cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        map<int, vector<string>, greater<>> m;
        for (int i = 0; i < 10; i++)
        {
            string s;
            int v;
            cin >> s >> v;
            m[v].push_back(s);
        }

        printf("Case #%d:\n", ii);
        for (auto &i : m.begin()->second)
            cout << i << '\n';
    }
}