import java.util.*;

class Solution{
	public static void main(String args[]){	
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=0;	
		while(a>b){	
			int n=sc.nextInt();
			String str[]=new String[n];	
			HashSet<Character> hs[]=new HashSet[n];
			for(int i=0;i<n;i++){	
				str[i]=sc.next();
				hs[i]=new HashSet<>();	
				for(char c : str[i].toCharArray()){
					if(hs[i].contains(c)==false){
						hs[i].add(c);
					} } }		
			int count=0;
			Character x[]={'a','e','i','o','u'};
			HashSet<Character> y=new HashSet<>(Arrays.asList(x));			
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					boolean k=true;					
					for(char c : y){
						if(hs[i].contains(c) == false && hs[j].contains(c) == false){
							k=false;
							break;
						} }					
					if(k==true){
						count ++;
					} } }		
			System.out.println(count);
			b++;
		} } }
