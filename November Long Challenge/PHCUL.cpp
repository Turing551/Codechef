#include <bits/stdc++.h>
#include <cmath>
using namespace std;
struct point{
    long long int a;
    long long int b;
};
double result(point* &x1, point* &y1){
    double k = (x1->a-y1->a)*(x1->a-y1->a) + (x1->b-y1->b)*(x1->b-y1->b);
    k = sqrt(k);
    return k;
}
void solve(){
    point* P = new point;
    cin>>P->a>>P->b;
    int x,y,z;
    cin>>x>>y>>z;
    point *p[x],*q[y],*r[z];
    for(int i=0;i<x;i++){
        p[i]=new point;
        cin>>p[i]->a>>p[i]->b;
    }for(int i=0;i<y;i++){
        q[i]=new point;
        cin>>q[i]->a>>q[i]->b;
    }for(int i=0;i<z;i++){
        r[i]=new point;
        cin>>r[i]->a>>r[i]->b;
    }
    double arr1[x],arr2[y],arr3[x],arr4[y];
    double temp=(double)LLONG_MAX;   
    for(int i=0;i<x;i++)
        arr1[i]=result(P,p[i]);
    for(int i=0;i<y;i++)
        arr2[i]=result(P,q[i]);
    for(int i=0;i<x;i++){
        arr3[i]=(double)LLONG_MAX;
        for(int j=0;j<y;j++)
            arr3[i]=min(arr2[j]+result(p[i],q[j]),arr3[i]);
    }for(int i=0;i<y;i++){
        arr4[i]=(double)LLONG_MAX;
        for(int j=0;j<x;j++)
            arr4[i]=min(arr1[j]+result(q[i],p[j]),arr4[i]);
    }for(int i=0;i<z;i++){
        for(int j=0;j<x;j++)
            temp=min(arr3[j]+result(r[i],p[j]),temp);
        for(int j=0;j<y;j++)
            temp=min(arr4[j]+result(r[i],q[j]),temp);
    }
    cout<<setprecision(11)<<temp<<endl;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        solve();
    }
	return 0;
}
