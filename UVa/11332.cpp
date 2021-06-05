
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (!n)
            break;
        auto f = [&](auto &self, int v) -> int
        {
            if (v < 10)
                return v;
            int s = 0;
            while (v)
            {
                s += v % 10;
                v /= 10;
            }
            return self(self, s);
        };
        cout << f(f, n) << '\n';
    }
}