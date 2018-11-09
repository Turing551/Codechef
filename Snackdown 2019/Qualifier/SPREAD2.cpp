#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int x,i;
		cin>>x;
		int arr[x];
		for(i=0; i<x; i++) 
		cin>>arr[i];
		int a=1,b=0,total=0,res=0;
		while(a<x){
			res++;
			for(i=b; i<a; i++){
				total=total+arr[i];
				if(total+a>=x) 
				break;
			}
			b=i;
			a=a+total;		
		}
		cout<<res<<endl;
	}
}
