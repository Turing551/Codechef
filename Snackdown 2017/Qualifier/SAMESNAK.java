import java.io.*;
import java.util.*;
    
class Solution3{
    public static void main(String args[]) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int x=Integer.parseInt(br.readLine());
            for(int i=0;i<x;i++){
              int a[]=new int[4];
              int b[]=new int[4];
              String str1[]=br.readLine().split(" ");
              String str2[]=br.readLine().split(" ");
              for(int j=0;j<4;j++){
                a[j]=Integer.parseInt(str1[j]);
                b[j]=Integer.parseInt(str2[j]);
               }
                boolean k=solve(a,b);
                if(k==true){
                    System.out.println("yes");
                } 
				else{
                    System.out.println("no");
                     }
                  }    
              }

              public static boolean solve(int p[],int q[]){
              	  if((p[1]==q[1]) && (p[1]==p[3]) && (p[1]==q[3])){
                         int x2=Math.min(q[0],q[2]);
              	  	     int y2=Math.max(q[0],q[2]);
              	  	     int m=Math.min(p[0],p[2]);
              	  	     int n=Math.max(p[0],p[2]);
              	  	     if((x2>=m && x2<=n) || (m>=x2 && m<=y2)){
              	  	     	return true;
              	  	     }else{
              	  	     	return false;
              	  	     }
              	  }else if((p[0]==p[2]) && (p[0]==q[0]) && (p[0]==q[2])){
              	  	     int x1=Math.min(p[1],p[3]);
                         int x2=Math.min(q[1],q[3]);
              	  	     int y1=Math.max(p[1],p[3]);
              	  	     int y2=Math.max(q[1],q[3]);
              	  	     if((x1>=x2&&x1<=y2) || (x2>=x1&&x2<=y1)){
              	  	     	return true;
              	  	     }else{
              	  	     	return false;
              	  	     }
              	  }else{
                      if((p[0]==q[2]&&p[1]==q[3]) || (p[0]==q[0]&&p[1]==q[1]) || (p[2]==q[0]&&p[3]==q[1]) ||(p[2]==q[2]&&p[3]==q[3])){
                      	     return true;
                      }
              	  }
              	  return false;
              }
    }  
