package encrypt;

import java.util.Arrays;

public class encrypt {
	public long encrypt(int[] numbers) {
		int min = numbers[0];
		int pivot = 0;
		long result = 1;
		for (int i = 0; i < numbers.length; i++) {
			if (numbers[i] < min) {
				min = numbers[i];
				pivot = i;
			}
		}
		numbers[pivot]++;
		for(int i = 0; i < numbers.length; i++) {
			result *= numbers[i];
		}
		return result;
	}
}
