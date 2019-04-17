import java.util.Scanner;

class Solution{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		String str1=sc.next();
		int k=str1.length();
		int res=0;
		for(int i=0;i<k;i++){
		for(int j=0;j<=k;j++){
			if(i<j){
				String str2=str1.substring(i,j);
				for(int x=j;x<k;x++){
				for(int y=j;y<=k;y++){
					if(x<y){
						if(i!=x || j!=y){
							String str3=str1.substring(x,y);
							String str4=str2+str3;
							int a=str4.length()-1;
							int b=0;
							boolean temp=true;
							while(a>b){
								if(str4.charAt(b) != str4.charAt(a)){
									temp=false;
									break;
										}
									b++;
									a--;
									}
									if(temp==true){
										res++;
                                    }
	                } } } } } } }
		System.out.println(res);
	}
}
