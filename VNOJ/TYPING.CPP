#include <bits/stdc++.h>
using namespace std;
string s;
int d=0;
unsigned long long S=1;
int main(){
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]){
            d++;
        }else{
            S*=(d+1);//multiply rule
            if(S>=1000000007)S%=1000000007;
            d=0;
        }
    }
    cout<<S;
}
