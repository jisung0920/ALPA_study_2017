package Cryptography;

import java.util.Arrays;

public class Cryptography {

	/*public long encrypt(int[] numbers){
		int N = numbers.length;
		int MAX = 0;
		int tmp;
		for(int i=0;i<N;i++){
			tmp = numbers[i]+1;
			for(int j=0;j<N;j++){
				if(i==j)
					continue;
				tmp*=numbers[j];
			}
			if(MAX<tmp)MAX=tmp;
		}
		return MAX;
	}*/
	
	public long encrypt(int[] numbers){
		Arrays.sort(numbers);
		int N = numbers.length;
		int MAX = numbers[0]+1;
		for(int i=1;i<N;i++)
			MAX*=numbers[i];
		return MAX;	
	}


}
