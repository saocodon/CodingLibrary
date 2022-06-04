#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fmm(a, b, c) for (int a = b; a >= c; a--)
#define pr(a, b, c) fpp (i, b, c) cout << a[i] << sp; cout << ln;

#define vt vector
#define pb push_back
#define sz(A) A.size()
#define uid uniform_int_distribution<int>

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxn = 1e5 + 1;

int s, n;
int p[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

void solve() {
    vt<int> num;
    num.pb(s);
    while (sz(num) < n) {
        int maxx = 0, minn = 1e9 + 1, maxi = 0, mini = 0;
        fpp (i, 0, sz(num) - 1) {
            if (num[i] > maxx && !binary_search(p, p + 10, num[i])) {
                maxx = num[i];
                maxi = i;
            }
            if (num[i] < minn && num[i] > 1 && binary_search(p, p + 10, num[i])) {
                minn = num[i];
                mini = i;
            }
        }
        if (maxx > 0) {
            // analyse this first (prioritised)
            int nd = floor(log10(maxx) + 1) - 1;
            num.erase(num.begin() + maxi);
            num.pb(p[nd]);
            num.pb(maxx - p[nd]);
        } else if (minn < 1e9 + 1) {
            // analyse this later
            int nd = floor(log10(minn) + 1) - 2;
            num.erase(num.begin() + mini);
            num.pb(p[nd]);
            num.pb(minn - p[nd]);
        } else { break; }
    }

    pr(num, 0, sz(num) - 1);
}

void input() {
    cin >> s >> n;
}

void reset() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
        reset();
    }
}
