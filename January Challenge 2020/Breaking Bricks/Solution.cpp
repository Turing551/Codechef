#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int res,x,y,z;
        cin>>res>>x>>y>>z;
        if(x+y+z <= res){
            cout<<"1\n";
        }else if(x+y<=res || y+z<=res){
            cout<<"2\n";
        }else{
            cout<<"3\n";
        }
    }
    return 0;
}
