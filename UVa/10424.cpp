
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    while (getline(cin >> ws, a) and getline(cin >> ws, b))
    {
        int Sa = 0, Sb = 0;
        for (auto &i : a)
            if (isalpha(i))
                Sa += tolower(i) - 'a' + 1;

        for (auto &i : b)
            if (isalpha(i))
                Sb += tolower(i) - 'a' + 1;

        auto f = [&](auto &self, int v)
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

        Sa = f(f, Sa);
        Sb = f(f, Sb);
        if (Sa > Sb)
            swap(Sa, Sb);

        cout.setf(ios::fixed);
        cout << setprecision(2) << 100.0 * Sa / Sb << " %" << '\n';
    }
}