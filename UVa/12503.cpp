#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, v, p = 0;
        cin >> n;
        vector<int> moves;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s == "LEFT")
                moves.push_back(-1);
            else if (s == "RIGHT")
                moves.push_back(1);
            else
            {
                cin >> s >> v;
                moves.push_back(moves[v - 1]);
            }
            p += moves.back();
        }
        cout << p << '\n';
    }
}