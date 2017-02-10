package Palindrome;

public class ThePalindrome {
	
	public static String reverseString(String s) {
	    return ( new StringBuffer(s) ).reverse().toString();
	  }
	
	public int find(String s){
		int count=s.length();
		String a = reverseString(s);
		String b = s;
		for(int i=0;!a.equals(b) && i<s.length();i++,count++){
			b = s+ reverseString(s.substring(0,i+1));
			a = reverseString(b);
		}
		return count;
	}
}
