#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        long long temp=1,x,y,i,j;
        cin>>x;
        int res[x],arr1[x],arr2[x];
        for(i=0; i<x; i++) 
        cin>>arr1[i];
        for(i=0; i<x; i++) 
        cin>>arr2[i];
        for(i=0; i<x;i++) 
        res[i]=arr2[i]-arr1[i];
        for(i=0; i<x-2; i++){
            if(res[i]<0){
                temp=0;
                break;                
            }
            y=res[i];
            res[i]=res[i]-y;
            res[i+1]=res[i+1]-(2*y);
            res[i+2]=res[i+2]-(3*y);
        }        
        if(res[x-1]!=0 || res[x-2]!=0) 
        cout<<"NIE"<<endl;
        else if(temp==0) 
        cout<<"NIE"<<endl;
        else cout<<"TAK"<<endl;       
    }
}
