#include <iostream>
#include <set>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    unsigned t;
    std::cin >> t;
    for(unsigned i = 0; i < t; ++i){
        unsigned cnt = 0;
        unsigned n;
        std::cin >> n;
        for(unsigned j = 0; j < n; ++j){
            std::string line(n, '.');
            line[j] = 'O';
            cnt++;
            if(j + 1 < n){
                line[j + 1] = 'O';
                cnt++;
            }
            if(j >= 2){
                line[j - 2] = 'O';
                cnt++;
            }     
            if(j + 5 < n){
                line[j + 5] = 'O';
                cnt++;
            }
            if(j >= 8){
                line[j - 8] = 'O';
                cnt++;
            }
            if(j + 15 < n){
                line[j + 15] = 'O';
                cnt++;
            }            
            if(j >= 20){
                line[j - 20] = 'O';
                cnt++;
            }
            
            if(j + 31 < n){
                line[j + 31] = 'O';
                cnt++;
            }
            if(j >= 44){
                line[j - 44] = 'O';
                cnt++;
            }
            
            if(j + 53 < n){
               line[j + 53] = 'O';
               cnt++;
            }            
            /*
            if(j + 30 < n){
                line[j + 30] = 'O';
                cnt++;
            }            
            if(j + 44 < n){
                line[j + 44] = 'O';
                cnt++;
            }
            if(j + 65 < n){
                line[j + 65] = 'O';
                cnt++;
            }
            if(j + 90 < n){
                line[j + 90] = 'O';
                cnt++;
            }
            */
        
            std::cout << line << "\n";
        }
        //std::cout << cnt << "\n";
    }
    return 0;
}
