import java.util.Arrays;
import java.util.Scanner;

public class InterestingParty {
		Scanner s1 = new Scanner(System.in);
		public int bestInvitation(String[] first, String[] second) {
			String x;
			int invitation = 0;
			for (int i = 0; i < first.length; i++) {
				x = first[i];
				for (int j = 0; j < second.length; j++) {
					if (x.equals(second[j])) {
						invitation++;
					}
				}
			}
			return invitation;
		}
		
		public void insertInteresting(String[] first, String[] second) {
			int leng = first.length;
			System.out.println("ģ���� ù��° ��̸� �Է����ּ���");
			for (int i = 0; i < leng; i++) {
				String interesting_1 = s1.next();
				first[i] = interesting_1;

			}
			System.out.println("ģ���� �ι�° ��̸� �Է����ּ���");
			for (int i = 0; i < leng; i++) {
				String interesting_2 = s1.next();
				second[i] = interesting_2;

			}
			
			for (int i = 0; i < leng; i++) {
				if(first[i].equals(second[i])) {
					System.out.println("�� ����� ��̴� �ΰ��� �޶���մϴ�.");
					System.exit(0);
				}
			}
			System.out.print("first = ");
			for (int i = 0; i< leng; i++) {
				System.out.print("\"" + first[i] + "\""+ " ");
			}
			System.out.println();
			System.out.print("second = ");
			for (int i = 0; i< leng; i++) {
				System.out.print("\"" + second[i] + "\"" + " ");
			}
			System.out.println();
			
		}
}
