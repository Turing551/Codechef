import java.io.*;
import java.util.*;

class Solution{
	static void solve(int n,List<Integer> k){
    int x1=0,y1=0;
    int z1=k.size()-1;
    while(z1-x1>0){
      y1=(x1+z1)/2;
      if(n<k.get(y1)){
        z1=y1;
      }else{
        x1=y1+1;
      }
    } 
    if(k.size()>x1 && k.get(x1)<n) 
		x1++;
    k.add(x1,n);
  }
  public static void main(String args[]) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    String str1=br.readLine();
    int cnt=Integer.parseInt(str1);   
    for(int i=0;i<cnt;i++){
      str1=br.readLine();
      String str2[]=str1.split(" ");
      int p=Integer.parseInt(str2[0]);
      int q=Integer.parseInt(str2[1]);   
      str1=br.readLine();
      str2=str1.split(" ");
      int arr1[]=new int[p];
      for(int j=0;j<p;j++) 
		  arr1[j]=Integer.parseInt(str2[j]); 
      int answer=0;
      for(int x=0;x<p;x++){
        List<Integer> list=new ArrayList<>(p);
        int arr2[]=new int[2001];
        for(int y=x;y<p;y++){
          solve(arr1[y],list);
          arr2[arr1[y]]++; 
          int a=1+y-x;
          int b=(int) Math.ceil((double)q / (double)a);
          int c=(q-1)/b;
          int d=list.get(c);
          int temp=arr2[d];
          if(arr2[temp]>0 && temp<2001){
            answer++;
          } } }
      System.out.println(answer);
    }  
    br.close();
  } 
 }
