package interestingparty;

public class partyMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		interestingParty party = new interestingParty();
		String first[] = {"a","b","a","d"};
		String second[] = {"b","c","s","a"};
		int i  = party.InterestingParty(first, second);
		System.out.println("return :"+i);
		}
	}


