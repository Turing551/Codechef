import java.util.*;

class CHNUM{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        for(int i=0;i<a;i++){
            int x=0,y=0;
			int b=sc.nextInt();
            int[] arr=new int[b];
            for(int j=0;j<b;j++){
                int k=sc.nextInt();
                if(k>=0){ 
		x+=1;
		}
                else if(k<0){ 
		y+=1;
		}
            }
            if(x==0){ 
			x=y;    
			}
            else if(y==0){ 
			y=x; 
			}		
            System.out.println(x+" "+y);
        }        
    }
}
#
