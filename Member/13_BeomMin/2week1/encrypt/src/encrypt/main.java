package encrypt;

import java.util.Arrays;
import java.util.Scanner;

public class main {
		static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int len;
		encrypt e = new encrypt();
		
		System.out.println("��� ���ڸ� �Է��Ͻǰǰ���?");
		len = s.nextInt();
		int[] numbers = new int[len];
		System.out.println("���ڸ� �Է����ּ���");
		for(int i = 0; i < len; i++) {
			numbers[i] = s.nextInt();
		}
		
		System.out.println("numbers = " + Arrays.toString(numbers));
		System.out.println("result = " + e.encrypt(numbers));
	}

}
