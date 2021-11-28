#include<bits/stdc++.h>
using namespace std;
#define NMAX 1000001
#define INF 1000000000000000001
int n,m,c1,c2;
struct p{
    int x;
    bool m;
};
p a[NMAX];
unsigned long long x=INF,y,d;
int r[1000001];
void nhap(){
    cin>>n>>m;
    cin>>c1>>c2;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
    }
    for(int i=n+1;i<=n+m;i++){
        cin>>a[i].x;
        a[i].m=true;
    }
    y=abs(c1-c2);
}
bool cmp(p &A, p&B){
    return A.x<B.x;
}
void xuat(){
    int z=0;//z is the one contains count
    sort(a+1,a+(n+m+1),cmp);
    for(int i=1;i<n+m;i++){
        if(a[i+1].m!=a[i].m){
            d=abs(a[i].x-a[i+1].x);
            if(x>d){
                x=d;
                z++;
                r[z]++;
            }else if(d==x){
                r[z]++;
            }
        }
    }
    cout<<x+y<<" "<<r[z];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    xuat();
}
