#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long int t,p;
	cin >> t;
	for(long long int j=0; j<t; j++){		
    cin >>p;
    long long int i=10 , z=p , count =0 ,k;
    if(z>=2048){  
    k = z/2048;
      count = count +k;
        z= z - (2048* k);   
    }
    while(i>=0 && z>0){
    if(z>=pow(2,i)){
        count++;
        z = z-pow(2,(i));   
    }else{
        i--;      
    }
}      
  cout << count << endl; 
	}
	return 0;
}
