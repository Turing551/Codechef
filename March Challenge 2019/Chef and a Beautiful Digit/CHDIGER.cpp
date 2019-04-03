#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    char a,b,arr[20];
    cin>>arr>>a;
    int k=0,len=strlen(arr);
    string str="";
    while(k!=len){
      b=arr[k];
      for(int i=k+1;i<len;++i)
        if(arr[i]<b){
          b=arr[i];
          k=i;
        }if(a>b){
        str+=b;
        k++;
      }else
        break;
    }
    cout<<str;
    int x=str.length();
    for(int j=0;j<len-x;j++)
      cout<<a;
    cout<<"\n";
  }
}
