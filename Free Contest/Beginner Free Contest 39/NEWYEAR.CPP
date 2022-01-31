/* Solution derived from Free Contest
 * Proof: while iterating backwards, when we update max, that number will move to the left of the max of the array
 * -> when we hit the max of the array, we end up with the answer.
 */

/* This problem is also on Codeforces: 1585B - Array Eversion */

#include <bits/stdc++.h>

using namespace std;

int t, n, a[200001];

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int m = a[n], c = 0;
        for (int i = n - 1; i >= 1; i--){
            if (a[i] > m){
                m = a[i];
                c++;
            }
        }
        cout << c << "\n";
    }
}