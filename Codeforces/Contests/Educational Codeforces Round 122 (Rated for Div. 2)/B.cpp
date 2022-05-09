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
string s;

// Calculate 2 cases: a substring which one '0' or '1' has been omitted (we want the substring to be as long as possible)
void solve(){
    int a = 0, b = 0; // a 0, b 1
    fpp (i, 0, s.length() - 1){
        if (s[i] == '0') {a++;}
        else {b++;}
    }
    cout << max(min(a - 1, b), min(a, b - 1)) << ln;
}

void input(){
    cin >> t;
    while (t--){
        cin >> s;
        solve();
    }
}
int main(){
    fastio;
    input();
}
