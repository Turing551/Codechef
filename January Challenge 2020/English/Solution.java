import java.io.*;
import java.util.*;
 
class Ds1<V,K>{
    private List<Entry> lst;
    private Map<V, Integer> val;
    private Comparator<K> pt;
    public int size(){
        return lst.size();
    }
    public boolean isEmpty(){
        return lst.isEmpty();
    }
	private int rnode(int idx){
        return idx == 0 ? 0 : (idx - 1) >> 1;
    }
    private int tmpl(int idx){
        return (idx << 1) + 1;
    }
    private int tmpr(int idx){
        return (idx << 1) + 2;
    }
	public Ds1(){
        lst=new ArrayList<>();
        val=new HashMap<>();
    }
    public Ds1(Comparator<K> pt){
        this();
        this.pt = pt;
    }
    public void add(V p, K q){
        lst.add(new Entry(p,q));
        val.put(p, lst.size() - 1);
        sol1(p,q);
    }
	private void enhance(int i){
        int x1 = tmpl(i);
        int y1 = tmpr(i);
        int mval = i;
        if(x1 < size() && diff(lst.get(x1).getKey(), lst.get(i).getKey()) < 0){
            mval = x1;
        }
        if(y1 < size() && diff(lst.get(y1).getKey(), lst.get(mval).getKey()) < 0){
            mval = y1;
        }
        if(mval == i){
            return;
        }
        Entry strt = lst.get(i);
        lst.set(i, lst.get(mval));
        val.put(lst.get(mval).getValue(), i);
        lst.set(mval, strt);
        val.put(strt.getValue(), mval);
        enhance(mval);
    }
    public void sol1(V p, K nq){
        int i = val.get(p);
        lst.get(i).setKey(nq);
        while(i > 0 && diff(lst.get(rnode(i)).getKey(), lst.get(i).getKey()) > 0){
            Entry strt = lst.get(i);
            lst.set(i, lst.get(rnode(i)));
            val.put(lst.get(rnode(i)).getValue(), i);
            lst.set(rnode(i), strt);
            val.put(strt.getValue(), rnode(i));
            i = rnode(i);
        }
    }
    public V calMinVal(){
        V min = lst.get(0).getValue();
        lst.set(0, lst.get(lst.size() - 1));
        val.put(lst.get(0).getValue(), 0);
        lst.remove(lst.size() - 1);
        val.remove(min);
        enhance(0);
        return min;
    }
    @SuppressWarnings("unchecked")
	private int diff(K k1, K k2){
        return pt == null
            ? ((Comparable<K>) k1).compareTo(k2)
            : pt.compare(k1, k2);
    }
    class Entry {
        private V p;
        private K q;
        public Entry(V v, K k) {
            p = v;
            q = k;
        }
        public V getValue() {
            return p;
        }
        public K getKey() {
            return q;
        }
        public K setKey(K k) {
            K old = q;
            q = k;
            return old;
        }
    }
}
class Ds2 {
    Map<Integer, Ds2> cnode;
    int a,b,c;
    Ds2 rnode;
    public Ds2() {
        cnode = new HashMap<>();
    }
    public void add(String str){
        Ds2 prt = this;
        prt.a++;
        for(int i = 0; i < str.length(); i++){
            char ch1 = str.charAt(i),ch2 = str.charAt(str.length() - 1 - i);
            int c = (ch1 - 'a') * 26 + (ch2 - 'a');
            if(!prt.cnode.containsKey(c)) prt.cnode.put(c, new Ds2());
            prt.cnode.get(c).rnode = prt;
            prt.cnode.get(c).b = prt.b + 1;
            prt = prt.cnode.get(c);
            prt.a++;
            prt.c = c;
        }
    }
}
class Solution{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out); 
    public static void main(String[] args) throws IOException {
        Solution s = new Solution();
        s.calculate();
        s.close();
    }
    void close() throws IOException {
        pw.flush();
        pw.close();
        br.close();
    }
    void calculate() throws IOException{
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            int inp = Integer.parseInt(br.readLine());
            Ds2 temp = new Ds2();
            for(int j=0;j<inp;j++){
                temp.add(br.readLine());
            }
            long res=0;
            Ds1<Ds2, Integer> lst = new Ds1<>();
            dfs(lst,temp);
            while(!lst.isEmpty()) {
                Ds2 tmp = lst.calMinVal();
                if(tmp.a < 2) continue;
                Integer x=null;
                Integer y=null;
                int b=tmp.b;
                for(int l : tmp.cnode.keySet()){
                    if(x == null) x=l;
                    else if(y == null) y=l;
                    else break;
                }
                tmp.cnode.remove(x);
                tmp.cnode.remove(y);
                tmp.a -= 2;
                if(tmp.a >= 2){
                    lst.add(tmp, -tmp.b);
                }
                while(tmp.rnode != null){
                    tmp.rnode.a -= 2;
                    tmp.rnode.cnode.remove(tmp.c);
                    tmp = tmp.rnode;
                }
                res += (long) b * b;
            }
            pw.println(res);
        }
    }
    void dfs(Ds1<Ds2, Integer> lst,Ds2 node){
        if(node.a >= 2){
            lst.add(node, -node.b);
        }
        for(Ds2 t : node.cnode.values()){
            dfs(lst,t);
        }
    }
}
