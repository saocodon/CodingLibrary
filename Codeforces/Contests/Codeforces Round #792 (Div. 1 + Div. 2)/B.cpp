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

ll a, b, c;

void solve() {
    cout << (a + b + c) << sp << (b + c) << sp << c << ln;
}

void input() {
    cin >> a >> b >> c;
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

