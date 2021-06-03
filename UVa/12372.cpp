#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Case = 0, t;
    cin >> t;
    while (t--)
    {
        ++Case;
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << Case << ": " << (a <= 20 && b <= 20 && c <= 20 ? "good" : "bad") << '\n';
    }
}