#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, string> f;
    f["HOLA"] = "SPANISH";
    f["HALLO"] = "GERMAN";
    f["CIAO"] = "ITALIAN";
    f["HELLO"] = "ENGLISH";
    f["BONJOUR"] = "FRENCH";
    f["ZDRAVSTVUJTE"] = "RUSSIAN";

    int Case = 0;
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        ++Case;
        cout << "Case " << Case << ": " << (f.find(s) == f.end() ? "UNKNOWN" : f[s]) << '\n';
    }
}