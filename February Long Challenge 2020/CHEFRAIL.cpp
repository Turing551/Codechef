#include <bits/stdc++.h>
using namespace std;
long long int val=100001;
vector<long long int> vec1(val+1,0);
void solve(long long int lt){
	vector<long long int> arr(val+1,0);
	long long int a=1,b=1,x2=0,i,j,k,n,tmp;
	for(i=0;i<val+1;i++)
	arr[i]=i;
	for(j=2;j<=val;j++){
		if(arr[j]==j){
		for(k=j*j;k<=val;k+=j){
			if(arr[k]==k)
			arr[k]=j;
		 }
	   }
	}for(i=1;i<=lt;i++){
		a=1,b=1;
	    x2=0;tmp=i;
		while(tmp>0){
			if(a==arr[tmp]){
				x2++;
				if(tmp==1)
				break;		
			}else{
				if(x2%2==1)
				b=b*a;
				x2=1;
				a=arr[tmp];
				if(tmp==1)
				break;
			}
			tmp/=arr[tmp];		
		}
		vec1[i]=b;
	}
}

int main(){
	double tot;
	long long int x1,y1,x2,y2,x3,y3,n,i,j,k,tmp,val,res;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;res=0;
	    vector <long long int> va1(4,0),va2(4,0);
		scanf("%lld %lld",&tmp,&val);
		vector <long long int> va3(tmp,0),va4(val,0);
		for(j=0;j<tmp;j++){
			scanf("%lld",&va3[j]);
			if(va3[j]>0){
				x2++;
				if(va3[j]>x1)
				x1=va3[j];
			}else if(va3[j]<0){
				y2++;
				if((va3[j]*-1)>y1)
				y1=(va3[j]*-1);
			}else{
				res+=(tmp-1)*val;
			}
		}
		va1[0]=x1;va1[1]=y1;va2[0]=x1;va2[1]=y1;
		vector <long long int> vb1(x2,0),vb2(x1+1,0),vb3(y2,0),vb4(y1+1,0);
		for(j=0;j<tmp;j++){
			if(va3[j]>0){
				vb2[va3[j]]=1;
				vb1[x3]=va3[j];
				x3++;
			}if(va3[j]<0){
				vb4[(va3[j]*-1)]=1;
				vb3[y3]=va3[j]*-1;
				y3++;
			}
		}
		x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;
		for(j=0;j<val;j++){
			scanf("%lld",&va4[j]);
			if(va4[j]>0){
				x2++;
				if(va4[j]>x1)
				x1=va4[j];
			}else if(va4[j]<0){
				y2++;
				if((va4[j]*-1)>y1)
				y1=(va4[j]*-1);
			}else
			res+=(val-1)*tmp;
		}
		va1[2]=x1;
		va1[3]=y1;
		va2[2]=x1;
		va2[3]=y1;
		sort(va1.begin(),va1.end());
		solve(va1[3]);
		vector<long long int> vc1(x1+1,0),vc2(y1+1),vc3(x2,0),vc4(y2,0);
		for(j=0;j<val;j++){
			if(va4[j]>0){
				vc1[va4[j]]=1;
				vc3[x3]=va4[j];
				x3++;
			}else if(va4[j]<0){
				vc2[(va4[j]*-1)]=1;
				vc4[y3]=va4[j]*-1;
				y3++;
			}
		}for(j=0;j<vb3.size();j++){   
			for(k=vec1[vb3[j]];k<=va2[0];k+=vec1[vb3[j]]){
				if(vb2[k]==1){
					tot=sqrt(k*vb3[j]);
					if(tot==floor(tot)){
					    if(tot<=vc1.size()){
						if(vc1[tot]==1)
		 				res++;
		 			    }if(tot<=vc2.size()){
						if(vc2[tot]==1)
						res++;
					    }
					}
				}
			}	
	}for(j=0;j<vc4.size();j++){
			for(k=vec1[vc4[j]];k<=va2[2];k+=vec1[vc4[j]]){
				if(vc1[k]==1){
					tot=sqrt(k*vc4[j]);
					if(tot==floor(tot)){
						if(tot<=vb2.size()){
						if(vb2[tot]==1)
						res++;
					    }if(tot<=vb4.size()){
						if(vb4[tot]==1)
						res++;
					    }
					}
				}
			}
	}
		cout<<res<<endl;
	}
	return 0;
}
