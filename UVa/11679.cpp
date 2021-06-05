#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int b, n;
    while (cin >> b >> n)
    {
        if (!n and !b)
            break;

        vector<int> m(b);
        for (auto &i : m)
            cin >> i;

        int s, r, a;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> r >> a;
            --s, --r;
            m[s] -= a;
            m[r] += a;
        }

        cout << (find_if(m.begin(), m.end(), [](int a)
                         { return a < 0; }) != m.end()
                     ? 'N'
                     : 'S')
             << '\n';
    }
}