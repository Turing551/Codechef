#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int  uint64;
const int mod = 1e9+7;

class Path{
public:
	vector<uint64> arr1,arr2;
	vector<vector<int>> vec;
	void add(int a,int b);
	void dfs(int a,int c);
};

void Path::dfs(int a, int c){
	arr1[a]=1, arr2[a]=1;
	uint64 x=0, y=0;
	for(int i=0; i<vec[a].size();i++){
		uint64 tmp=vec[a][i];
		if(tmp != c){
			dfs(tmp,a);
			arr1[a] += ((2 * arr1[tmp]) % mod);
			arr1[a] %= mod;
			y++;
			arr2[a] += arr2[tmp];
			arr2[a] %= mod;
			arr2[a] += arr1[tmp];
			arr2[a] %= mod;
			x += arr1[tmp];
		}
	}for(int i=0; i<vec[a].size(); i++){
		int tmp=vec[a][i];
		if(tmp != c){
			arr2[a] += (arr1[tmp] * ((x - arr1[tmp] + mod) % mod)) % mod;
			arr2[a] %= mod;
		}
	}
}

void Path::add(int a, int b){
	vec[a].push_back(b);
	vec[b].push_back(a);
}

void solve(){
	int j;
	cin>>j;
	Path g;
	g.vec.resize(j + 1);
	for(int i=0; i<j-1; i=i+1){
		int c,a;
		cin>>c>>a;
		g.add(c,a);
	}
	g.arr1.resize(j+1);g.arr2.resize(j+1);
	g.dfs(1,1);
	uint64 res = g.arr2[1]%mod;
	cout<<res<<endl;
	g.arr1.clear();g.arr2.clear();g.vec.clear();
	return;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
