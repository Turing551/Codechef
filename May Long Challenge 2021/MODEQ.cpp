#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        int res=0;
        vector<int> vec(x+1, 1);
        for(int i=2; i<=x; i++){
            int tmp = y%i;
            res += vec[tmp];
            for(int j=tmp; j<=x; j+=i){
                vec[j]++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
