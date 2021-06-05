#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Case = 0, n;
    while (true)
    {
        ++Case;
        cin >> n;
        if (!n)
            break;

        int balance = 0, treat;
        for (int i = 0; i < n; i++)
        {
            cin >> treat;
            balance += treat ? 1 : -1;
        }

        cout << "Case " << Case << ": " << balance << '\n';
    }
}