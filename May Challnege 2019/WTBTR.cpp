#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        int *a=new int[temp];
        int *b=new int[temp];
        for(int i=0;i<temp;i++){
            int p,q;
            cin>>p>>q;
            a[i]=p+q;
            b[i]=p-q;
        }
        sort(a,a+temp);
        sort(b,b+temp);
        double res = abs(a[0]-a[1])/2.0;
        res = min(abs(b[0]-b[1])/2.0,res);
        for(int i=1;i<temp-1;i++){
            res=min(abs(a[i]-a[i+1])/2.0,res);
            res=min(abs(b[i]-b[i+1])/2.0,res);
            if(res==0.0){
                break;
            }
        }
        cout << fixed << setprecision(6) << res << endl;
    }
    return 0;
}
