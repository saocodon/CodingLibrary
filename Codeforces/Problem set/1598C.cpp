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

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;

int t, n, a[mxn];
ull s = 0;

int freq(int l, int r, int x){
    int L = l, R = r, al = 0, ar = 0;
    while (L <= R){
        int m = (L + R) / 2;
        if (a[m] == x){
            al = m;
            R = m - 1;
        }
        if (a[m] > x) R = m - 1;
        if (a[m] < x) L = m + 1;
    }
    if (al <= 0) return -1;
    L = l; R = r;
    while (L <= R){
        int m = (L + R) / 2;
        if (a[m] == x){
            ar = m;
            L = m + 1;
        }
        if (a[m] > x) R = m - 1;
        if (a[m] < x) L = m + 1;
    }
    return ar - al + 1;
}

void solve(){
    // Write k as s / n to avoid rounding
    if ((2 * s) % n != 0){
        // If k is not an integer, print 0
        cout << "0\n";
    }else{
        sort(a + 1, a + 1 + n);
        ull ans = 0;
        fpp (i, 1, n){
            int r = freq(i + 1, n, 2 * s / n - a[i]);
            if (r > -1) ans += r;
        }
        cout << ans << ln;
    }
}

void input(){
    cin >> t;
    while (t--){
        // Reset
        s = 0;
        cin >> n;
        fpp (i, 1, n){
            cin >> a[i];
            s += a[i];
        }

        solve();
    }
}

int main(){
    fastio;
    input();
}
