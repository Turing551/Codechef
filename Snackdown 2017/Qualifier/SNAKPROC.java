import java.io.*;
import java.util.*;
import java.lang.*;

class Solution1{
	public static void main (String args[]) throws java.lang.Exception{
		Scanner scan = new Scanner(System.in);		                 
		int x=scan.nextInt();
		String str=new String();
		String arr[]=new String[x];
		for(int i=0;i<x;i++){
		    int y=scan.nextInt();
		        str=scan.next();
		    arr[i]= solve(str);

		}		
		for(int i=0;i<arr.length;i++){
		   System.out.println(arr[i]);
		}
	}
	
	public static String solve(String str){
	    int a=0;
	    for(int i=0;i<str.length();i++){
	            if(str.charAt(i) == '.'){
	                continue;
	            } else if(a == 0 && str.charAt(i) == 'H'){
	                a=1;
	                continue;
	            } else if(a == 1 && str.charAt(i) == 'T'){
	                a=0;
	                continue;
	            } else if(a == 1 && str.charAt(i) == 'H'){
	                return "Invalid";
	            } else if(a == 0 && str.charAt(i) == 'T'){
	                return "Invalid";
	            }
	    }
	    if(a==0){
	    	return "Valid";
	    } else{
	    	return "Invalid";
	    }	    
	}	
}
