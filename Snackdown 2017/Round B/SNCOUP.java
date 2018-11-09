import java.util.*;

class Solution3{   
    static int solve(int x,String y[]){
        int z=0;
        boolean k=false;
        for(int i=0;i<x;i++){
            if(!k){
                if(y[1].charAt(i)=='*'&&y[0].charAt(i)=='*'){
                    k=true;
                    z++;
                    break;
                } }
        }
        int a=0; 
        for(int i=0;i<x;i++){
            if(y[1].charAt(i)=='.'&&y[0].charAt(i)=='.')
                continue;
            if(y[1].charAt(i)=='*'&&y[0].charAt(i)=='*'){
                if(a!=0)
                    z++;a=3;
            } else if(y[1].charAt(i)=='.'&&y[0].charAt(i)=='*' ){
                if(a==1||a==3)
                    z++;
                else if(!k&&a==2)
                    z++;a=1;
            } else{
                if(a==2||a==3)
                    z++;
                else if(!k&&a==1)
                    z++;a=2;                
            }
        } return z;
    }
        static int bar(int x,String y[]){
        boolean k=y[1].indexOf('*')>=0&&y[0].indexOf('*')>=0;     
        int z=k?1:0;
        boolean arr[]=new boolean[]{false,false};
        for(int i=0;i<x;i++){
            for(int j=0;j<2;j++){
                if(y[j].charAt(i)=='*'){
                    if(arr[j]){
                        z++;
                        arr[0]=false;
                        arr[1]=false;
                        break;
                    }
                } }
            for(int j=0;j<2;j++)
                if(y[j].charAt(i)=='*')
                    arr[j]=true;
        } return z;
    }
    static void result(){
        int n=in.nextInt(); 
        for(int i=0;i<n;i++){
            int x=in.nextInt();
            String y[]=new String[2];
            y[0]=in.next();
            y[1]=in.next();
            System.out.println(bar(x,y));
        }        
    }

    static Scanner in=new Scanner(System.in);
    public static void main(String args[]){      
        result();
    }
}
