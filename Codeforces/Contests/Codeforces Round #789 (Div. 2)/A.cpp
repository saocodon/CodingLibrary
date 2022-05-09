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
const int mxn = 1e5 + 1;

short n, t, m = 101;
int f[101];
bool c = false;

void solve(){
    if (m == 0) { cout << n - f[0] << ln; }
    else if (c && f[0] == 0) {
        cout << n << ln;
    } else if (!c && f[0] == 0) {
        cout << n + 1 << ln;
    }
}

void input(){
    cin >> n;
    fpp (i, 1, n) {
        cin >> t;
        f[t]++;
        if (f[t] == 2) c = true;
        m = min(m, t);
    }
}

void reset() {
    m = 101;
    memset(f, 0, sizeof(f));
    c = false;
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

