#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W, v, w;
    cin >> N >> W;

    vector<long long> prv(W + 1), nxt(W + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> w >> v;
        for (int j = 0; j <= W; j++)
        {
            nxt[j] = prv[j];
            if (j >= w)
                nxt[j] = max(nxt[j], prv[j - w] + v);
            if (j >= 1)
                nxt[j] = max(nxt[j], nxt[j - 1]);
        }
        swap(prv, nxt);
    }
    cout << *max_element(prv.begin(), prv.end()) << '\n';
}