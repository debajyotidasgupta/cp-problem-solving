
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (auto &i : a)
            scanf("%d", &i);

        int ans = -1e9, mn = a.back();
        for (int i = n - 2; i >= 0; i--)
            ans = max(ans, a[i] - mn), mn = min(mn, a[i]);
        printf("%d\n", ans);
    }
}