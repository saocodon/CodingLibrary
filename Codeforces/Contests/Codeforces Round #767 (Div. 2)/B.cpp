#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define vt vector
#define pb push_back
#define sz(A) A.size()

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;

int t, l, r, k;

/* To make GCD > 1, make GCD = 2 => transform the array into an even array => calculating moves by multiplying an odd with an even number will produce an even number */
void solve(){
    if (l == r && l > 1){
        cout << "YES\n";
    }else{
        int m = (r - l + 1) / 2;
        if ((r - l + 1) % 2 == 1 && r % 2 == 1) m++;
        if (m <= k) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
}

void input(){
    cin >> t;
    while (t--){
        cin >> l >> r >> k;
        solve();
    }
}
int main(){
    fastio;
    input();
}
