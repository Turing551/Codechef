#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	bool flag;
	for(int t=0;t<T;t++){
		int tasks[4];
		int arr[2][150];
		flag=false;
		for(int n=0;n<2;n++){
			for(int m=0;m<150;m++){
				arr[n][m]=0;
			}
		}
		for(int n=0;n<4;n++){
			cin>>tasks[n];
			int temp;
			for(int m=0;m<tasks[n];m++){
				cin>>temp;
				if(n<2){
					arr[n][temp]=1;
				}else{
					if(arr[n-2][temp]==0){
						flag=true;
					}
				}
			}
		}
		if(flag){
			cout<<"no\n";
		}else{
			cout<<"yes\n";
		}
	}
	return 0;
}
