package interdigit;


public class interestingDigit {

	public int[] digits(int base){
		
		int[] arr = {--base,-1,-1};
		for(int i=1;i<3;i++)
			if(base==(int)Math.pow((int)Math.sqrt((double)base),2)){
				base = (int)Math.sqrt(base);
				arr[i]=base;
				}
		return arr;
	}
	
		
}
