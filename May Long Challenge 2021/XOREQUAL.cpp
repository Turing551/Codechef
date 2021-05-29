#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(int x,int y,int z) {
    if(y == 1){
        return x;
    }if(y == 0){
        return 1;
    }
    ll ans = power(x, y/2, z);
    ans = (ans*ans) % z;
    if(y%2){
        ans=(ans * x) % z;
    }
    return ans;
}

void solve() {
    int a;
    cin>>a;
    cout<<power(2,a-1,1e9+7)<<endl;
}

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        solve();
    }
    return 0;
}
