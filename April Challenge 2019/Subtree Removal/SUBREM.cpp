#include <bits/stdc++.h>
#define val 1000010
using namespace std;
vector<int> arr1[val];
int x,y,z;
long long arr2[val],arr3[val],k;
inline void solve3(int p,int q){
	arr3[p]=0;
	for(auto temp:arr1[p]){
		if(temp==q) continue;
		solve3(temp,p);
		arr3[p]=arr3[p]+arr3[temp];
	}
	arr3[p]=max(-k-arr2[p],arr3[p]);
}
inline void solve2(int p,int q){
	for(auto temp:arr1[p]){
		if(temp==q) continue;
		solve2(temp,p);
		arr2[p]=arr2[p]+arr2[temp];
	}
}
template <class x>
inline void solve1(x& k){
	k=0; 
	int arr3=1; 
	char ch = getchar();
	for(; !isdigit(ch);ch=getchar()) if (ch == '-') arr3=-1;
	for(; isdigit(ch);k = k * 10 + ch - '0', ch=getchar());
	k=k*arr3;
}
int main(){
	solve1(x);
	while(x--){
		solve1(y), solve1(k); z=0;
		for(int i=1;i<=y;++i) arr1[i].clear();
		for(int i=1;i<=y;++i) solve1(arr2[i]);
		for(int i=1,p,temp;i<y;++i){
			solve1(p), solve1(temp);
			arr1[p].emplace_back(temp);
			arr1[temp].emplace_back(p);
		}
		solve2(1,0); 
		solve3(1,0);
		cout<<arr2[1]+arr3[1]<<endl;
	}
	return 0; 
}
