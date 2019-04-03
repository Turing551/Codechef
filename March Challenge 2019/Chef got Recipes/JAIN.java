import java.io.*;

class Solution{ 
  public static void main(String args[]) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    String str=br.readLine();
    int cnt=Integer.parseInt(str);  
    for(int i=0;i<cnt;i++){
      int arr[][]=new int[6][32];
      str=br.readLine();
      int n=Integer.parseInt(str);    
      for(int j=0;j<n;j++){
        str=br.readLine();     
        int k=0;
        if(str.indexOf("u")!=-1) k+=1;
        if(str.indexOf("o")!=-1) k+=2;
        if(str.indexOf("i")!=-1) k+=4;
        if(str.indexOf("e")!=-1) k+=8;
        if(str.indexOf("a")!=-1) k+=16;      
        int c=Integer.bitCount(k);
        arr[c][k]++;
      }
      long answer=0;
      for(int x=1;x<5;x++){
        for(int y=x;y<=5;y++){
          long a=0;
          for(int p=1;p<32;p++){
            for(int q=1;q<32;q++){
              if((p|q)==31){
                  a=a+(arr[x][p]*arr[y][q]);
              } } }      
          if(x==y){
            long b=a/2;
            answer=answer+b;
          }else{
            answer=answer+a;
          } } }
      int temp=arr[5][31];
      answer=answer+(((temp-1)*temp)/2);   
      System.out.println(answer);
    }  
    br.close();  
  }
}
