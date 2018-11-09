#include <iostream>
using namespace std;

int x,y,arr[100100];
int main(){
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>y;
        for(int j=1;j<=y;j++)
            cin>>arr[j];
        int j;
        for(j=2;j<=y;j++){
            if(arr[j-1]>arr[j])
                break;
        }
        if(j<y){
            int k;
            for(k=j;k<=y;k++){
                if(arr[k-1]>arr[k] && j!=k){
                    break;
                } }
            if(arr[y]<=arr[1] && k==y+1){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            } }
        else{
            cout<<"YES";
        }
        cout<<endl;
    }
    return 0;
}

// Accepted
