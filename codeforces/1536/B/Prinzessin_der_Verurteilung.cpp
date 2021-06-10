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
#define rall(v) (v).rbegin(), (v).rend()
#define trav(i, v) for (auto &i : (v))
#define fr(i, n) for (int i = 0; i <= n; i++)
#define rf(i, n) for (int i = n; i >= 0; i--)
#define fra(i, a, b) for (int i = a; i <= b; i++)
#define rfa(i, a, b) for (int i = a; i >= b; i--)
#define fru(i, a, b, u) for (int i = a; i <= b; i += u)
#define rfu(i, a, b, u) for (int i = a; i >= b; i -= u)
#define lb(v, x) lower_bound(v.begin(), v.end(), x);
#define ub(v, x) upper_bound(v.begin(), v.end(), x);
#define ms(v, x) memset((v), x, sizeof((v)))
#define chmin(a, b) (a) = min((a), (b))
#define chmax(a, b) (a) = max((a), (b))
#define vread(v) trav(iter, a) cin >> iter
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
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<pii, int> mpi;
typedef map<int, vi> mivi;
typedef map<int, vl> mivl;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<pii, int> umpi;
typedef unordered_map<int, vi> umivi;
typedef unordered_map<int, vl> umivl;
typedef set<ll> sl;
typedef set<int> si;
typedef set<string> ss;
typedef unordered_set<ll> usl;
typedef unordered_set<int> usi;
typedef unordered_set<string> uss;

template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
#ifdef DEBUG
    return os << '(' << p.first << ", " << p.second << ')';
#else
    return os << p.F << " " << p.S;
#endif
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
#ifdef DEBUG
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
#else
    string sep;
    for (const T &x : v)
        os << sep << x, sep = " ";
    return os;
#endif
}

void print() { cout << '\n'; }
template <typename Head, typename... Tail>
void print(Head H, Tail... T) { cout << H << ' ', print(T...); }

void read() { return; }
template <typename Head, typename... Tail>
void read(Head &H, Tail &...T) { cin >> H, read(T...); }

typedef tree<pii, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> oset;
const int inf = 1e9 + 7;

struct dsu
{
    vl p;
    dsu(int n) { p.resize(n), iota(all(p), 0LL); }
    int find(int u) { return u == p[u] ? u : find(p[u]); }
    void join(int u, int v) { p[find(v)] = find(u); }
    bool same(int u, int v) { return find(v) == find(u); }
};

template <typename T>
struct fen
{
    vector<T> f;
    fen(int n) { f.assign(n + 1, 0); }
    void add(int p, T v) { fru(i, ++p, sz(f), (i & -i)) f[p] += v; }
    T get(int p, T v)
    {
        T sum = 0;
        rfu(i, (++p), 1, (i & -i)) sum += f[p];
        return sum;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        read(n, s);

        fr(i, inf)
        {
            string cur;
            int v = i + 1;
            while (v > 0)
            {
                v--;
                cur += 'a' + v % 26;
                v /= 26;
            }
            reverse(all(cur));
            bool ok = true;
            fr(i, sz(s) - sz(cur))
            {
                if (s.substr(i, sz(cur)) == cur)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                print(cur);
                break;
            }
        }
    }
}
