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
const int mxn = 2e5 + 1;

int n;
vt<int> g[mxn];

int topo_number(){
    vt<int> lst;
    int deg[mxn];
    // Init
    lst.clear();
    fpp (i, 1, n) deg[i] = 0;
    // Calculating in-degrees of vertices
    fpp (u, 1, n){
        for (int v = 0; v < sz(g[u]); v++){
            deg[g[u][v]]++;
        }
    }
    // Pushing vertices which deg[] = 0 into queue
    // dp[u] here = 0
    fpp (u, 1, n){
        if (deg[u] == 0) lst.pb(u);
    }
    // Consider (u, v) and eliminate from the graph
    int dp[mxn], ans = 1;
    //int maxx = 1, _maxx = 1;
    // Init dp[]
    fpp (i, 1, n) dp[i] = 1;
    
    for (int i = 0; i < lst.size(); i++){
        int u = lst[i];
        for (int v = 0; v < g[u].size(); v++){
            deg[g[u][v]]--;
            if (deg[g[u][v]] == 0){
                lst.pb(g[u][v]);
            }
            if (g[u][v] < u){
                dp[g[u][v]] = max(dp[g[u][v]], dp[u] + 1);
            }else{
                dp[g[u][v]] = max(dp[g[u][v]], dp[u]);
            }
            ans = max(ans, dp[g[u][v]]);
        }
    }
    if (lst.size() < n){
        return -1;
    }else{
        return ans;
    }
}

void input(){
    int t, k, u;
    cin >> t;
    while (t--){
        cin >> n;
        fpp (i, 1, n){
            cin >> k;
            fpp (j, 1, k){
                cin >> u;
                g[u].pb(i);
            }
        }
        cout << topo_number() << ln;
        // Init for next test case
        fpp (i, 1, n) g[i].clear();
    }
}

int main(){
    fastio;
    input();
}
