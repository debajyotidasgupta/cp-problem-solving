#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5;
int main()
{
    long long N, W, v, w;
    cin >> N >> W;

    vector<long long> prv(nax + 1, 1e18), nxt(nax + 1);
    prv[0] = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> w >> v;
        for (int j = 0; j <= nax; j++)
        {
            nxt[j] = prv[j];
            if (j >= v)
                nxt[j] = min(nxt[j], prv[j - v] + w);
        }
        swap(prv, nxt);
    }
    for (int i = nax; i >= 0; i--)
        if (prv[i] <= W)
        {
            cout << i << '\n';
            break;
        }
}