#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fmm(a, b, c) for (int a = b; a >= c; a--)
#define printarr(arr, st, en) fpp(i, st, en) cout << arr[i] << sp; cout << ln;

#define vt vector
#define pb push_back
#define sz(A) A.size()
#define uid uniform_int_distribution<int>
#define vi vector<int>

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;

int n, r[mxn];
vi v[mxn];
set<int> s;

void solve(){
    if (s.empty()) {
        cout << "-1\n"; 
    } else {
        int cnt = 0, ans = 1;
        int u = *s.begin();
        while (!s.empty()) {
            if (sz(v[u]) > 0) {
                fpp (i, 0, sz(v[u]) - 1) {
                    r[v[u][i]]--;
                    if (r[v[u][i]] == 0) s.insert(v[u][i]);
                }
            }
            cnt++;
            // Get largest element in set using *s.rbegin()
            if (*s.rbegin() == u) {
                s.erase(u);
                u = *s.begin();
                ans++;
                
            } else {
                s.erase(u);
                u = *s.lower_bound(u);
            }
        }
        if (cnt < n) {
            cout << "-1\n";
        } else {
            cout << ans - 1 << ln;
        }
    }
}

void input(){
    int t, k, u;
    cin >> t;
    while (t--){
        cin >> n;
        fpp (i, 1, n) {
            cin >> k;
            fpp (j, 1, k) {
                cin >> u;
                v[u].pb(i);
            }
            r[i] = k;
            if (k == 0) s.insert(i);
        }
        solve();
        // Init for next test case
        memset(r, 0, sizeof(r));
        s.clear();
        fpp (i, 1, n) v[i].clear();
    }
}

int main(){
    fastio;
    input();
}
