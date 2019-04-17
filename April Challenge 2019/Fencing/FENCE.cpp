#include "bits/stdc++.h"
using namespace std;

const int a=100000,b=1000000;
int arr1[]={-1,0,1,0},arr2[]={0,-1,0,1},x,y,z;
map <pair<int,int>,bool> temp;
inline bool solve(int p,int q){
    return (p>=1 && q>=1 && p<=x && q<=y);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
    scanf("%d %d %d",&x,&y,&z);
    for(int i=0;i<z;i++){
        int p,q; 
	scanf("%d %d",&p,&q);
        temp[{p,q}]=true;
    }
    int c=0,ans=0,y;
    for(auto k:temp){
        int p=k.first.first;
        int q=k.first.second;
        y=0;
        for(int i=0;i<4;i++){
            int x1=arr2[i]+p;
            int y1=arr1[i]+q;
            if(temp.count({x1,y1}) && solve(x1,y1)){
                y++;
            }
        }
        c=4-y;
        ans+=c;
    }
    cout<<ans<<endl;
    temp.clear();
}
}
