import java.util.*;

class Solution1{ 
        static void result(){
        int n=in.nextInt();    
        for(int i=0;i<n;i++){
            String s=in.next();
            solve(s);
        }
    }  
    static void solve(String str){
        int x=0,s=0;
        Stack<Character> st=new Stack<>();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='s'){
                if(st.isEmpty() || st.peek() !='x'){
                    st.add('s');
                    s++;
                } else{
                    st.pop();
                    st.add('m');
                }
            } else{
                x++;
                if(st.isEmpty() || st.peek()!='s') 
                    st.add('x');
                else{
                    st.pop();
                    s--;
                    st.add('m'); 
                } 
            }
        }
        if(x<s)
            System.out.println("snakes");           
        else if(x>s)
            System.out.println("mongooses");
        else
            System.out.println("tie");
    }
    static Scanner in=new Scanner(System.in);
    public static void main(String args[]){      
        result();
    }
}
