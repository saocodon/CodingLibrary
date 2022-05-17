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
const int mxn = 1e5 + 5;

int n, t;
string s;
map<string, int> sub;

void input() {
    int mx = 0, ans = 1;
    cin >> n;
    fpp (i, 1, n) {
        cin >> s >> t;
        if (sub.count(s) == 0) {
            sub.insert({s, t});
            if (t > mx) {
                mx = t;
                ans = i;
            }
        }
    }
    cout << ans << ln;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
}

