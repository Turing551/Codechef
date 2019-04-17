#include <bits/stdc++.h>
#define val 200010
using namespace std;
vector<int> arr[val],res;
int a,b,c,d[val];
long long arr1[val],arr2[val],arr3[val],arr4[val];
inline long long gcd(long long p,long long q){ 
	return q == 0 ? p : gcd(q,p%q); 
	}
template <class a>
inline void solve1(a& p){
	p=0; 
	char ch=getchar();
	for(; !(ch<='9' && ch>='0');ch=getchar());
	for(; ch<='9' && ch>='0';p=p * 10 + ch - '0', ch=getchar());
}
inline void solve2(int x,int y){
	d[x]=y; 
	arr4[x]=gcd(arr1[x],arr4[y]);
	int k=0;
	for(auto temp1:arr[x]){
		if(temp1==y) continue;
		++k;
		solve2(temp1,x);
	}
	if(k==0) res.emplace_back(x);
}
int main(){
	solve1(a);
	while(a--){
		solve1(b);
		c=0; 
		res.clear();
		for(int i=1;i<=b;++i) arr[i].clear();
		for(int i=1,x,temp1;i<b;++i){
			solve1(x), solve1(temp1);
			arr[x].emplace_back(temp1);
			arr[temp1].emplace_back(x);
		}
		for(int i=1;i<=b;++i) solve1(arr1[i]);
		for(int i=1;i<=b;++i) solve1(arr2[i]);
		solve2(1,0);
		sort(res.begin(),res.end());
		for(auto temp2:res){
			if(arr2[temp2]<arr4[temp2])
				arr3[++c]=0;
			else if(arr2[temp2]%arr4[temp2] == 0)
				arr3[++c]=arr2[temp2]-arr4[temp2];     
			else
				arr3[++c]=arr2[temp2]-gcd(arr2[temp2],arr4[temp2]);
		}
		for(int i=1;i<=c;++i){
			cout<<arr3[i];
			if(i==c) 
				cout<<endl;
			else 
				cout<<" ";
		}
	}
	return 0;
}
