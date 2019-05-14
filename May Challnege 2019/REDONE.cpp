#include <iostream>
#define ll long long
#define mod 1000000007
ll arr[1000001];
void solve(){
    arr[1]=1;
    for(int i=2;i<1000001;++i){
        ll x=(i)%mod;
        ll y=arr[i-1]%mod;
		ll p=(x+y)%mod;
		ll q=(x*y)%mod;
        arr[i]=(p+q)%mod;
    }
}
int main(){
    solve();
    int n;
    std::cin>>n;
    while(n--){
        ll temp;
        std::cin>>temp;
        std::cout<<arr[temp]<<"\n";
    }
    return 0;
}
