import java.util.Scanner;

public class main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int Invitation;
		System.out.println("ģ���� ����ֽ��ϱ�?");
		int num = s.nextInt();
		String first[] = new String[num];
		String second[] = new String[num];
		
		InterestingParty I = new InterestingParty();
		I.insertInteresting(first, second);
		Invitation = I.bestInvitation(first, second);
		System.out.println("return : " + Invitation);
	}
}
