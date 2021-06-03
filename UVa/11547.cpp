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
        double n;
        cin >> n;
        n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
        int ans = (int)(fabs(n) / 10) % 10;
        cout << ans << endl;
    }
}