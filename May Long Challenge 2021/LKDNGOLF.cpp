#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    string ans="NO";
    if(y%z == 0){
        ans="YES";
    }
    if (y%z == (x+1) % z){
        ans="YES";
    }
    cout<<ans<<endl;
}

int main() {
    int x;
    cin>>x;
    for(int i=1; i<=x; i++){
        solve();
    }
    return 0;
}
