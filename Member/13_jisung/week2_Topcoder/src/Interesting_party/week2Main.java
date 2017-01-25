package Interesting_party;

public class week2Main {

	public static void main(String[] args) {
		/*
		String first[] = {"fishing","gardening","swimming","fishing"};
		String second[] = {"hunting","fishing","fishing","biting"};
		int i=party.bestInvitation(first, second);
		System.out.println("return : "+i);
		*/
		
		InterestingParty party = new InterestingParty();
		String first[] = {"variety","diversity","loquacity","courtesy"};
		String second[] = {"talking","speaking","discussion","meeting"};
		int i=party.bestInvitation(first, second);
		System.out.println("return : "+i);
		
	}

}
