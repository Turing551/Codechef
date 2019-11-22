#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> temp;
char carr[]={'R','G','B'};
struct cal{
    int a,x,y,z;
};
struct child{
    unordered_set<int> S1,S2;
    int a,b,c,iarr[3];
    char ch;
};
vector<cal*> vec;
child* chd[512];
void solve(){
    int x1,y1,x2,y2,i,j;
    cin>>i>>j;
    vec.resize(j);
    cin>>x1>>y1>>x2>>y2;
    temp['R']=0;temp['G']=1;temp['B']=2;  
    for(int n=0;n<i;n++){
        chd[n]=new child;
        chd[n]->a=n;
        cin>>chd[n]->ch;
    }for(int n=0;n<i;n++){
        cin>>chd[n]->b>>chd[n]->c;
    }for(int n=0;n<j;n++){
        vec[n]=new cal;
        int b;
        cin>>vec[n]->x>>vec[n]->y>>vec[n]->z;
        vec[n]->x--; 
        vec[n]->y--; 
        vec[n]->z--;
        chd[vec[n]->x]->S1.insert(vec[n]->y);
        chd[vec[n]->x]->S1.insert(vec[n]->z);
        chd[vec[n]->y]->S1.insert(vec[n]->z);
        chd[vec[n]->y]->S1.insert(vec[n]->x);
        chd[vec[n]->z]->S1.insert(vec[n]->x);
        chd[vec[n]->z]->S1.insert(vec[n]->y);  
        chd[vec[n]->x]->S2.insert(n);
        chd[vec[n]->y]->S2.insert(n);
        chd[vec[n]->z]->S2.insert(n);
    }for(int n=0;n<i;n++){
        for(auto &b : chd[n]->S1){
            chd[n]->iarr[temp[chd[b]->ch]]++;
        }
    }
    int res=0;
    for(int n=0;n<i;n++){
        int  prev=0,curr=chd[n]->iarr[0];
        if(curr>chd[n]->iarr[1]){
            curr=chd[n]->iarr[1];
            prev=1;
        }if(curr>chd[n]->iarr[2]){
            curr=chd[n]->iarr[2];
            prev=2;
        }if(temp[chd[n]->ch] != prev){
            for(auto &c : chd[n]->S1){
                chd[c]->iarr[temp[chd[n]->ch]]--;
                chd[c]->iarr[prev]++;
            }
            chd[n]->ch=carr[prev];
            res++;
        }if(res==x2) break;
    }
    cout<<res<<" "<<0<<endl;
    for(int n=0;n<i;n++){
        cout<<chd[n]->ch;
    }
    cout<<endl;
}
int main(){
    solve();
    return 0;
}
