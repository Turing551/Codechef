#include <bits/stdc++.h>
using namespace std;
const int temp=1e5+10;
int p,q,r,s;
int arr[temp];
int main(){
    int n; 
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&p,&q,&r,&s);
        for(int i=0;i<p;i++)
        scanf("%d",&arr[i]);
        sort(arr,arr+p);
        int res=s*(p+q+1)-r;
        for(int i=0;i<p;i++){
            if(arr[i]>r){
                res=min(res,s*(q+i+1)-r);
                break;
            }
            res=min(s*(q+i+1)-arr[i],res);
        }
        printf("%d\n",max(0,res));
    }
    return 0;
}
