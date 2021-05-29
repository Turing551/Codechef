#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    int ans = y +(100-x)*z;
    ans *= 10;
    cout<<ans<<endl;
}

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) 
		solve();
    return 0;
}
