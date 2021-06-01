#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define trav(i, v) for (auto &i : (v))
#define fr(i, n) for (int i = 0; i <= n; i++)
#define rf(i, n) for (int i = n; i >= 0; i--)
#define fra(i, a, b) for (int i = a; i <= b; i++)
#define rfa(i, a, b) for (int i = a; i >= b; i--)
#define lb(v, x) lower_bound(v.begin(), v.end(), x);
#define ub(v, x) upper_bound(v.begin(), v.end(), x);
#define ms(v, x) memset((v), x, sizeof((v)))
#define chmin(a, b) (a) = min((a), (b))
#define chmax(a, b) (a) = max((a), (b))
#define RND                                                                      \
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); \
    std::mt19937 g(seed);

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// typedef tree<pii, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> oset;
const int inf = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cs = 0;
    while (true)
    {
        int n;
        cin >> n;
        n *= 2;
        if (!n)
            break;

        vii a(n);
        string s;
        fr(i, n - 1) cin >> s >> a[i].F >> a[i].S;

        auto d = [&](pii a, pii b)
        {
            a.F -= b.F;
            a.S -= b.S;
            return sqrt(a.F * a.F + a.S * a.S);
        };

        double dp[1 << n];
        fr(i, (1 << n) - 1) dp[i] = 1e18;
        dp[0] = 0;

        fr(i, (1 << n) - 1)
        {
            if (__builtin_popcount(i) & 1)
                continue;
            fr(j, n - 1)
            {
                if (!(i & (1 << j)))
                {
                    int ii = i | (1 << j);
                    fr(k, n - 1)
                    {
                        if (!(ii & (1 << k)))
                        {
                            chmin(dp[ii | (1 << k)], dp[i] + d(a[j], a[k]));
                        }
                    }
                }
            }
        }

        double ans = dp[(1 << n) - 1];
        ans = round(ans * 100) / 100;

        ++cs;
        cout.setf(ios::fixed);
        cout << "Case " << cs << ": " << setprecision(2) << ans << endl;
    }
}
