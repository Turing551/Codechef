#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int x,y;
    string str;
    cin>>x;
    while(x--){
        map<string,int>word;
        int res=0;
        cin>>y;
        while(y--){
            int a=0,b=0,c=0;
            cin>>str;
            for(int i=0;i<str.size();i++){
                if(a>0&&(str[i]=='f'||str[i]=='d')){
                    c=c+4;
                }
                else if(a==0&&(str[i]=='f'||str[i]=='d')){
                    c=c+2;
                    a++;
                    b=0;
                }  
                else if(b>0&&(str[i]=='k'||str[i]=='j')){
                    c=c+4;
                }
                else if(b==0&&(str[i]=='k'||str[i]=='j')){
                    c=c+2;
                    b++;
                    a=0;
                } }
            res=res+c;
            if(word[str]>0)
                res=res-(c/2);
            else
            word[str]++;
        }
        cout<<res<<endl;
    } }

//Accepted
