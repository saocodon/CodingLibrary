#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long

int t, a, b;

void solve(){
    int S = a, x, n = a - 1;

    if (n % 4 == 0){
        x = n;
    }else if (n % 4 == 1){
        x = 1;
    }else if (n % 4 == 2){
        x = n + 1;
    }else if (n % 4 == 3){
        x = 0;
    }

    if ((b ^ x) == a){
        S++;
    }

    if (x != b){
        S++;
    }

    cout << S << "\n";
}

void input(){
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b;
        solve();
    }
}
int main(){
    fastio;
    input();
}
