#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y,i,res;
        cin>>x>>y;
        int arr[x];
        for(i=0; i<x; i++) 
        cin>>arr[i];
        sort(arr,arr+x,greater<int>());
        res=y;
        for(i=y; i<x; i++){
            if(arr[i]==arr[y-1]) 
            res++;
        }
        cout<<res<<endl;
    }
    
}
