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
        int high = 0, low = 0, n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        sort(a.rbegin(), a.rend());

        cout << "Case " << Case << ": " << a.front() << '\n';
    }
}