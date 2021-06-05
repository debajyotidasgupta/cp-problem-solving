
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int v = 1, ans = 0;
        for (auto &i : s)
        {
            if (i == 'O')
                ans += v++;
            else
                v = 1;
        }
        cout << ans << '\n';
    }
}