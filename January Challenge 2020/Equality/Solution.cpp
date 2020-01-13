#include<bits/stdc++.h>
using namespace std;
int main(){
	long long  n;
    int a,b,c,d,x1,y1,x2(0),y2(0);
    cin>>a>>b;
    vector<long long >vec;
    for(int i=0;i<a;i++){
        cin>>n;    
        vec.push_back(n);
    }
    int arr1[a]={0},arr2[a]={0},x=0,y=0;
    for(int i=0;i<a-1;i++){
        if(arr1[i]!=0 && vec[i]<vec[i+1])
            arr1[i+1]=x;
        else if(vec[i]<vec[i+1]){
            x++;
            arr1[i+1]=x;
        }
        else arr1[i+1]=0;
        if(arr2[i]!=0 && vec[i]>vec[i+1])
            arr2[i+1]=y;
        else if(vec[i]>vec[i+1]){
            y++;
            arr2[i+1]=y;
        }else arr2[i+1]=0;
    }for(int i=0;i<a;i++){
        if(arr1[i]>arr1[i+1])
            arr1[i+1]=arr1[i];
        if(arr2[i]>arr2[i+1])
            arr2[i+1]=arr2[i];
    }while(b--){
        cin>>c>>d;
        if(arr2[c]!=0 && vec[c]<vec[c-1] && arr2[c-1]==arr2[c])
            x2=arr2[d-1]-arr2[c-1]+1;
        else 
            x2=arr2[d-1]-arr2[c-1];
        if(arr1[c]!=0 && vec[c]>vec[c-1] && arr1[c-1]==arr1[c])
            y2=arr1[d-1]-arr1[c-1]+1;
        else 
            y2=arr1[d-1]-arr1[c-1];
        if(x2!=0 && x2==y2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        x2=0;
        y2=0;
    }
}
