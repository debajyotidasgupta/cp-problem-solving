#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<string>> p = {
        {
            ".*.",
            ".*.",
            ".*.",
            ".*.",
            ".*.",
        },
        {
            "***",
            "..*",
            "***",
            "*..",
            "***",
        },
        {
            "***",
            "..*",
            "***",
            "..*",
            "***",
        },
    };

    vector<string> a(5);
    for (auto &i : a)
        cin >> i;
    string ans;
    for (int i = 0; i < 4 * n; i += 4)
    {
        for (int j = 0; j < 3; j++)
        {
            bool ok = true;
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (p[j][k][l] != a[k][i + l])
                    {
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (ok)
            {
                ans += '1' + j;
                break;
            }
        }
    }
    cout << ans << endl;
}