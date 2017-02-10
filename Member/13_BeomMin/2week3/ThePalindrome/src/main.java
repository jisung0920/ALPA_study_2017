import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner t = new Scanner(System.in);
		String s = t.nextLine();
		
		find f = new find();
		
		System.out.println("return : " + f.find(s));
	}

}
