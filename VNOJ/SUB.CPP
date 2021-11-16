#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL -10000
int T,N,t;
vector<int> A;
bool cmp(const int &a, const int &b){
    return a>b;
}
void nhap(){
    ll S1=0, S2=LL, max_ending_here=0, maxe=LL;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N;
        S1=0; S2=LL; max_ending_here=0; maxe=LL;
        A.clear();
        for(int j=1;j<=N;j++){
            cin>>t;
            A.push_back(t);
            //Kadane's Algorithm
            max_ending_here+=t;
            if(max_ending_here<=0){
                max_ending_here=0;
            }
            if(S2<max_ending_here){
                S2=max_ending_here;
            }
            if(maxe<t){
                maxe=t;
            }
        }
        if(S2==0){
            S2=maxe;
        }
        sort(A.begin(),A.end(),cmp);
        /*for(int k=0;k<A.size();k++){
            cout<<A[k]<<" ";
        }
        cout<<endl;*/

        S1=A[0];
        for(int k=1;k<A.size();k++){
            S1=max(S1,S1+A[k]);
        }
        cout<<S1<<" "<<S2<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
}
