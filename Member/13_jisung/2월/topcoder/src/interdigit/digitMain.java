package interdigit;

public class digitMain {

	public static void main(String[] args) {


		interestingDigit digit = new interestingDigit();
		int b = 26;
		int n[] = digit.digits(b);
		for(int i=0;i<3;i++)
			if(n[i]>1)
				System.out.print(n[i]+"  ");
		
	}

}
