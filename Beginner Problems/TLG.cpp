#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
	int t,p1,p2,winner=1,score=0,score1=0,score2=0,lead=0;
	cin>>t;
	while(t--)
	{	
		cin>>p1>>p2;
		score1+=p1;
		score2+=p2;
		score=score1-score2;
	//	cout<<score<<" ";
		if(abs(score)>abs(lead))
		{
			lead=score;
			winner=score>0?1:2;
	//		cout<<lead<<endl;
		}	
	}
	//cout<<endl;
	cout<<winner<<" "<<abs(lead)<<endl;
		
	return 0;
}
