import java.util.*;
import java.util.AbstractMap.SimpleEntry;

class key {
    int arr[][];
    int k;
        static int result(Scanner sc,int arr[][]){
        int y=0; 
        for(int q=0;q<arr.length;q++)
            for(int r=0;r<arr[q].length;r++){
                arr[q][r]=sc.nextInt();
                if(arr[q][r]>y)
                    y=arr[q][r];
            }return y;
    }
    int solve(List<Map.Entry<Integer, Integer>> b){
        List<Map.Entry<Integer, Integer>> p=new ArrayList<>();
        for (Map.Entry<Integer, Integer> e: b) {
            int q=e.getKey();
            int r=e.getValue();
            cal(p,q-1,r-1);
            cal(p,q-1,r);
            cal(p,q-1,r+1);
            cal(p,q,r-1);
            cal(p,q,r+1);
            cal(p,q+1,r-1);
            cal(p,q+1,r);
            cal(p,q+1,r+1);
        }
        if(p.isEmpty())
            return 0;
        else{
            return 1+solve(p);
        }
    }    
        key(int arr[][],int y){
        List<Map.Entry<Integer, Integer>> maxEntry=new ArrayList<>();
        for(int q=0;q<arr.length;q++)
            for(int r=0;r<arr[q].length;r++){
                if ( arr[q][r]==y)
                    maxEntry.add(new SimpleEntry<Integer,Integer>(q,r));
            }
        this.arr=arr;
        k=y;
        System.out.println(solve(maxEntry));
    }
        void cal(List<Map.Entry<Integer, Integer>> p,int q,int r){
        if(q>=arr.length || r>=arr[0].length || q<0 || r<0)
            return;
        if(arr[q][r]>=k)
            return;
        arr[q][r]=k;
        p.add(new SimpleEntry<Integer,Integer>(q,r));
    }

    static Scanner in=new Scanner(System.in);
    public static void main(String[] args){      
        int n=in.nextInt(); 
        for (int q=0; q<n; q++) {
            int x=in.nextInt(); 
            int y=in.nextInt();
            int arr[][]=new int[x][y];
            int z=result(in,arr);
            new key(arr,z);
        }
    }
}
