package KiwiJuice;

public class JuiceMain {

	public static void main(String[] args) {
		
		KiwiJuiceEasy  Juice = new KiwiJuiceEasy();
		
		int capacities[] = {14,35,86,58,25,62};
		int bottles[] = {6,34,27,38,9,60};
		int fromId[] = {1,2,4,5,3,3,1,0};
		int toId[] = {0,1,2,4,2,5,3,1};
		
		Juice.thePouring(capacities, bottles, fromId, toId);
		
		for(int i=0;i<bottles.length;i++){
			System.out.println("bottle["+i+"] :"+bottles[i]);
			
		}


	}

}
