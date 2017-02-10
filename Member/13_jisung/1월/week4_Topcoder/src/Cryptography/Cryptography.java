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
		Arrays.sort(numbers); // array 정렬 
		int MAX = numbers[0]+1; //배열의 최소값에 1을 더한다.
		for(int i=1;i<numbers.length;i++) //배열의 요소 곱한다.
			MAX*=numbers[i];
		return MAX;	
	}


}
