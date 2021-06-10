#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int A = 0, B = 0, C = 0, a, b, c;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        int _A = a + max(B, C);
        int _B = b + max(C, A);
        int _C = c + max(A, B);
        A = _A;
        B = _B;
        C = _C;
    }
    cout << max({A, B, C}) << '\n';
}