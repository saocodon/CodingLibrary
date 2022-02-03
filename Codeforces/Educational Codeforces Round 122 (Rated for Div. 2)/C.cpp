#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fmm(a, b, c) for (int a = b; a >= c; a--)
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define printarr(arr, st, en) fpp(i, st, en) cout << arr[i] << sp;

#define vt vector
#define pb push_back
#define sz(A) A.size()

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;

int t;
ull hc, dc, hm, dm, k, w, a;

// Not the best way, reference: https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
ull ceilDivision(ull x, ull y){
    ull q = x / y;
    if (q * y < x) q++;
    return q;
}

void solve(){
    bool x = false;
    ull kw = 0, ka = 0;
    // With an adequate k, do not use Binary Search (k < 2e5)
    fpp (i, 0, k){
        kw = i; ka = k - kw;
        if (ceilDivision((hc + ka * a), dm) >= ceilDivision(hm, dc + kw * w)){
            cout << "YES\n";
            x = true;
            break;
        }
    }
    if (!x){
        cout << "NO\n";
    }
}

void input(){
    cin >> t;
    while (t--){
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        solve();
    }
}
int main(){
    fastio;
    input();
}
