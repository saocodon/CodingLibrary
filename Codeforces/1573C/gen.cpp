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

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxn = 1e5 + 1;

void input(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> d(2, 10); // you can test n = 1 by hand
    int n = d(gen);
    uniform_int_distribution<int> _d(1, n), _k(0, n - 1);
    cout << "1\n";
    cout << n << ln;
    bool c[11];
    fpp (i, 1, n){
        int k = _k(gen), j = 1;
        cout << k << sp;
        memset(c, 0, sizeof(c));
        while (j <= k){
            int u = _d(gen);
            if (u != i && !c[u]){
                c[u] = true;
                cout << u << sp;
                j++;
            }
        }
        cout << ln;
    }
}

int main(){
    fastio;
    input();
}
