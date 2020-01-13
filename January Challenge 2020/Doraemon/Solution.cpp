#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;
    cin>>n;
    while(n--){
        ll x,y,res=0;
        cin>>x>>y;
        ll arr[x+1][y+1];
	for(ll i=1;i<=x;i++){
            for(ll j=1;j<=y;j++){
                cin>>arr[i][j];
            }
        }
    for(ll i=1;i<=x;i++){
        for(ll j=1;j<=y;j++){
            for(ll k=0;k<min(x,y);k++){
                if(i+k<=x&&i-k>=1&&j+k<=y&&j-k>=1){
                    if(arr[i][j-k]==arr[i][j+k]&&arr[i-k][j]==arr[i+k][j]){
                        res++;
                    }
                    else 
                        break;
                }
            }
        }
    }
    cout<<res<<"\n";
    }
}
