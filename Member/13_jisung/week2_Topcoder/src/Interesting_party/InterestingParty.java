package Interesting_party;

public class InterestingParty {

	public int bestInvitation(String[] first, String[] second){
		int NumPeople = first.length;
		int common=0;
		for(int i=0;i<NumPeople;i++){
			int temp=0;
			for(int j=i;j<NumPeople;j++)
				if(first[i]==first[j] || first[i]==second[j])
					temp++;
			
			if(common<temp)
				common=temp;
		}
		return common;
	}
}