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
const int mxn = 1e5 + 1;

int n, k;

// Stable power function
ll power(int b, int e) {
    ull res = 1;
    fpp (i, 1, e) {
        res *= b;
        res %= mod;
    }
    return res;
}

void solve(){
    vi s;
    ull nm = 0;
    // Binary to decimal in O(log n)
    while (k) {
        s.pb(k & 1);
        k >>= 1;
    }
    fmm (i, sz(s) - 1, 0) {
        if (s[i] == 1) {
            nm += power(n, i);
            nm %= mod;
        }   
    }
    cout << nm << ln;
}


void input(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        solve();
    }
}

int main(){
    fastio;
    input();
}
