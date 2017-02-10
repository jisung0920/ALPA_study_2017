
public class find {
	public int find(String s) {
		int l = s.length();
		String reverse = (new StringBuffer(s)).reverse().toString();
		String ss = new String(s);
		while(!s.equals(reverse)) {
			if(l>0) {
				s = s + s.charAt(l-2);
				l--;
				reverse = new StringBuffer(s).reverse().toString();
			}
			else {
				ss = ss + ss.charAt(0);
				reverse = new StringBuffer(ss).reverse().toString();
			}
		}
		return reverse.length();
	}
}

