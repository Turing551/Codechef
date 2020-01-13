import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
class Solution{
    private static BufferedInputStream in = new BufferedInputStream(System.in);
    private static final int x=100007,y=1000000007;
    private static long arr1[]=new long[x];
    private static long arr2[]=new long[x];
    private static long arr3[]=new long[x];
    private static long arr4[]=new long[x];
	
	private static Stats enhance(int len,long[] arr){
        Stats st=new Stats();
        Map<Long,Long> cnt=new HashMap<>();
        long tot=0;
        for(long k : arr){
            tot=tot+k;
            Long occr=cnt.get(k);
            if(occr==null){
                cnt.put(k,1L);
            }else{
                cnt.put(k,occr+1);
            }
        }
        long org=tot/(len+1);
        boolean p=(org % 2 == 0);
        long q=org/2;
        Long r=cnt.get(org);
        if(r==null || r<2) return null;
        if(r==2){
            cnt.remove(org);
        }else{
            cnt.put(org,r-2);
        }
        if (cnt.isEmpty()) return st;
        st.check=true;
        for(Long j : cnt.keySet()){
            if(j.equals(q) && p){
                Long icnt=cnt.get(j);
                if(icnt % 2 == 1) return null;
                st.jcnt=icnt/2;
            }else if(cnt.get(j)==1){
                if(!st.dp.contains(org-j)){
                    Long kcnt=cnt.get(org-j);
                    if(kcnt==null || kcnt!=1){
                        return null;
                    }
                    st.dp.add(j);
                }
            }else{
                if(!st.coup.containsKey(org-j)){
                    Long icnt=cnt.get(j);
                    Long kcnt=cnt.get(org-j);
                    if(kcnt==null || !kcnt.equals(icnt)){
                        return null;
                    }
                    st.coup.put(j,icnt);
                }
            }
        }
        return st;
    }
	private static long calculate(int len,long[] arr){
        Stats st=enhance(len,arr);
        if(st==null) return 0;
        if(!st.check) return 1;
        int x1=0,x2=0,y1=st.dp.size(),y2=(int) st.jcnt;
        long k1=arr1[y1];
        x1=x1+y1;
        long k2=(k1*perm(x1+y2,y2))%y;
        x1=x1+y2;
        HashMap<Long,Long> coup=st.coup;
        for(Long j : coup.keySet()){
            int mul = (int) coup.get(j).longValue();
            k2=(k2*perm(x1+mul,mul))%y;
            x1=x1+mul;
            x2=x2+mul;
        }
        return (k2*arr2[y1+x2])%y;
    }
    private static void estimate(){
        arr1[0]=1;arr1[1]=1;arr2[0]=1;arr2[1]=2;arr3[0]=1;arr3[1]=1;arr4[0]=1;arr4[1]=1;
        for(int i=2;i<x;i++){
            arr1[i]=(i*arr1[i-1]) % y;
            arr2[i]=(2*arr2[i-1]) % y;
            arr3[i]=((y-(y/i)) * arr3[y%i]) % y;
            arr4[i]=(arr3[i]*arr4[i-1]) % y;
        }
    }
    private static long perm(int a,int b){
        if(a==0 || b==0) return 1;
        return ((arr1[a] * arr4[a-b]) % y * arr4[b]) % y;
    }
    static class Stats{
        Set<Long> dp=new HashSet<>();
        long jcnt=0;
        HashMap<Long,Long> coup=new HashMap<>();
        boolean check=false;
    }
    private static String read(){
        StringBuilder sb=new StringBuilder();
        try{
            int inp=in.read();
            while(inp==32)
                inp=in.read();
            while(inp!=10 && inp!=32 && inp!=-1){
                sb.append((char) inp);
                inp=in.read();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        return sb.toString();
    }
    static class Print{
        private final BufferedWriter bw;
        public Print(){
            bw=new BufferedWriter(new OutputStreamWriter(System.out));
        }
        public void print(String str) throws IOException{
            bw.append(str);
        }
        public void printLine(String str) throws IOException{
            print(str);
            bw.append("\n");
        }
        public void close() throws IOException{
            bw.close();
        }
    }
	public static void main(String[] args) throws IOException{
        Print print=new Print();
        estimate();
        int n=Integer.parseInt(read());
        IntStream.range(0,n).forEach(test -> {
            int len=Integer.parseInt(read());
            long arr[]=new long[len * 2];
            for(int i=0;i<2*len;i++) {
                arr[i]=Long.parseLong(read());
            }
            try{
                print.printLine("" + calculate(len,arr));
            } catch(IOException ignored){
            }
        });
        print.close();
    }
}
