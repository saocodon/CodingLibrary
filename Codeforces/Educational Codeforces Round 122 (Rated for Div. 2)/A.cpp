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
string d[150];

int t, n;

// Framework for minimum moves, different from 'Make A Power of Two - 1560D'
void solve(){
    int x = 4;
    string N = to_string(n), ans;
    fpp (i, 1, 142){
        if (N.length() == d[i].length()){
            int j = 0, k = 0, c = 0;
            fpp(j, 0, N.length() - 1){
                if (N[j] != d[i][j]){
                    c++;
                }
            }
            if (x > c){
                x = c;
                ans = d[i];
            }
        }
    }
    cout << ans << ln;
}

void input(){
    fpp (i, 1, 142){ d[i] = to_string(7 * i); }
    cin >> t;
    while (t--){
        cin >> n;
        solve();
    }
}
int main(){
    fastio;
    input();
}
