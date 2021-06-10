#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t, ans = 0;
    cin >> t;
    while (t--)
    {
        double l, w, d, wt;
        cin >> l >> w >> d >> wt;
        bool ok = false;
        ok = ok or (l <= 56.0 and w <= 45.0 and d <= 25.0);
        ok = ok or (l + w + d <= 125.0);
        ok = ok and (wt <= 7.0);
        cout << ok << '\n';
        ans += ok;
    }
    cout << ans << '\n';
}