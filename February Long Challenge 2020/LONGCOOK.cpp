#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int iarr[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(ll c){
	return (c%100||c%400==0)&&c%4==0;
	}	
ll calculate(ll b,ll c){
	return iarr[b-1]+(b==2&&leap(c));
	}
int solve(int a,int b,int c){
	static int arr[]={0,3,2,5,0,3,5,1,4,6,2,4};
	c-=b<3;
	return (c+c/4-c/100+c/400+arr[b-1]+a)%7;
}
ll resolve(ll b,ll c){
	int x=calculate(b,c),a=1;
	while(solve(a,b,c)!=5) a++;
	for(int i=0,k=2;i<k;++i){
		while(solve(x,b,c)) x--;
		if(!i)x--;
	}
	return a+10>=x;
}
int temp[500];
ll sol(ll c){
	if(!c)return 0;
	ll res=(c/400)*101;
	c=c%400;
	if(c) res=res+temp[c-1];
	return res;
}

int main(){
	for(int i=0,k=500;i<k;++i) temp[i]=resolve(2,i+1)+(i?temp[i-1]:0);
	int n; 
	cin>>n;
	while(n--){
		int res=0,p,q,r,s;
		cin>>p>>q>>r>>s;
		if(p>2) q++;
		if(r<2) s--;
		cout<<sol(s)-sol(q-1)<<"\n";
	}
}
