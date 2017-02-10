package interestingparty;

public class interestingParty {
	
	public int InterestingParty(String[] first, String[] second){
		int inter=1;
		int numFriend = first.length;
		for(int i=0;i<numFriend;i++){
			int tmp=0;
			for(int j=i;j<numFriend;j++)
				if(first[i]==first[j] || first[i]==second[j] ||second[i]==second[j])
					tmp++;
			if(inter<tmp)
				inter = tmp;
		}
		return inter;
	}
}
