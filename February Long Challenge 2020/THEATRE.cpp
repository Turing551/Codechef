#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,res=0;
	cin>>n;
	while(n--){
	    int inp,p=-99999999,q=100,r=0,s=0;
        cin>>inp;
        char carr[inp];
        int ans[4][4]={0},x[4]={0,1,2,3},y[4],z[13],iarr[inp];
        z[12]=0;z[3]=1;z[6]=2;z[9]=3;
        for(int i=0;i<inp;i++){
            cin>>carr[i]>>iarr[i];
            switch(carr[i]){
            case 'A':   (ans[0][z[iarr[i]]])++;
                        break;
            case 'B':   (ans[1][z[iarr[i]]])++;
                        break;
            case 'C':   (ans[2][z[iarr[i]]])++;
                        break;
            case 'D':   (ans[3][z[iarr[i]]])++;
                        break;
            default:    break;
            }
        }do{ 
            int x1=100,y1=0;
            y[0]=ans[0][x[0]];y[1]=ans[1][x[1]];y[2]=ans[2][x[2]];y[3]=ans[3][x[3]];
            sort(y,y+4);
            for(int i=3;i>=0;i--){
                if(y[i]!=0)
                    y1+=(y[i]*x1);
                else
                    y1-=100;
                x1-=25;
            }if(y1<=0){
                if(y1>=p)
                    p=y1;
            }else{
                if(y1>r)
                    r=y1;
            }
        }while(next_permutation(x,x+4));
        if(r>0)
            s=r;
        else
            s=p;           
        cout<<s<<endl;
        res+=s;
	}
    cout<<res<<endl;
	return 0;
}
