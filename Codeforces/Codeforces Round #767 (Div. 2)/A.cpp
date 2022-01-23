#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define vt vector
#define pb push_back
#define sz(A) A.size()

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;

int t, n, k, a[101], b[101];

/* Recursive QuickSort, middle pivot O(n*log(n)), prevent worst case when choosing last element as pivot in a sorted array O(n^2) */
void quickSort(int low, int high){
    if (low >= high) return;
    int left = low, right = high, pivot = a[(low + high) / 2];
    while (left <= right){
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left <= right){
            swap(a[left], a[right]);
            swap(b[left], b[right]);
            left++; right--;
        }
    }
    if (low < right) quickSort(low, right);
    if (left < high) quickSort(left, high);
}

void solve(){
    quickSort(1, n);
    fpp (i, 1, n){
        if (k >= a[i]){
            k += b[i];
        }else{
            break;
        }
    }
    cout << k << ln;
}

void input(){
    cin >> t;
    while (t--){
        cin >> n >> k;
        fpp (i, 1, n) cin >> a[i];
        fpp (i, 1, n) cin >> b[i];
        solve();
    }
}
int main(){
    fastio;
    input();
}
