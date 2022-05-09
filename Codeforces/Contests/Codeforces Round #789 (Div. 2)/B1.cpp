#include <bits/stdc++.h>
using namespace std;

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

void solve() {

}

void input() {
    int n;
    char s[mxn];
    vi sub;
    cin >> n >> s[1];
    int c = 0, m = 0;
    fpp (i, 2, n) {
        cin >> s[i];
        if (s[i] == s[i - 1]) { c++; }
        else {
            sub.pb(c + 1);
            if (sz(sub) > 1) {
                if (((sub[sz(sub) - 1] & 1) && (sub[sz(sub) - 2] & 1)) || ((sub[sz(sub) - 2] & 1) && ((sub[sz(sub) - 1] & 1) == 0))) {
                    m++;
                    sub[sz(sub) - 2]++;
                    sub[sz(sub) - 1]--;
                    if (sub[sz(sub) - 1] == 0) sub.pop_back();
                }
            }
            c = 0;
        }
    }
    sub.pb(c + 1);
    if (sz(sub) > 1) {
        if (((sub[sz(sub) - 1] & 1) && (sub[sz(sub) - 2] & 1)) || ((sub[sz(sub) - 2] & 1) && ((sub[sz(sub) - 1] & 1) == 0))) {
            m++;
            sub[sz(sub) - 2]++;
            sub[sz(sub) - 1]--;
            if (sub[sz(sub) - 1] == 0) sub.pop_back();
        }
    }
    cout << m << ln;
}

void reset() {

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        input();
        solve();
        reset();
    }
}

