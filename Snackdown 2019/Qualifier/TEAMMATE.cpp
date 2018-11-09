#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
while(n--){
    long long x,y,i,j=0,res=1;
    long long k=pow(10,9)+7;
    cin>>x;
    long long arr[x],cnt[x];
    fill(cnt,cnt+x,1);
    for(i=0; i<x; i++) 
    cin>>arr[i];
    sort(arr,arr+x,greater<int>());
    for(i=1; i<x; i++){
        if(arr[i]==arr[i-1]){
        cnt[j]=cnt[j]+1;        
        }
        else j++;
}
    y=x;
    x=j+1;
    for(i=0; i<x; i++){    
        if(cnt[i]<=0) 
        continue;
        if(cnt[i]%2==0){        
        for(j=cnt[i]-1; j>2; j=j-2){
            res=res*j;
            res=res%k;
        }
        }
        else{        
            for(j=cnt[i]; j>2; j=j-2){
            res=res*j;
            res=res%k;
        }
        if(i!=x-1) 
        res=res*cnt[i+1];
        cnt[i+1]=cnt[i+1]-1;
        res=res%k;
    }
    }
cout<<res<<endl;
}
}
