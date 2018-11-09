import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]){
        java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        try {
            Integer n=Integer.valueOf(br.readLine());
            ArrayList<String[]> arr=new ArrayList<>(n);
            for(int i=0;i<n;i++){
                String str[]=br.readLine().split(" ");
                arr.add(str);
            }
            for(String[] str : arr){
                System.out.println(solve2(str));
            }
        } catch(IOException e){
            e.printStackTrace();
        } }
    static int solve1(int i){
        i-=((i >>> 1) & 0x55555555);
        i=((i >>> 2) & 0x33333333)+(i & 0x33333333);
        i=((i >>> 4)+i) & 0x0f0f0f0f;
        i+=(i >>> 8);
        i+=(i >>> 16);
        return i & 0x3f;
    }
    private static long solve2(String str[]){
        long res=0;
        int x=Integer.valueOf(str[0]);
        int y=Integer.valueOf(str[1]);
        int z=Integer.valueOf(str[2]);
        int x1=solve1(x);
        int y1=solve1(y);
        for(int j=0;j<=z;j++){
            int k=z-j;
            if(solve1(k)==y1 && solve1(j)==x1){
                res++;
            } }
        return res;
    } }
