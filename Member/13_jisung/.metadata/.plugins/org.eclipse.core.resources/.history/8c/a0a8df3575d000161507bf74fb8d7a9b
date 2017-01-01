package week1;

public class KiwiJuiceEasy {
	
	public	int[] thePouring(int[] capacities,int[] bottles, int[] fromId, int[] toId){
		int i=0;
		while(fromId.length!=i){
			
			int FromB = fromId[i];
			int ToB =toId[i];
			int mJuice = bottles[FromB];
			int cap = bottles[ToB] + mJuice;
			
			if(capacities[ToB]<=cap){
				bottles[ToB]=capacities[ToB];
				bottles[FromB]=cap-capacities[ToB];
			}
			else{
				bottles[ToB]=cap;
				bottles[FromB]=0;
			}
			
			i++;
			}
	return bottles;
	}

}
