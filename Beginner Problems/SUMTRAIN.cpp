#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n,m;
	int triangle[100][100] = {0};
	scanf("%d",&n);

	while(n--){
		scanf("%d",&m);

		for(int i = 0; i <m; i++){
			for(int j = 0; j<= i; j++){
				scanf("%d", &triangle[i][j]);
			}
		}

		//DP - start from last but one row and keep on adding up best possible element for a cell
		for(int i = m-2; i>=0; i--){
			for(int j = 0; j<= i; j++){
				if(triangle[i+1][j] > triangle[i+1][j+1]) triangle[i][j] += triangle[i+1][j];
				else triangle[i][j] += triangle[i+1][j+1];
			}
		}

		printf("%d\n", triangle[0][0]);

	}

	return 0;
}
