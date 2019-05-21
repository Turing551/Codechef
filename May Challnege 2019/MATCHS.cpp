#include <iostream>
#define ll long long
int main(){
    int t;
    std::cin >> t;
    while(t--){
        ll m,n;
        std::cin>>m>>n;
        if(m==n){
            std::cout << "Ari\n";
            continue;
        }
        if(m<n){
            swap(m,n);
        }
        ll res=m/n;
        if(res>1){
            std::cout << "Ari\n";
        }else{
            bool chance=1;
            while(m>0 && n>0){
                m -= (res*n);
                if(m<n){
                    swap(m,n);
                }
                res=m/n;
                if(res>1 && chance){
                    std::cout << "Rich\n";
                    break;
                }else if(res>1 && !chance){
                    std::cout << "Ari\n";
                    break;
                }else{
                    chance=!chance;
                    continue;
                }
            }
        }
    }
    return 0;
}
