#include <bits/stdc++.h>
using namespace std;

// Files for pbds: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int mod = 1e9 + 7;
const int mxn = 1e5 + 1;

void input(){
    pbds st;
    int l, q, c, x;
    cin >> l >> q;
    st.insert(1);
    st.insert(l);
    while (q--){
        cin >> c >> x;
        st.insert(x);
        if (c == 2){
            int k = st.order_of_key(x);
            int L = *(st.find_by_order(k - 1)), R = *(st.find_by_order(k + 1));
            if (k - 1 > 0) L++;
            cout << R - L + 1 << ln;
            st.erase(st.find(x));
        }
    }
}

int main(){
    fastio;
    input();
}
