#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
long int cnt;
for(int i=0;i<n;i++){
	long int a,b;
	int x,y=0,z=1;
	cin>>x>>cnt;
	long int arr[x];
for(int j=0;j<x;j++){
	cin>>arr[j];
	if(cnt%arr[j]!=0){
		b=j;
		y=1;
	}
}
int temp[x+1]={0};
if(y==1){
	temp[b]=1+(cnt/arr[b]);	
	z=0;
}else{
	for(int j=x-1;j>=0;j--){
		if(cnt%arr[j]==0){
			a=cnt/arr[j];
			cnt=cnt-arr[j]*(a-1);
			temp[j]=a-1; 
}else if(cnt%arr[j]!=0){
		a=cnt/arr[j];
		z=0;
		temp[j]=a+1;
		break; 
		}
	}
}if(z==0){
	cout<<"YES ";
	for(int j=0;j<x;j++){
		cout<<temp[j]<<" ";}
		cout<<endl;
}else if(z==1){
	cout<<"NO"<<endl;
	}
}
return 0;
}
