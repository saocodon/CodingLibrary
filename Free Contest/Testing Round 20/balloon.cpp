// DP Space Optimization + Sliding Window Deque

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

int n, m, k;

// When operating with each other, these arrays should be the same type
ll a[mxn], dp[2][mxn];

void solve(){
    // In case n = 1
    ll ans = *max_element(a + 1, a + 1 + n);
    
    fpp (i, 2, k){
        bool cur = i & 1; // Returns true if i is odd, otherwise false
        bool pre = !cur;
        deque<int> q;
        fpp (j, 1, n){
	    // Clearing out of bound elements 
            while (!q.empty() && q.front() < j - m) q.pop_front();
	    // Values set to -2e15 are wrong, we don't need to care about 'em
            ll mx = q.empty() ? -2e15 : dp[pre][q.front()];
            dp[cur][j] = mx + i * a[j];
            ans = max(ans, dp[cur][j]);
            // Finding max for next window
            while (!q.empty() && dp[pre][j] >= dp[pre][q.back()]) q.pop_back();
            q.pb(j);
        }
    }
    cout << ans << ln;
}

void input(){
    cin >> n >> m >> k;
    fpp (i, 1, n){
        cin >> a[i];
        dp[1][i] = a[i];
    }
    solve();
}

int main(){
    fastio;
    input();
}
