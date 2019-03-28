import java.util.*;

class Solution{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for (int i=0;i<T;i++) {
			int M=sc.nextInt();
			int N=sc.nextInt();
			int Rx=sc.nextInt();
			int Ry=sc.nextInt();
			sc.nextInt();
			String str=sc.next();
			System.out.println("Case " + (i+1) + ": " + solve(M,N,Rx,Ry,str));
		}
		sc.close();
	}
	static String solve(int M,int N,int Rx,int Ry,String str) {
		int x=0;
		int y=0;
		for(char ch : str.toCharArray()) {
			if(ch == 'U') {
				y++;
			}else if(ch == 'D') {
				y--;
			}else if(ch == 'R') {
				x++;
			}else if(ch == 'L') {
				x--;
			}
		}

		if(x==Rx && y==Ry) {
			return "REACHED";
		}else if(x<0 || y<0 || x>M || y>N){
			return "DANGER";
		}else{
			return "SOMEWHERE";
		}
	}
}
