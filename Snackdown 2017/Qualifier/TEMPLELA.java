import java.io.*;
import java.util.*;

class Solution2{
    public static void main(String args[]) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(System.out);
        int a=Integer.parseInt(br.readLine());
        for(int j=0;j<a;j++){
            int b=Integer.parseInt(br.readLine());
            boolean k=true;
            if(b % 2 == 0){
                k=false;
                br.readLine();
            }
            else{
                StringTokenizer st=new StringTokenizer(br.readLine(), " ");
                int p=0;
                for(int i=0;i<b/2+1;i++){
                    int q=Integer.parseInt(st.nextToken());
                    if(q != p+1){
                        k=false;
                        break;
                    }
                    p=q;
                }
                for(int i=b/2+1;i<b;i++){
                    int q=Integer.parseInt(st.nextToken());
                    if(q!=p-1){
                        k=false;
                        break;
                    }
                    p=q;
                }
            }
            if (k) pw.println("yes");
            else pw.println("no");
        }
        pw.flush();
    }
}
