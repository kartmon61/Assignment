package assignment3;

public class Tester {

	public static void main(String[] args) {
		
		//making Application polymorphism
		Application [] arr = {new WebApp("Reddit","www.reddit.com","Bluehost"),
				new iOSApp("Clash Royale",12.04,"SUPER CELL","iTunes Store"),
				new WindowsApp("Skype","skyper","1920x1080")};
		
		//input Release_date
		arr[0].setRelease_date(23,07,2005);
		arr[1].setRelease_date(4, 01, 2016);
		arr[2].setRelease_date(29, 8, 2003);
		
		//print
		for(int i=0;i<arr.length;i++) {
			
		System.out.println(arr[i]);
		
		}
	}
}
