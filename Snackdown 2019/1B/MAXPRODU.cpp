#include <bits/stdc++.h>
using namespace std;
const int temp1=1e5+10;
const int temp2=1e9+7;
long long arr[temp1];

int main(){
    int n; 
    scanf("%d",&n);
    while(n--){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if((1+y)*y/2 > x)puts("-1");
        else{
            x=x-((y+1)*y/2);
            for(int i=1;i<=y;i++){
                arr[i]=x/y+i;
            }
            x=x%y;
            long long res=1;
            for(int i=y;i>=1;i--){
                if(x){
                    arr[i]++;
                    x--;
                }
                res=res*(arr[i]-1)%temp2*arr[i]%temp2;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}

