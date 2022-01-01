// ***************************************************
// Factors with 10^9 still works with primes < 40000!
// ***************************************************

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long

const int mxP = 40000;

int t, a, b, k;

bool isPrime[mxP + 1];
vector<int> prime;

void sieve(){
    for (int i = 2; i <= mxP; i++) isPrime[i] = true;
    for (int i = 2; i <= mxP; i++){
        if (isPrime[i]){
            prime.push_back(i);
            for (int j = i * 2; j <= mxP; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int factor(int x){
    int cnt = 0;
    for (int i = 0; i < prime.size(); i++){
        while (x % prime[i] == 0){
            cnt++;
            x /= prime[i];
        }
    }
    if (x > 1) cnt++; // If it falls into this case, x is a prime number
    return cnt;
}

void solve(){
    if (k == 1){
        if (a != b){
            if (a % b == 0 || b % a == 0){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }else{
        if (k > factor(a) + factor(b)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}

void input(){
    sieve();
    cin >> t;
    while (t--){
        cin >> a >> b >> k;
        solve();
    }
}
int main(){
    fastio;
    input();
}
