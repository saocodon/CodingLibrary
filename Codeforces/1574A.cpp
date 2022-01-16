/*
 * A regular bracket sequence is a sequence which has enough "(" and ")" pairs and they were put properly, e.g. () 1 open 1 close, (()) 2 open 2 close, (())() 2 open 2 close + 1 open 1 close 
 */

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "

#define ll long long
#define ull unsigned long long

int T, n, x[101], t[101], c = 0;

void build(int i){
    string s;
    for (int k = 1; k <= i; k++){
        for (int l = 1; l <= x[k] * 2; l++){
            if (l <= x[k]) { s += "("; }
            else { s += ")"; }
        }
    }
    cout << s << ln;
    c++;
}

/* Sum analysis */
void Try(int i){
    for (int j = x[i - 1]; j <= ((n - t[i - 1]) / 2); j++){
        x[i] = j;
        t[i] = t[i - 1] + j;
        Try(i + 1);
    }
    x[i] = n - t[i - 1];
    if (c < n) build(i);
}

void solve(){
    c = 0;
    x[0] = 1;
    Try(1);
}

void input(){
    cin >> T;
    while (T--){
        cin >> n;
        solve();
    }
}
int main(){
    fastio;
    input();
}
